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

const int M = 111000;
const int m = 100000;

int dp[101][200000];
int n,k;
int a[101], b[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) cin>>b[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<M; j++) {
            dp[i][j] = -1;
        }
    }

    dp[0][m] = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<M; j++) if (dp[i][j]!=-1) {
            //dp[i+1][j+a[i]-k*b[i]]
            if (dp[i+1][j]==-1) dp[i+1][j] = dp[i][j];
            else dp[i+1][j] = max(dp[i][j], dp[i+1][j]);

            if (dp[i+1][j+a[i]-k*b[i]]==-1) dp[i+1][j+a[i]-k*b[i]] = dp[i][j] + a[i];
            else dp[i+1][j+a[i]-k*b[i]] = max(dp[i][j] + a[i], dp[i+1][j+a[i]-k*b[i]]);
        }
    }

    if (dp[n][m]==0) cout<<-1;
    else cout<<dp[n][m]<<endl;

    return 0;

}
