#include <iostream>
#include <sstream>
#include <vector>
#include <string>
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

long long dp[3001][1501][2];
int n,k;
long long p[3010];

long long solve(int i, int t, int f) {
    if (i==n) return 0;
    if (t==0 && f==0) return 0;
    if (dp[i][t][f]!=-1) return dp[i][t][f];

    long long tmp = 0;
    if (f==1) {
        tmp = max(solve(i+1, t, 1), p[i]+solve(i+1,t,0));
    }
    else {
        tmp = max(solve(i+1, t, 0), -p[i]+solve(i+1,t-1,1));
    }


    dp[i][t][f] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%I64d",p+i);
    for (int i=0; i<n; i++) for (int j=0; j<=k; j++) dp[i][j][0] = -1;
    for (int i=0; i<n; i++) for (int j=0; j<=k; j++) dp[i][j][1] = -1;

    long long res = solve(0,k,0);

    cout<<res<<endl;

    return 0;

}
