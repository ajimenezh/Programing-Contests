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

const int mod = 100711433;
#define MAXN 100010
#define MAXM 18

long long up[100010];
long long down[100010];
long long pw[100010];
long long inv[100010];
int n;
long long r;
vector<int> e[100010];
int dp[MAXN][MAXM];
int parent[MAXN];
int depth[MAXN];
bool vis[MAXN];
long long sum[100010];
long long add[100010];

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

void init(int _n){
    n = _n;
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
}

int lca(int p, int q){
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

void dfs(int p, int q, int v){
    vis[p] = 1;
    parent[p] = q;
    depth[p] = v;
    for (vector<int>::iterator it = e[p].begin(); it!=e[p].end(); it++) if (!vis[*it])
        dfs(*it,p,v+1);
    return;
}

pair<long long, long long> dfs2(int p, int q) {
    pair<long long, long long> pp;

    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) {
        pair<long long, long long> tmp = dfs2(e[p][i], p);
        pp.first += tmp.first;
        pp.second += tmp.second;
    }

    //cout<<p+1<<" "<<pp.first<<" "<<pp.second<<endl;

    sum[p] += (pp.first)%mod;
    sum[p] += (pp.second)%mod;
    sum[p] = (sum[p] + up[p])%mod;
    sum[p] = (sum[p] + down[p])%mod;
    sum[p] = (sum[p] - add[p])%mod;
    sum[p] = (sum[p] + mod)%mod;

    //cout<<sum[p]<<endl;

    pp.first = ((pp.first*r)%mod + (up[p]*r)%mod)%mod;
    pp.first = (pp.first + mod)%mod;

    pp.second = ((pp.second*inv[1])%mod + (down[p]*inv[1])%mod)%mod;
    pp.second = (pp.second + mod)%mod;

    return pp;
}

void dfs3(int p, int q, long long x){
    sum[p] += x;
    sum[p] = (sum[p]%mod + mod)%mod;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) {
        dfs3(e[p][i], p, sum[p]);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>r;
    pw[0] = 1;
    for (int i=1; i<=n; i++) pw[i] = (pw[i-1]*r)%mod;
    for (int i=0; i<=1; i++) inv[i] = fpow(pw[i], mod-2);
    for (int i=0; i<n; i++) parent[i] = -1;
    for (int i=0; i<n; i++) vis[i] = false;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(0, 0, 1);
    init(n);

    int u,q;
    cin>>u>>q;
    for (int i=0; i<u; i++) {
        int a,b;
        long long x;
        scanf("%d%d%lld",&a,&b,&x);
        x = (x*r)%mod;
        a--; b--;
        if (a==b) {
            sum[a] = (sum[a] + x)%mod;
        }
        else {
            int c = lca(a,b);
            if (a!=c) up[a] += x;
            if (parent[c]!=c) {
                if (a!=c) up[parent[c]] -= ((x*pw[depth[a]-depth[c]])%mod)*r%mod;
                if (b!=c) down[parent[c]] -= ((x*pw[depth[a]-depth[c]])%mod)*inv[1]%mod;
            }
            if (b!=c) down[b] += (x*pw[depth[a]-depth[c]+depth[b]-depth[c]])%mod;
            if (a!=c && b!=c) add[c] += (x*pw[depth[a]-depth[c]])%mod;
            up[a] %= mod;
            up[b] %= mod;
            down[a] %= mod;
            down[b] %= mod;
            add[c] %= mod;
            up[c] %= mod;
            down[c] %= mod;
        }
    }
    for (int i=0; i<n; i++) {
        up[i] = (up[i]%mod + mod)%mod;
        down[i] = (down[i]%mod + mod)%mod;
    }
    //for (int i=0; i<n; i++) cout<<i+1<<" "<<up[i]<<" "<<down[i]<<endl;

    dfs2(0,-1);
    dfs3(0,-1,0);

    //for (int i=0; i<n; i++) cout<<i+1<<" "<<sum[i]<<endl;

    for (int i=0; i<q; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        int c = lca(a,b);

        long long tot = 0;
        if (a==b) tot = sum[a];
        else if (c==a) {
            if (c==0) tot = sum[b];
            else tot = sum[b] - sum[parent[c]];
        }
        else if (c==b) {
            if (c==0) tot = sum[a];
            else tot = sum[a] - sum[parent[c]];
        }
        else {
            tot = sum[a] + sum[b] - sum[c];
            if (c!=parent[c]) tot -= sum[parent[c]];
        }

        tot = (tot%mod + mod)%mod;
        tot = (tot*inv[1])%mod;

        cout<<tot<<"\n";
    }

    return 0;

}
