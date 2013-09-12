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

#define INF 1000000000

int n,m,r;
int c[61][61][61];
int dist[61][61][61];
int dp[65][61][61];
priority_queue<pair<int,int> > q;

int mask(int a, int b, int c) {
    return a*4225 + b*65 + c;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>r;
    for (int i=0; i<m; i++) {
        for (int j=0; j<n; j++) for (int k=0; k<n; k++) scanf("%d",&c[i][j][k]);
    }

    for (int i=0; i<m; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) dist[i][j][k] = c[i][j][k];

    for (int ii=0; ii<m; ii++) {
        for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[ii][i][j] = min(dist[ii][i][j],dist[ii][i][k] + dist[ii][k][j]);
    }

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) dp[0][i][j] = INF;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<m; k++) dp[0][i][j] = min(dp[0][i][j],dist[k][i][j]);
    for (int k=1; k<=n; k++) {
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            dp[k][i][j] = INF;
            for (int kk=0; kk<n; kk++) {
                dp[k][i][j] = min(dp[k][i][j], dp[k-1][i][kk] + dp[0][kk][j]);
                dp[k][i][j] = min(dp[k][i][j], dp[0][i][kk] + dp[k-1][kk][j]);
            }
        }
    }


    for (int i=0; i<r; i++) {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        printf("%d\n",dp[min(k,n)][a-1][b-1]);
    }

    return 0;

}
