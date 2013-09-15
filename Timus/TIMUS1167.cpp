#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,k;
int c[550];
int sumW[550];
int sumB[550];
int dp[510][510];

int solve(int i, int t) {
    if (i==n) return 0;
    if (t==0 && i!=n) return 100000000;
    if (dp[i][t]>=0) return dp[i][t];

    int tmp = 100000000;
    for (int j=i; j<n; j++) {
        int bad = 0;
        if (i>0) bad = (sumW[j]-sumW[i-1])*(sumB[j]-sumB[i-1]);
        else bad = (sumW[j]-0)*(sumB[j]-0);
        tmp = min(tmp, bad + solve(j+1,t-1));
    }
    dp[i][t] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>c[i];
    sumW[0] = (c[0]==0);
    sumB[0] = (c[0]==1);
    for (int i=1; i<n; i++) {
        sumW[i] = sumW[i-1] + (c[i]==0);
        sumB[i] = sumB[i-1] + (c[i]==1);
    }
    for (int i=0; i<n; i++) for (int j=0; j<=k; j++) dp[i][j] = -1;
    cout<<solve(0,k);

    return 0;

}
