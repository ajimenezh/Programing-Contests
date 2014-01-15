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

int n,m;
long long mod;
pair<int,int> local[301];
bool vis[301][301];
long long dp[301][301];
int cnt[310];
int sum[310];
long long coef[301][301];

long long solve(int i, int k) {
    if (i==0) return 1;
    if (cnt[i-1]>k+1) return 0;
    if (dp[i][k]>=0) return dp[i][k];

    long long tmp = 0;

    for (int j=cnt[i-1]; j<=k+1; j++) {
        tmp = (tmp + solve(i-1,k+1-j)*coef[i+k-sum[i-1]][i-cnt[i-1]]%mod)%mod;
    }

    dp[i][k] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        scanf("%d%d%I64d",&n,&m,&mod);
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--;
            b--;
            local[i] = make_pair(a,b);
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                vis[i][j] = 0;
            }
        }
        sort(local,local+m);
        for (int i=0; i<m; i++) {
            int s = local[i].first;
            int t = local[i].second;
            t--;
            cnt[t]++;
            while (t<n && vis[t][s]) t++;
            if (t==n) {
                printf("NO\n");
                return 0;
            }
            for (int j=s; j<n; j++) {
                vis[t][j] = 1;
            }
        }
        for (int i=0; i<=n; i++) {
            for (int j=0; j<=n; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i=0; i<=n; i++) {
            coef[i][0] = 1;
            coef[i][i] = 1;
            for (int j=1; j<i; j++) coef[i][j] = (coef[i-1][j] + coef[i-1][j-1])%mod;
        }
        for (int i=0; i<n; i++) {
            if (i==0) sum[i] = cnt[i];
            else sum[i] = cnt[i] + sum[i-1];
        }
        long long ans = solve(n,0);
        printf("YES %I64d\n",ans);
    }

    return 0;

}
