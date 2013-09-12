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

bool m[45][45];
int N,t;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
pair<pii,pii> all[1605];
int tot;

bool inside(int a, int b) {
	if (a>=N || a<0) return false;
	if (b>=N || b<0) return false;
	if (!m[a][b]) return false;
	return true;
}



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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>N>>t;
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) m[i][j] = 1;
	for (int i=0; i<t; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		m[a][b] = 0;
	}
	
	if ((N*N-t)%2!=0) {
		cout<<"No"<<endl;
		return 0;
	}
	
	init(N*N+2,N*N,N*N+1);
	
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) if (m[i][j]) {
		if (i%2==0) {
			if (j%2==0) {
				add_edge(src,i*N+j,1,0);
				for (int d=0; d<4; d++) {
					if (inside(i+dx[d],j+dy[d])) {
						add_edge(i*N+j,(i+dx[d])*N+j+dy[d],1,0);
					}
				}
			}
			else {
				add_edge(i*N+j,dest,1,0);
			}
		}
		else {
			if (j%2!=0) {
				add_edge(src,i*N+j,1,0);
				for (int d=0; d<4; d++) {
					if (inside(i+dx[d],j+dy[d])) {
						add_edge(i*N+j,(i+dx[d])*N+j+dy[d],1,0);
					}
				}
			}
			else {
				add_edge(i*N+j,dest,1,0);
			}
		}
	}
	
	int f = dinic();

	
	if (f!=(N*N-t)/2) {
		cout<<"No"<<endl;
		return 0;
	}
	
	for (int i=0; i<nedge; i+=2) {
		if (flow[i]==1 && point[i]!=dest && point[i^1]!=src) {
			all[tot++] = mp(mp(point[i]/N,point[i]%N),mp(point[i^1]/N,point[i^1]%N));
		}
	}
	
	cout<<"Yes"<<endl;
	
	int nv = 0;
	for (int i=0; i<tot; i++) if (all[i].first.second==all[i].second.second) nv++;
	cout<<nv<<endl;
	for (int i=0; i<tot; i++) if (all[i].first.second==all[i].second.second) {
		cout<<min(all[i].first.first+1,all[i].second.first+1)<<" "<<all[i].first.second+1<<endl;
	}
	
	int nh = 0;
	for (int i=0; i<tot; i++) if (all[i].first.first==all[i].second.first) nh++;
	cout<<nh<<endl;
	for (int i=0; i<tot; i++) if (all[i].first.first==all[i].second.first) {
		cout<<all[i].first.first+1<<" "<<min(all[i].first.second+1,all[i].second.second+1)<<endl;
	}

    return 0;

}
