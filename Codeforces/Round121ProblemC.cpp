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

int n,m;
int k;
vector<int> e[100010];
int p[100010];
bool vis[100010];
int dp[100010][18];
int rank[100010];
int val[100010];
pair<int,int> edges[100010];

void dfs(int u, int v) {
    vis[u] = 1;
    p[u] = v;
    rank[u] = 1;
    if (v!=-1) rank[u] += rank[v];

    int tmp = 0;

    rep(it,e[u]) {
        int q = *it;
        if (vis[q]) continue;
        dfs(q,u);
        tmp += val[q];
    }
    val[u] += tmp;
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    m = n-1;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
        edges[i] = make_pair(a,b);
    }
    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) p[i] = -1;

    for (int i=0; i<n; i++) val[i] = 0;
    dfs(0,-1);

    for (int i=0; i<n; i++) for (int j=0; j<18; j++) dp[i][j] = -1;
    for (int i=0; i<n; i++) dp[i][0] = p[i];
    for (int j=1; j<18; j++) {
        for (int i=0; i<n; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    cin>>k;
    for (int j=0; j<k; j++) {
        int u,v;
        scanf("%d%d",&u,&v);
        u--; v--;
        val[u]++;
        val[v]++;
        if (rank[u]<rank[v]) {
            int tmp = v;
            v = u;
            u = tmp;
        }

        for (int i=17; i>=0; i--) {
            if (rank[u]-(1<<i)>=rank[v]) {
                u = dp[u][i];
            }
        }

        //cout<<u<<" "<<v<<endl;
        if (u!=v) {
            for (int i=17; i>=0; i--) {
                if (dp[u][i]!=-1 && dp[u][i]!=dp[v][i]) {
                    u = dp[u][i];
                    v = dp[v][i];
                }
            }
            u = p[u];
        }

        //cout<<u<<endl;

        val[u]-=2;
    }

    for (int i=0; i<n; i++) vis[i] = 0;
    //for (int i=0; i<n; i++) cerr<<val[i]<<" "; cerr<<endl;
    dfs(0,-1);
    //for (int i=0; i<n; i++) cout<<val[i]<<" "; cout<<endl;
    for (int i=0; i<m; i++) {
        if (edges[i].first==p[edges[i].second])
            printf("%d ",val[edges[i].second]);
        else
            printf("%d ",val[edges[i].first]);
    }

    return 0;

}
