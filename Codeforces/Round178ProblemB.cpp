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

int dp[201][201][101];
int n;
int w[101];
int t[101];
int p;

int solve(int c1, int c2, int k) {
    //cout<<c1<<" "<<c2<<" "<<k<<endl;
    if (c2>2*n) return 0;
    if (c2>c1 && k==n) return 0;
    if (k==n && c2<=c1) {
        p = min(p,c1);
        return 1;
    }
    if (dp[c1][c2][k]>=0) return dp[c1][c2][k];

    dp[c1][c2][k] = max(solve(c1,c2+w[k],k+1),solve(c1+t[k],c2,k+1));

    return dp[c1][c2][k];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>t[i]>>w[i];

    for (int i=0; i<=2*n; i++) for (int j=0; j<=2*n; j++) for (int k=0; k<n; k++) dp[i][j][k] = -1;

    p = 100000;

    solve(0,0,0);

    cout<<p<<endl;

    return 0;

}
