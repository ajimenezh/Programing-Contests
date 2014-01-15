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

vector<int> e[110];
int a[110];
int b[110];
int n;
bool border[110];
int sum = 0;

const int maxnode=100000+5;
const int maxedge=100000+5;
const int INF=1000000000;

int N,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],q[maxnode],work[maxnode];

void init(int _n, int _src, int _dest) {
    N = _n;
    src = _src;
    dest = _dest;
    for (int i=0; i<N; i++) head[i] = -1;
    nedge = 0;
}

void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v; capa[nedge]=c1; flow[nedge] = 0; next[nedge]=head[u]; head[u] = (nedge++);
    point[nedge] = u; capa[nedge]=c2; flow[nedge] = 0; next[nedge]=head[v]; head[v] = (nedge++);
}

bool bfs() {
    for (int i=0; i<N; i++) dist[i] = -1;
    dist[src] = 0;
    int fn = 0;
    q[fn++]=src;
    int in=0;
    while (fn!=in)
    {
        for (int k=q[in], i=head[k]; i>=0; i=next[i])
        {
            if (flow[i]<capa[i] && dist[point[i]]<0)
            {
                dist[point[i]] = dist[k]+1;
                q[fn++] = point[i];
            }
        }
        in++;
    }
    return dist[dest]>=0;
}

int dfs(int x, int f) {
    if (!f) return 0;
    if (x == dest) return f;

    int res = 0;
    for (int i = work[x]; i>=0; i = next[i])
    {
        int v = point[i],temp;

        if (flow[i] < capa[i] && dist[v] == (dist[x] + 1))
        {
            temp=dfs(v,min(f,capa[i]-flow[i]));
            if (temp>0)
            {
                flow[i] += temp;
                flow[i^1] -= temp;
                res += temp;
                f -= temp;
                if (f==0) break;
            }
        }
    }
    return res;
}

int dinic() {
    int f = 0;
    while (bfs())
    {
        for (int i = 0; i<N; i++) work[i] = head[i];

        f += dfs(src,INF);
    }
    return f;
}

bool check(int x) {
    int m = n;
    init(2*m+2,2*m,2*m+1);
    for (int i=0; i<n; i++) if (a[i]>0) {
        add_edge(2*m,i,a[i],0);
        if (border[i]) add_edge(i+m,2*m+1,x,0);
        else add_edge(i+m,2*m+1,1,0);
        for (int j=0; j<e[i].size(); j++) add_edge(i,e[i][j]+m,100000,0);
        add_edge(i,i+m,1000000,0);
    }
    dinic();
    for (int i=0; i<nedge; i+=2) {
        if (point[i]==2*m+1) {
            if (border[point[i^1]-m]) {
                if (flow[i]<x) return false;
            }
            else {
                if (flow[i]<1) return false;
            }
        }
    }
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) border[i] = 0;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            if (a[i]==0) continue;
            for (int j=0; j<n; j++) if (s[j]=='Y') {
                if (a[j]!=0) e[i].push_back(j);
                else border[i] = 1;
            }
        }

        int lo = 1;
        int hi = 10000;

        while (lo<hi) {
            int mi = (lo+hi)>>1;
            if (check(mi)) lo = mi+1;
            else hi = mi;
        }

        cout<<lo-1<<endl;
    }

    return 0;

}
