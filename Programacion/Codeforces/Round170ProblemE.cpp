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

vector<int> x[2010];
int n;

#define INF 1000000000

const int N = 1000+5; // max nodes
const int M = 400000+5; // max edges

int nodes, nedge, src, dest;
int point[M], next[M], flow[M], capa[M];
double cost[M];
int head[N];
double dist[N];
int expand[N], prev[N], edge[N];
bool changed[N];

void init (int _nodes, int _src, int _dest) {
	nodes = _nodes;
	src = _src;
	dest = _dest;
	nedge = 0;
	for (int i = 0; i<nodes; i++) head[i] = -1;
}

void addEdge (int u, int v, int c, double w) {
	point[nedge]=v, capa[nedge]=c, cost[nedge]=w,  flow[nedge]=0, next[nedge]=head[u], head[u]=(nedge++);
	point[nedge]=u, capa[nedge]=0, cost[nedge]=-w, flow[nedge]=0, next[nedge]=head[v], head[v]=(nedge++);
}

pair<int,double> ford() {
	int mflow = 0;
	double mcost = 0;
	while (1) {
		for (int i=0; i<nodes; i++) dist[i] = INF, prev[i] = -1, changed[i] = 0;
		dist[src] = 0;
		changed[src] = 1;
		expand[src] = INF;
		while (1) {
			bool ok = 1;
			for (int i=0; i<nodes; i++) if (changed[i]) {
				changed[i] = 0;
				for (int k = head[i]; k>=0; k=next[k]) {
					if (flow[k] < capa[k] && dist[i]+cost[k] < dist[point[k]]) {
						dist[point[k]] = dist[i]+cost[k];
						changed[point[k]] = 1;
						prev[point[k]] = i;
						edge[point[k]] = k;
						expand[point[k]] = min(expand[i], capa[k]-flow[k]);
						ok = 0;
					}
				}
			}
			if (ok) break;
		}
		if (prev[dest] < 0) break;
		int d = expand[dest];
		mflow += d;
		mcost += d*dist[dest];
		for (int k = dest; k != src; k = prev[k]) {
			flow[edge[k]] += d;
			flow[edge[k]^1] -= d;
		}
   }
   return mp(mflow,mcost);
}

int y[405];
int v[402];
int id[405];

double sqr(int a) {return (double)a*a;}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		b += 1000;
		y[i] = b;
		x[b].push_back(a);
	}
	
	init(2*n+2,2*n,2*n+1);
	
	for (int i=0; i<n; i++) addEdge(src,i,2,0);
	for (int i=0; i<n; i++) addEdge(i+n,dest,1,0);
	
	sort(y,y+n);
	reverse(y,y+n);
	int c = 0;
	for (int i=0; i<n; i++) if (i==0 || y[i]!=y[i-1]) v[c++] = y[i];
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i=0; i<c-1; i++) {
		cnt2 = cnt1 + x[y[i]].size();
		int tmp = cnt2;
		for (int j=0; j<(int)x[y[i]].size(); j++) {
			cnt2 = tmp;
			for (int t=i+1; t<c; t++) {
				for (int k=0; k<(int)x[y[t]].size(); k++) {
					addEdge(cnt1,cnt2+n,1,sqrt(sqr(x[y[i]][j]-x[y[t]][k])+sqr(y[i]-y[t])));
					cnt2++;
					//cout<<x[y[i]][j]<<" "<<x[y[i+1]][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
					//cout<<sqr(x[y[i]][j]-x[y[i+1]][k])+sqr(y[i]-y[i+1])<<endl;
					//cout<<cnt1<<" "<<cnt2<<endl;
				}
			}
			cnt1++;
		}
	}
	
	pair<int,double> p = ford();
	
	//cout<<p.first<<" "<<p.second<<endl;
	
	if (p.first==n-1) printf("%.15f\n",p.second);
	else cout<<-1;

    return 0;

}
