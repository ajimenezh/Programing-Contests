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

string s[35];
int m;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (true) {
		m = 0;
		while (getline(cin,s[m]) && s[m]!="") m++;
		if (m==0) break;
		
		int k = m*s[0].length();
		int N = s[0].length();
		init(2*k+2, 2*k, 2*k+1);
		

		for (int i=0; i<m; i++) {
			for (int j=0; j<s[0].length(); j++) {
				if (s[i][j]=='I') {
					add_edge(i*N+j,k+i*N+j,1,0);
					for (int t=0; t<4; t++) {
						int u = i + dx[t];
						int v = j + dy[t];
						if (u<0 || u>=m) continue;
						if (v<0 || v>=N) continue;
						if (s[u][v]=='N') add_edge(k+i*N+j,u*N+v,1,0);
						if (s[u][v]=='W') add_edge(u*N+v,i*N+j,1,0);
					}
				}
				if (s[i][j]=='W') add_edge(src,i*N+j,1,0);
				if (s[i][j]=='N') add_edge(i*N+j,dest,1,0);
			}
		}
		
		int ans = dinic();
		
		cout<<ans<<endl;
				
	}
	
    return 0;

}
