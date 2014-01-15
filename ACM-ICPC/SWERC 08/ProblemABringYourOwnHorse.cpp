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

pair<int,pair<int,int> > v[100010];
int par[3100];
int rk[3100];
bool vis[100010];
vector<int> e[3100];
vector<int> c[3100];
int n,m;

int get(int a) {
    if (par[a]==a) return a;
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

int dfs(int a, int b, int pre) {
    if (a==b) return 0;
    for (int i=0; i<e[a].size(); i++) {
        if (pre==e[a][i]) continue;
        int tmp = dfs(e[a][i],b,a);
        if (tmp>=0) {
            tmp = max(tmp, c[a][i]);
            return tmp;
        }
    }
    return -1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int cas=1; cas<=tt; cas++) {
        cin>>n>>m;
        for (int i=0; i<m; i++) {
            int a,b,l;
            scanf("%d%d%d",&a,&b,&l);
            a--; b--;
            vis[i] = 0;
            v[i] = make_pair(l, make_pair(a,b));
            e[a].clear();
            e[b].clear();
            c[a].clear();
            c[b].clear();
            par[a] = a;
            par[b] = b;
            rk[a] = 0;
            rk[b] = 0;
        }
        sort(v,v+m);
        for (int i=0; i<m; i++) {
            if (connect(v[i].second.first,v[i].second.second)) vis[i] = 1;
        }
        for (int i=0; i<m; i++) {
            if (vis[i]) {
                e[v[i].second.second].push_back(v[i].second.first);
                e[v[i].second.first].push_back(v[i].second.second);
                c[v[i].second.second].push_back(v[i].first);
                c[v[i].second.first].push_back(v[i].first);
            }
        }
        int q;
        cin>>q;
        printf("Case %d\n",cas);
        for (int i=0; i<q; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            printf("%d\n",dfs(a,b,-1));
        }
        printf("\n");
    }

    return 0;

}
