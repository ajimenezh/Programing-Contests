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

vector<int> colors;
int parent[100050];
vector<int> e[100010];
int n,m;
int root;
int tot[100010];
int dp[100010][18];
pair<int,pair<int,int> > all[100010];
int sum[100010];
int depth[100010];
int index[100010];
int cnt;

void dfs(int p, int q) {
    parent[p] = q;
    if (q!=-1) depth[p] = depth[q] + 1;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) {
        dfs(e[p][i], p);
        tot[p] += tot[e[p][i]];
    }
    tot[p]++;
    index[p] = ++cnt;
}

void dfs2(int p, int q) {
    parent[p] = q;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) {
        dfs2(e[p][i], p);
        sum[p] += sum[e[p][i]];
    }
    tot[p] -= sum[p];
}

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
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>root;
    root--;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(root, -1);
    for (int i=0; i<n; i++) for (int j=0; j<18; j++) dp[i][j] = -1;
    for (int i=0; i<n; i++) dp[i][0] = parent[i];
    for (int i=1; i<18; i++) {
        for (int j=0; j<n; j++) {
            if (dp[i][j-1]!=-1)
                dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    for (int i=0; i<n; i++) {
        int k;
        scanf("%d",&k);
        all[i] = make_pair(k,make_pair(index[i],i));
    }
    sort(all, all+n);
    for (int i=1; i<n; i++) if (all[i].first==all[i-1].first) {
        int p = lca(all[i].second.second, all[i-1].second.second);
        sum[p]++;
    }
    dfs2(root, -1);
    for (int i=0; i<m; i++) {
        int p;
        scanf("%d",&p);
        p--;
        printf("%d\n", tot[p]);
    }

    return 0;

}
