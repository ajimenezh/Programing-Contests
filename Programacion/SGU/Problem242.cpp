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

const int MAXN = 410;
const int MAXM = 210*210 + 2*210;

int n,k;
int N;
int src, dest;
int nedge;
int point[MAXM], cap[MAXM], flow[MAXM], next[MAXM], head[MAXM];
vector<int> v[MAXN];

void addedge(int u, int v, int c) {
	point[nedge] = v; cap[nedge] = c; flow[nedge] = 0; next[nedge] = head[u]; head[u] = nedge++;
	point[nedge] = u; cap[nedge] = 0; flow[nedge] = 0; next[nedge] = head[v]; head[v] = nedge++;
}

int dist[MAXN], q[MAXN];
int in,fn;

bool bfs() {
	for (int i=0; i<N; i++) dist[i] = -1;
	dist[src] = 0;
	in = fn = 0;
	q[fn++] = src;
	while (in<fn && dist[dest]==-1) {
		int p = q[in++];
		for (int i=head[p]; i!=-1; i = next[i]) {
			if (cap[i]-flow[i]>0 && dist[point[i]]==-1) {
				dist[point[i]] = 1 + dist[p];
				q[fn++] = point[i];
			}
		}
	}
	return dist[dest]!=-1;
}

int dfs(int source, int MAX) {
	if (source==dest) return MAX;
	if (MAX==0) return 0;
	
	int cur = 0;
	for (int i = head[source]; i!=-1; i = next[i]) {
		if (cap[i]-flow[i]>0 && dist[point[i]]==1+dist[source]) {
			int f = dfs(point[i], min(MAX-cur,cap[i]-flow[i]));
			cur += f; 
			flow[i] += f;
			flow[i^1] -= f;
			if (cur==MAX) break;
		}
	}
	
	return cur;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>k;
	for (int i=0; i<n+k+2; i++) head[i] = -1;
	for (int i=0; i<n; i++) {
		int t; cin>>t;
		while (t--) {
			int a;
			cin>>a;
			a--;
			addedge(i,n+a,1);
		}
	}
	src = n+k;
	dest = n+k+1;
	N = n+k+2;
	for (int i=0; i<n; i++) addedge(src,i,1);
	for (int i=0; i<k; i++) addedge(n+i,dest,2);
	
	int f = 0;
	while (bfs()) {
		f += dfs(src, 1000000);
	}
	
	if (f!=k*2) cout<<"NO"<<endl;
	else {
		cout<<"YES"<<endl;
		for (int i=0; i<nedge; i+=2) {
			if (point[i]!=dest && point[i^1]!=src) {
				if (flow[i] == 1) {
					v[point[i]-n].push_back(point[i^1]);
				}
			}
		}
		for (int i=0; i<k; i++) sort(v[i].begin(),v[i].end());
		for (int i=0; i<k; i++) {
			cout<<v[i].size()<<" ";
			for (int j=0; j<v[i].size(); j++) cout<<v[i][j]+1<<" ";
			cout<<endl;
		}
	}

    return 0;

}
