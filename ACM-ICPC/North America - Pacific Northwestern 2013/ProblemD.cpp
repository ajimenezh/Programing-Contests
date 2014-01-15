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

int n,k;
set<int> cur;
vector<int> e[10010], c[10010];
int cnt[10010];
long long tot[10010];
long long dp[10010][25];
long long res;
long long next[25];

void dfs(int p, int last) {
    cnt[p] = 1;
    tot[p] = 0;
    for (int i=0; i<e[p].size(); i++) {
        int q = e[p][i];
        if (q!=last) {
            dfs(q,p);
            cnt[p] += cnt[q];
            tot[p] += tot[q] + c[p][i];
            for (int t=0; t<=k; t++) next[t] = 0;

            for (int j=0; j<=k; j++) {
                for (int t=j; t<=k; t++) {
                    next[t] = max(next[t], dp[p][t-j] + dp[q][j]);
                }
            }
            for (int t=cnt[q]; t<=k; t++) {
                next[t] = max(next[t], dp[p][t-cnt[q]] + tot[q] + c[p][i]);
            }
            for (int t=0; t<=k; t++) dp[p][t] = max(dp[p][t], next[t]);
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt) {
        cin>>n>>k;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) c[i].clear();
        long long sum = 0;
        for (int i=0; i<n-1; i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[x].push_back(y);
            c[x].push_back(z);
            e[y].push_back(x);
            c[y].push_back(z);
            sum += z;
        }

        long long ans = 1000000000000LL;

        for (int i=0; i<min(n-1,k+1); i++) {
            for (int j=0; j<n; j++) cnt[j] = 0;
            for (int j=0; j<n; j++) tot[j] = 0;
            for (int j=0; j<n; j++) {
                for (int t=0; t<=k; t++) dp[j][t] = 0;
            }
            dfs(i,-1);
            ans = min(ans, 2*(sum - dp[i][k]));
        }

        cout<<ans<<endl;
    }

    return 0;

}
