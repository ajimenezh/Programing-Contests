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

int vis[110][110];
pair<int,int> q[10100];
int in,fn;
int n,k;
vector<int> e[110];
vector<int> c[110];

void dfs(int p, int t, int cc,int m) {
    if (vis[p][t]!=-1 && vis[p][t]>=cc) return;
    vis[p][t] = cc;

    for (int i=0; i<e[p].size(); i++) {
        if (c[p][i]>cc) {
            if (c[p][i]<=m && t>0) {
                dfs(e[p][i], t-1, m-c[p][i],m);
            }
        }
        else {
            if (t>0 && c[p][i]<=m) dfs(e[p][i], t-1, m-c[p][i],m);
            if (cc>=c[p][i]) dfs(e[p][i], t, cc-c[p][i],m);
        }
    }
    return;
}

bool good(int p, int x) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<k; j++) {
            vis[i][j] = -1;
        }
    }

    dfs(p,k-1,x,x);

    for (int i=0; i<n; i++) {
        bool done = 0;
        for (int j=0; j<k; j++) if (vis[i][j]!=-1) {
            done = 1;
            break;
        }
        if (!done) return false;
    }
    return true;
}

bool check(int x) {
    for (int i=0; i<n; i++) if (!good(i,x)) return 0;
    return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        int m;
        scanf("%d%d%d",&n,&k,&m);
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) c[i].clear();
        for (int i=0; i<m; i++) {
            int x,y,z;
            scanf("%d%d%d",&x,&y,&z);
            e[x].push_back(y);
            c[x].push_back(z);
            e[y].push_back(x);
            c[y].push_back(z);
        }

        int lo = 1;
        int hi = 1000000000;
        while (lo<hi) {
            int mi = (lo+hi)/2; cout<<lo<<" "<<hi<<endl;
            if (check(mi)) hi = mi;
            else lo = mi+1;
        }
        cout<<lo<<endl;
    }

    return 0;

}
