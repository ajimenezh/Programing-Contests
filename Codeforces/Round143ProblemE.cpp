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
vector<int> e[100010];
vector<int> f[100010];
vector<int> ba[100010];
vector<pair<int,int> > g[100010];
bool vis[100010];
int q[100010];
int cnt[100010];
int q2[100010];
int type[100010];
int parent[100010];
int depth[100010];

void dfs(int u, int v) {
    rep(it,e[u]) if (*it!=v) {
        int p = *it;
        f[u].push_back(p);
        ba[p].push_back(u);
        dfs(p,u);
    }
}

void bfs_backwards(int p) {
    int in = 0 ,fn = 0;
    q2[in++] = p;
    while (in!=fn) {
        int u = q2[in++];
        if (e[u].size()>2) {
            g[u].push_back(make_pair(p,2));
            g[p].push_back(make_pair(u,2));
            break;
        }
        else {
            if (u!=p) {
                type[u] = 2;
            }
        }
        rep(it,ba[u]) {
            q2[fn++] = *it;
        }
    }
}

void bfs_forward(int p) {
    int in = 0, fn = 0;
    q[fn++] = p;
    while (in!=fn) {
        int u = q[in++];
        vis[u];
        cnt[u]++;
        if (cnt[u]>1) bfs_backwards(u);
        rep(it,f[u]) if (!vis[*it]) {
            q[fn++] = *it;
        }
    }
}

void dfs2(int u, int v) {
    rep(it,e[u]) if (*it!=v && type[*it]==1) {
        int p = *it;
        g[u].push_back(make_pair(p,1));
        g[p].push_back(make_pair(u,1));
        dfs(p,u);
    }
}

void count_dfs(int u, int v,int val) {
    cnt[u] = cnt[v] + val;
    parent[u] = v;
    depth[u] = depth[v] + 1;
    rep(it,g[u]) if ((*it).first!=v) {
        count_dfs((*it).first,u,(*it).second-1);
    }
}

#define MAXN 100010
#define MAXM 18

int dp[MAXN][18];


int lca(int p, int q)
{

    if (depth[p]<depth[q]) return lca(q,p);

    int l;
    for (l=1; 1<<l <= depth[p]; l++);
    l--;

    for (int i=l; i>=0; i--)
    {
        if (depth[p] - (1<<i) >= depth[q])
            p = dp[p][i];
    }

    if (p==q) return p;

    for (int i=l; i>=0; i--)
    {
        if (dp[p][i]!=-1 && dp[p][i]!=dp[q][i])
        {
            p = dp[p][i];
            q = dp[q][i];
        }
    }
    return parent[p];
}

#define mod 1000000007

long long fastpow(long long a, int b) {
    if (b==0) return 1LL;
    if (b==1) return a;
    long long tmp = fastpow(a,b/2)%mod;
    if (b%2==0) return (tmp*tmp)%mod;
    return (a*((tmp*tmp)%mod)%mod)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    if (m==n) {
        int k;
        cin>>k;
        for (int i=0; i<k; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            printf("%d\n",2);
        }
        return 0;
    }

    int p = -1;
    for (int i=0; i<n; i++) {
        if (e[i].size()==1) {
            p = i;
            break;
        }
        else if (e[i].size()>2 && p==-1) {
            p = i;
        }
    }

    dfs(p,p);
    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) cnt[i] = 0;
    for (int i=0; i<n; i++) type[i] = 1;
    bfs_forward(p);

    dfs2(p,p);
    for (int i=0; i<n; i++) cnt[i] = 0;
    count_dfs(p,p,0);

    for (int i=0; i<MAXN; i++) for (int j=0; j<MAXM; j++) dp[i][j] = -1;

    for (int i=0; i<n; i++) dp[i][0] = parent[i];

    for (int j=1; 1<<j < n; j++)
    {
        for (int i=0; i<n; i++)
        {
            if (dp[i][j-1]!=-1)
                dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }

    int k;
    cin>>k;
    for (int i=0; i<k; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        int p = lca(a,b);
        printf("%I64d\n",fastpow(2LL,cnt[a]+cnt[b]-2*cnt[p]));
    }

    return 0;

}
