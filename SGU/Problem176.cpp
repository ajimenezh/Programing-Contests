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

#define INF 1000000000
#define maxedge 100*110

int n,m;
int fr[maxedge], to[maxedge], c[maxedge];
int sp[maxedge];
int nedge;

int cap[110][110];
int dist[110];
int q[500];
int N;

bool bfs(int src, int dest) {
	for (int i=0; i<N; i++) dist[i] = -1;
	dist[src] = 0;
	int in = 0;
	int fn = 0;
	q[fn++] = src; 
	while (in<fn && dist[dest]==-1) {
		int p = q[in++]; 
		for (int i=0; i<N; i++) if (i!=p) {
			if (cap[p][i]>0 && dist[i]==-1) {
				dist[i] = dist[p] + 1;
				q[fn++] = i;
			}
		}
	}
	return dist[dest]>=0;
}

int dfs(int source, int dest, int cur) {
	if (cur==0) return 0;
	if (source==dest) return cur;
	int f = 0;
	for (int i=0; i<N; i++) {
		if (cap[source][i]>0 && dist[source] + 1 == dist[i]) {
			int tmp = dfs(i,dest, min(cur-f,cap[source][i]));
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

bool check(int MAX) {
	
	nedge = 0;
	int src = n;
	int dest = n+1;
	N = n+2;
	
	for (int i=0; i<N; i++) for (int j=0; j<N; j++) cap[i][j] = 0;

	for (int i=0; i<m; i++) {
		if (sp[i]) {
			cap[fr[i]][dest] += c[i];
			cap[src][to[i]] += c[i];
		}
		else {
			cap[fr[i]][to[i]] += c[i];
		}
	}
	cap[n-1][0] = MAX;
	
	while (bfs(src,dest)) {
		dfs(src,dest,INF);
	}
	
	for (int i=0; i<n; i++) {
		if (cap[src][i]>0) return 0;
	}
	
	return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<m; i++) {
		scanf("%d%d%d%d",fr+i,to+i,c+i,sp+i);
		fr[i]--; to[i]--;
	}
	
	int lo = 0;
	int hi = 1000000000;
	if (check(hi)) {
		while (lo<hi) {
			int mi = (lo+hi)>>1;
			if (check(mi)) {
				hi = mi;
			}
			else lo = mi+1;
		}
		check(lo);
		cout<<lo<<endl;
		int j = 0;
		for (int i=0; i<m; i++) {
			cout<<c[i] - cap[fr[i]][to[i]]<<" ";
		}cout<<endl;
	}
	else {
		cout<<"Impossible";
	}

    return 0;

}
