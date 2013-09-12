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

#define INF 1LL<<40

int n,m;
int a[1505][1505];
long long dp[1505][1505];
long long sum[1505][1505];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            scanf("%d",&a[i][j]);
        }
    }

    for (int i=0; i<n; i++) for (int j=0; j<=m; j++) dp[i][j] = -1;

    for (int i=0; i<n; i++) {
        for (int j=0; j<=m; j++) {
            j==0 ? sum[i][j] = 0 : sum[i][j] = sum[i][j-1] + a[i][j-1];
        }
    }

    long long res = -INF;

    for (int i=n-1; i>=0; i--) {
        if (i==n-1) {
            for (int j=0; j<=m; j++) {
                dp[i][j] = sum[i][j];
            }
            dp[i][0] = -INF;
        }
        else {
            if ((i+1)%2==1) {
                dp[i][0] = -INF;
                for (int j=m; j>0; j--) {
                    dp[i][j] = dp[i-1][j-1]
                    dp[i][j] = max(dp[i][j-1], dp[i+1][j-1] + sum[i][j] );
                    //cout<<i<<" "<<j<<" "<<sum[i][j]<<" "<<dp[i-1][j-1]<<endl;
                }
            }
            else {
                dp[i][m] = -INF;
                for (int j=m-2; j>=1; j--) {
                    dp[i][j] = max(dp[i][j+1], dp[i+1][j+1] + sum[i][j] );
                }
            }
        }
    }

    for (int i=0; i<n; i++) {for (int j=0; j<=m; j++) cout<<dp[i][j]<<" "; cout<<endl;}

    for (int i=0; i<=m; i++) res = max(res, dp[0][i]);

    cout<<res<<endl;

    return 0;

}
