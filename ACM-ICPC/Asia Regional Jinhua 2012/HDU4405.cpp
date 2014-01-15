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

double dp[100010];
int e[100010];
int n,m;

double solve(int x) {
    if (x>=n) return 0.0;
    if (dp[x]>-0.5) return dp[x];

    double res = 0;
    if (e[x]!=x) res = solve(e[x]);
    else {
        for (int i=1; i<=6; i++) {
            res += 1.0/6.0*(1.0 + solve(x+i));
        }
    }
    dp[x] = res;
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&m) && n) {
        for (int i=0; i<n; i++) e[i] = i;
        for (int i=0; i<n; i++) dp[i] = -1.0;
        for (int i=0; i<m; i++) {
            int u,v;
            scanf("%d%d",&u,&v);
            e[u] = max(e[u],v);
        }
        double ans = solve(0);
        printf("%.4lf\n",ans);
    }

    return 0;

}
