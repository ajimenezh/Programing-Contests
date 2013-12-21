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
set<int> e[500010];
int par[500010];
int rk[500010];
int deg[500010];
vector<int> d[500010];
int r[500010], l[500010];

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

bool connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (rk[a]>rk[b]) {
        rk[b]++;
        par[a] = b;
    }
    else {
        rk[a]++;
        par[b] = a;
    }
    return true;
}

void remove(int x) {
    int tmp = l[x];
    l[r[x]] = l[x];
    r[tmp] = r[x];
}

int q[1000010];
int in, fn;
vector<vector<int> > v;
bool vis[500010];

void bfs(int x) {
    in = 0; fn = 0;
    q[fn++] = x;
    remove(x);
    vis[x] = 1;
    v.push_back(vector<int>(0,0));
    while (in<fn) {
        x = q[in++];
        v[v.size()-1].push_back(x);
        for (int y=r[0]; y<=n; y = r[y]) {
            if (e[x].find(y)==e[x].end() && connect(x,y)) {
                q[fn++] = y;
                remove(y);
                vis[y] = 1;
            }
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].insert(b); deg[a]++;
        e[b].insert(a); deg[b]++;
    }
    for (int i=0; i<=n; i++) par[i] = i;
    for (int i=0; i<=n; i++) r[i] = i+1;
    for (int i=0; i<=n; i++) l[i+1] = i;

    for (int i=1; i<=n; i++) {
        d[deg[i]].push_back(i);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<d[i].size(); j++) {
            int x = d[i][j];
            if (!vis[x]) bfs(x);
        }
    }

    //for (int i=0; i<n; i++) cout<<par[i]<<" "; cout<<endl;
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++) {
        printf("%d ",v[i].size());
        for (int j=0; j<v[i].size(); j++) printf("%d ",v[i][j]);
        printf("\n");
    }

    return 0;

}
