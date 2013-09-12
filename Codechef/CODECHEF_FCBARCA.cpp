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

#define mod 1000000007LL

int n,k;
long long dp[1001][11][2];

long long solve(int s, int f, bool w) {
    if (s==1) return 1-w;
    if (dp[s][f][w]>=0) return dp[s][f][w];

    if (w) {
        dp[s][f][w] = solve(s-1,f,0)*(f)%mod;
    }
    else {
        dp[s][f][w] = (solve(s-1,f,0)*(f-1)%mod + solve(s-1,f,1))%mod;
    }

    dp[s][f][w] %= mod;

    return dp[s][f][w];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=2; i<=1000; i++) for (int j=1; j<=10; j++) dp[i][j][0] = -1;
    for (int i=2; i<=1000; i++) for (int j=1; j<=10; j++) dp[i][j][1] = -1;

    for (int i=2; i<=1000; i++) for (int j=1; j<=10; j++) solve(i,j,1);

    int tt;
    cin>>tt;

    for (int t=0; t<tt; t++) {
        cin>>n>>k;

        printf("%I64d\n",dp[n][k][1]);
    }


    return 0;

}
