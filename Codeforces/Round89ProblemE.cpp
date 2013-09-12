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
vector<int> edges[100010];
int vis[100010];
int low[100010];
int hi[100010];
int d[100010];
int t;
int parent[100010];
int des[100010];
int fin;
bool bridge[100010];

void dfs(int p, int pre) {
    vis[p] = 1;

    d[p] = t++;

    low[p] = d[p];

    rep(it,edges[p]) {
        int u = *it;

        if (pre==u) continue;

        if (!vis[u]) {

            parent[u] = p;

            dfs(u,p);
        }
        low[p] = min(low[p],low[u]);
    }

    if (pre!=-1 && low[p]>=d[p]) {
        bridge[p] = 1;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    for (int i=0; i<n; i++) vis[i] = 0;
    for (int i=0; i<n; i++) bridge[i] = 0;
    for (int i=0; i<n; i++) des[i] = 0;
    t = 0;

    dfs(0,-1);

    for (int i=0; i<n; i++) {
        if (bridge[i]) {
            cout<<0<<endl;
            return 0;
        }
    }



    for (int i=0; i<n; i++) rep(it,edges[i]) {
        int u = i;
        int v = *it;
        if (u<v) continue;
        if (d[u]>d[v]) {
            int tmp = u;
            u = v;
            v = tmp;
        }
        if (parent[v]==u) {
            printf("%d %d\n",v+1,u+1);
        }
        else printf("%d %d\n",u+1,v+1);
    }


    return 0;

}
