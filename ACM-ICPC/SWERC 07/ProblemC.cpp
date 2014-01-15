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

int c;
int n;
int x[100010], y[100010], w[100010];
int sum[100010], dist[100010];
int d[100010];
int dp[100010][110];

int solve(int i, int last) {
    if (i==n-1) {
        int tmp = d[i] + d[i-last] + dist[i] - dist[i-last];
        return tmp;
    }
    if (dp[i][last]>=0) return dp[i][last];

    int tmp = d[i] + d[i-last] + dist[i] - dist[i-last] + solve(i+1,0);

    if (sum[i+2] - sum[i-last]<=c) tmp = min(tmp, solve(i+1,last+1));

    dp[i][last] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int cas;
    cin>>cas;
    while (cas--) {
        scanf("%d",&c);
        scanf("%d",&n);
        for (int i=0; i<n; i++) {
            scanf("%d%d%d",x+i,y+i,w+i);
            d[i] = x[i] + y[i];
        }
        for (int i=1; i<=n; i++) {
            if (i!=n) dist[i] = abs(x[i]-x[i-1]) + abs(y[i]-y[i-1]) + dist[i-1];
            sum[i] = w[i-1] + sum[i-1];
        }
        for (int i=0; i<n; i++) for (int j=0; j<=c; j++) dp[i][j] = -1;
        int ans = solve(0,0);
        printf("%d\n",ans);
        if (cas!=0) printf("\n");
     }

    return 0;

}
