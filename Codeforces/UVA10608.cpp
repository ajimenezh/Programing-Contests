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

#define MAXM 500000+5
#define MAXN 30000+5

int cnt;
vector<int> ed[MAXN];
vector<int> edrev[MAXN];
int w[MAXN];
bool vis[MAXN];
int comp[MAXN];

struct edge{
    int from, to, id, c;
    edge(int a, int b, int d, int i) {
        from = a; to = b; c = d; id = i;
    }
    edge(int i=0, int _id = -1) {
        from = -1; to = i; id = _id; c = -1;
    }
};

edge e[MAXM];

void dfs(int p) {
    vis[p] = 1;
    for (int i=0; i<ed[p].size(); i++) if (!vis[ed[p][i]]) dfs(ed[p][i]);
    w[--cnt] = p;
}
void dfsrev(int p, int k) {
    vis[p] = 1;
    for (int i=0; i<edrev[p].size(); i++) if (!vis[edrev[p][i]]) dfsrev(edrev[p][i],k);
    comp[p] = k;
}

int scc(int n, int m) {
    cnt = n;
    for (int i=0; i<n; i++) ed[i].clear();
    for (int i=0; i<m; i++) ed[e[i].from].push_back(e[i].to);
    for (int i=0; i<m; i++) edrev[e[i].to].push_back(e[i].from);
    for (int i=0; i<n; i++) comp[i] = 0;
    for (int i=0; i<n; i++) if (!vis[i]) dfs(i);
    for (int i=0; i<n; i++) vis[i] = 0;
    cnt = 0;
    for (int i=0; i<n; i++) if (!vis[w[i]]) dfsrev(w[i],++cnt);
    for (int i=0; i<n; i++) cout<<comp[i]<<" "; cout<<endl;
    return cnt+1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    t = 1;

    while (t--) {
        int n,m;
        cin>>n>>m;
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            e[i] = edge(a,b,0,i);
        }

        int mm = scc(n,m);
        cout<<mm<<endl;
    }


    return 0;

}
