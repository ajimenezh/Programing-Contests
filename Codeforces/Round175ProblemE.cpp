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

#define mod 1000000007

int n,k;
long long dp[1001][1001][2][2];

long long solve(int i, int t, int f1, int f2) {
    if (t<0) return 0;
    if (i==n) {
        if (f2==0 && t==0) return 1;
        return 0;
    }
    if (dp[i][t][f1][f2]>0) return dp[i][t][f1][f2];

    dp[i][t][f1][f2] = (solve(i+1,t,f2,0) + solve(i+1,t-1,f2,1))%mod;
    if (f1==0) {
        dp[i][t][f1][f2] = (dp[i][t][f1][f2] + solve(i+1,t-1,f2,0))%mod;
    }

    cout<<i<<" "<<t<<" "<<f1<<" "<<f2<<" "<<dp[i][t][f1][f2]<<endl;

    return dp[i][t][f1][f2];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) for (int j=0; j<=k; j++) for (int p=0; p<2; p++) for (int r = 0; r<2; r++) dp[i][j][p][r] = -1;
    cout<<solve(0,k,1,0);

    return 0;

}
