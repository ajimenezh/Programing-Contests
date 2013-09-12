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

int n;
vector<int> e[301];
int depth[301];
int par[301];
int p[301][9];
int v[301];
vector<int> sol;

void dfs(int u, int v) {
    par[u] = v;
    depth[u] = depth[v] + 1;
    rep(it,e[u]) if (*it!=v)
        dfs(*it,u);
    return;
}
int lca(int u, int v) {
    if (depth[u]<depth[v]) return lca(v,u);
    for (int i=9; i>=0; i--) {
        if (depth[p[u][i]]<depth[v]);
        else {
            u = p[u][i];
        }
    }
    if (u==v) return u;

    for (int i=9; i>=0; i--) {
        if (p[u][i]!=p[v][i]) {
            u = p[u][i];
            v = p[v][i];
        }
    }
    return par[u];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    dfs(0,0);
    for (int i=0; i<n; i++) p[i][0] = par[i];
    for (int i=1; i<10; i++) {
        for (int j=0; j<n; j++) {
            p[i][j] = p[p[i][j-1]][j-1];
        }
    }
    int k=0;
    for (int i=1; i<n; i++) if (e[i].size()==1) k++;
    for (int i=0; i<k; i++) scanf("%d",v+i);
    v[k++] = 0;
    int now = 0;
    for (int i=0; i<k; i++) {
        int t = lca(now,v[i]);
        int u = now;
        while (u!=t) {sol.push_back(u); u = par[u];}
        vector<int> tmp;
        u = v[i];
        while (u!=t) {tmp.push_back(u); u = par[u];}
        reverse(tmp.begin(),tmp.end());
        for (int j=0; j<tmp.size(); j++) sol.push_back(tmp[j]);
    }
    for (int i=0; i<sol.size(); i++) cout<<sol[i]+1<<" "; cout<<endl;

    return 0;

}
