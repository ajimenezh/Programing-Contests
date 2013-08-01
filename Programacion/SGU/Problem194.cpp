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

const int maxnode=200+5;
const int maxedge=maxnode*maxnode+5;
const int INF=1000000000;

int n,m;
int src,dest;

int cap[205][205];
int dist[205];
int q[500];

int cm[maxedge];
int fr[maxedge], to[maxedge];

bool bfs() {
	for (int i=0; i<n; i++) dist[i] = -1;
	dist[src] = 0;
	int in = 0;
	int fn = 0;
	q[fn++] = src; 
	while (in<fn && dist[dest]==-1) {
		int p = q[in++]; 
		for (int i=0; i<n; i++) if (i!=p) {
			if (cap[p][i]>0 && dist[i]==-1) {
				dist[i] = dist[p] + 1;
				q[fn++] = i;
			}
		}
	}
	return dist[dest]>=0;
}

int dfs(int source, int cur) {
	if (cur==0) return 0;
	if (source==dest) return cur;
	int f = 0;
	for (int i=0; i<n; i++) {
		if (cap[source][i]>0 && dist[source] + 1 == dist[i]) {
			int tmp = dfs(i, min(cur-f,cap[source][i]));
			f += tmp;
			cap[source][i] -= tmp;
			cap[i][source] += tmp;
			if (tmp==cur) {
				break;
			}
		}
	}
	return f;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	
	src = n;
	dest = n+1;
	
	for  (int i=0; i<m; i++) {
		int u,w,c,l;
		scanf("%d%d%d%d",&u,&w,&l,&c);
		cap[u-1][w-1] += c-l;
		cap[src][w-1] += l;
		cap[u-1][dest] += l;
		
		cm[i] = l;
		to[i] = w-1;
		fr[i] = u-1;
	}

	n = n+2;
	
	while (bfs()) {
		dfs(src,INF);
	}

	bool good = 1;
	for (int i=0; i<n-2; i++) {
		if (cap[src][i]>0) good = 0;
	}
	
	if (!good) {
		cout<<"NO"<<endl;
	}
	else {
		cout<<"YES"<<endl;
		for (int i=0; i<m; i++) {
			cout<<(cm[i]+cap[to[i]][fr[i]])<<endl;
		}
	}

    return 0;

}
