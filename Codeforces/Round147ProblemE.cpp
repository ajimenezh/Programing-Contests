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

#define INF 1<<30

const int NM = 10000+5; // max nodes
const int M = 100000+5; // max edges

int nodes, nedge, src, dest;
int point[M], next[M], flow[M], capa[M], cost[M];
int head[NM], dist[NM], expand[NM], prev[NM], edge[NM];
bool changed[NM];

void init (int _nodes, int _src, int _dest) {
	nodes = _nodes;
	src = _src;
	dest = _dest;
	nedge = 0;
	for (int i = 0; i<nodes; i++) head[i] = -1;
}

void addEdge (int u, int v, int c, int w) {
	point[nedge]=v, capa[nedge]=c, cost[nedge]=w,  flow[nedge]=0, next[nedge]=head[u], head[u]=(nedge++);
	point[nedge]=u, capa[nedge]=0, cost[nedge]=-w, flow[nedge]=0, next[nedge]=head[v], head[v]=(nedge++);
}

pii ford() {
	int mflow = 0, mcost = 0;
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

string t;
string s[100];
int n;
int a[100];
int C[28];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>s[i];
        cin>>a[i];
    }

    for (int i=0; i<28; i++) C[i] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<s[i].length(); j++) {
            C[s[i][j]-'a']++;
        }
    }
    for (int i=0; i<t.length(); i++) {
        C[t[i]-'a']--;
    }
    for (int i=0; i<28; i++) {
        if (C[i]<0) {
            cout<<-1;
            return 0;
        }
    }

    int c = 'z' - 'a' + 1;

    int N = c*n + n + c + 1;
    init(N+2,N,N+1);


    for (int i=0; i<c; i++) {
        int cnt = 0;
        for (int j=0; j<t.length(); j++) {
            if (t[j]-'a'==i) cnt++;
        }
        addEdge(N-1-c+i,N-1,cnt,0);
    }
    addEdge(N-1,N+1,INF,0);

    for (int i=0; i<n; i++) {
        for (int k=0; k<c; k++) {
            int cnt = 0;
            for (int j=0; j<s[i].length(); j++) {
                if (s[i][j]-'a'==k) cnt++;
            }
            addEdge((c+1)*i,(c+1)*i + 1 + k,cnt,0);
            addEdge((c+1)*i + 1 + k, N-1-c+k,INF,0);
        }
        addEdge(N,(c+1)*i,a[i],i+1);
    }

    pair<int,int> p = ford();

    if (p.first!=t.length()) {
        cout<<-1;
        return 0;
    }

    cout<<p.second<<endl;

    return 0;

}
