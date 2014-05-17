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

int n;
int par[1010];
int rk[1010];
bool vis[1010];
int cnt[1010];
int tmp[1010];
vector<pair<int,int> > v;
pair<int,int> all[1010];
vector<int> nodes;
bool good[1010][1010];
vector<int> e[1010];

int _find(int p) {
    if (p==par[p]) return p;
    par[p] = _find(par[p]);
    return par[p];
}

void _union(int p, int q) {
    p = _find(p);
    q = _find(q);
    if (p==q) return;
    if (rk[p]>rk[q]) {
        par[p] = q;
        rk[q]++;
    }
    else {
        par[q] = p;
        rk[p]++;
    }
}

void dfs(int p, int pre) {
    vis[p] = 1;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=pre && good[p][e[p][i]] && !vis[e[p][i]]) dfs(e[p][i], p);
}

bool check(int p, int pp) {
    for (int i=0; i<n; i++) vis[i] = 0;
    dfs(p,-1);
    for (int i=0; i<n; i++) if (par[i]==pp && !vis[i]) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<n; i++) rk[i] = 0;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d", &a,&b);
        a--; b--;
        all[i] = make_pair(a,b);
        _union(a,b);
        e[a].push_back(b);
        e[b].push_back(a);
        good[a][b] = 1;
        good[b][a] = 1;
    }
    for (int i=0; i<n; i++) par[i] = _find(i);
    for (int i=0; i<n; i++) cnt[par[i]]++;
    for (int i=0; i<n-1; i++) {
        int a = all[i].first;
        int b = all[i].second;
        good[a][b] = 0;
        good[b][a] = 0;
        if (check(a, par[a])) v.push_back(all[i]);
        else {
            good[a][b] = 1;
            good[b][a] = 1;
        }
    }
    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) if (vis[par[i]]==0) {
        nodes.push_back(i);
        vis[par[i]] = 1;
    }
    cout<<nodes.size()-1<<endl;

    for (int i=1; i<nodes.size();i++) {
        cout<<v[i-1].first+1<<" "<<v[i-1].second+1<<" "<<nodes[0]+1<<" "<<nodes[i]+1<<"\n";
    }

    return 0;

}
