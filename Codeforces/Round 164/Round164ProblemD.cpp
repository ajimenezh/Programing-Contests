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

#define mod 1000000009

long long dp[2][32][32][32][2];
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    dp[0][0][0][0][1] = 1;

    for (int i=1; i<=n; i++) {
        for (int j1=0; j1<=m; j1++) for (int j2=0; j2<=m; j2++) for (int j3=0; j3<=m; j3++) for (int k=0; k<2; k++) {
            long long t = dp[1-i%2][j1][j2][j3][k];
            if (t==0) continue;
            dp[1-i%2][j1][j2][j3][k] = 0;

            t %= mod;

            int j4;

            if (k) j4 = 1;
            else j4 = m;

            dp[i%2][min(j1+1,m)][min(j2+1,m)][min(j2+1,m)][k] += t;
            dp[i%2][min(j1+1,m)][min(j2+1,m)][min(j2+1,m)][k] %= mod;

            dp[i%2][min(j2+1,m)][min(j3+1,m)][j4][j1<m] += t;
            dp[i%2][min(j2+1,m)][min(j3+1,m)][j4][j1<m]%=mod;
            dp[i%2][min(j1+1,m)][min(j3+1,m)][j4][j2<m] += t;
            dp[i%2][min(j1+1,m)][min(j3+1,m)][j4][j2<m]%=mod;
            dp[i%2][min(j1+1,m)][min(j2+1,m)][j4][j3<m] += t;
            dp[i%2][min(j1+1,m)][min(j2+1,m)][j4][j3<m]%=mod;
        }
    }

    long long ans = 0;
    for (int j1=0; j1<=m; j1++) for (int j2=0; j2<=m; j2++) for (int j3=0; j3<=m; j3++) for (int k=0; k<2; k++) {
        if (j1<m || j2<m || j3<m || k) {
            long long t = dp[n%2][j1][j2][j3][k];
            t %= mod;
            ans = (ans + t)%mod;
        }
    }

    cout<<ans<<endl;

    return 0;

}
