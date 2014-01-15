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

void add_edge(int u, int v, int c1, int c2=0) {
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

int t;
int N;
int a[101];
string vs[101];
bool ady[101][101];
bool border[100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>N;
        for (int i=0; i<N; i++) cin>>a[i];
        for (int i=0; i<N; i++) cin>>vs[i];

        for (int i=0; i<N; i++) for (int j=0; j<N; j++) ady[i][j] = vs[i][j]=='Y';
        //for (int i=0; i<N; i++) ady[i][i] = 1;

        for (int i=0; i<N; i++) {
            border[i] = 0;
            for (int j=0;  j<N; j++) if (ady[i][j] && a[j]==0) {
                border[i] = 1;
                break;
            }
        }

        int lo = 1;
        int hi = 10000;
        int offset = 0;

        while (lo<hi) {
            int mid = (lo+hi+offset%2)/2;
            offset++;

            init(2*N+2,2*N,2*N+1);

            for (int i=0; i<N; i++) if (a[i]!=0) add_edge(src,2*i,a[i]);
            for (int i=0; i<N; i++) if (a[i]!=0 && !border[i]) add_edge(2*i+1,dest,1);
            for (int i=0; i<N; i++) if (a[i]!=0 && border[i]) add_edge(2*i+1,dest,mid);
            for (int i=0; i<N; i++) if (a[i]!=0) {
                for (int j=0; j<N; j++) if (ady[i][j] && a[j]!=0) add_edge(2*i,2*j+1,100);
            }
            for (int i=0; i<N; i++) add_edge(2*i,2*i+1,INF);

            int sum = 0;
            for (int i=0; i<N; i++) if (border[i] && a[i]!=0) sum += mid;
            for (int i=0; i<N; i++) if (!border[i] && a[i]!=0) sum ++;

            int flow = dinic();

            //cout<<mid<<" "<<flow<<" "<<sum<<endl;

            if (flow<sum) {
                hi = mid-1;
            }
            else {
                lo = mid;
            }
        }

        cout<<hi<<endl;
    }

    return 0;

}
