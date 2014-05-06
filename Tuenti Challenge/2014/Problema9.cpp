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

const int maxnode=100000+5;
const int maxedge=100000+5;
const int INF=1000000000;

int n,src,dest,nedge;
int head[maxnode],point[maxedge],next[maxedge],flow[maxedge],capa[maxedge];
int dist[maxnode],q[maxnode],work[maxnode];

void init(int _n, int _src, int _dest) {
    n = _n;
    src = _src;
    dest = _dest;
    for (int i=0; i<n; i++) head[i] = -1;
    nedge = 0;
}

void add_edge(int u, int v, int c1, int c2) {
    point[nedge] = v; capa[nedge]=c1; flow[nedge] = 0; next[nedge]=head[u]; head[u] = (nedge++);
    point[nedge] = u; capa[nedge]=c2; flow[nedge] = 0; next[nedge]=head[v]; head[v] = (nedge++);
}

bool bfs() {
    for (int i=0; i<n; i++) dist[i] = -1;
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
        for (int i = 0; i<n; i++) work[i] = head[i];

        f += dfs(src,INF);
    }
    return f;
}

int main() {

    int t;
    cin>>t;
    for (int i=0; i<t; i++) {
        string name;
        cin>>name;
        int normal, dirt;
        cin>>normal>>dirt;

        int r, ii;
        cin>>r>>ii;

        init(r+2, r, r+1);

        string s;
        getline(cin,s);
        int fr, t, f;
        for (int j=0; j<ii; j++) {
            getline(cin,s);
            stringstream ss(s);
            ss>>s;
            if (s[0]>='0' && s[0]<='9') fr = atoi(s.c_str());
            else {
                if (s==name) fr = r;
                else fr = r+1;
            }

            ss>>s;
            if (s[0]>='0' && s[0]<='9') t = atoi(s.c_str());
            else {
                if (s==name) t = r;
                else t = r+1;
            }

            ss>>s;
            if (s=="normal") f = normal;
            else f = dirt;

            ss>>s;

            int k = atoi(s.c_str());

            add_edge(fr, t, f*k*200, 0);
        }

        cout<<name<<" "<<dinic()<<"\n";
    }

    return 0;

}
