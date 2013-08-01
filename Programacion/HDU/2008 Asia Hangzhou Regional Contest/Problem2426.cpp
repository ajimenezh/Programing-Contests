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

#define INF 10000000

int n,N,M,e;
int graph[510][510];
int fx[510];
int fy[510];

int hungarian() {
	int p,q;
	vector<int> x(n, -1), y(n, -1);
	for (int i=0; i<n; i++) fx[i] = -INF;
	for (int j=0; j<n; j++) fy[j] = 0;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			fx[i] = max(fx[i],graph[i][j]);
		}
	}
	
	for (int i = 0; i < n; ) {
		vector<int> t(n, -1), s(n+1, i);
		for (p = 0, q = 0; p <= q && x[i] < 0; p++) {
			for (int k = s[p], j = 0; j < n && x[i] < 0; j++) {
				if (fx[k] + fy[j] == graph[k][j] && t[j] < 0) {
					s[++q] = y[j], t[j] = k;
					if (s[q] < 0) {
						for (p = j; p >= 0; j = p) {
							y[j] = k = t[j], p = x[k], x[k] = j;
						}
					}
				}
			}
		}
		if (x[i] < 0) {
			int d = INF;
			for (int k = 0; k <= q; k++) {
				for (int j = 0; j < n; ++j) {
					if (t[j] < 0) d = min(d, fx[s[k]] + fy[j] - graph[s[k]][j]);
				}
			}
			for (int j = 0; j < n; ++j) fy[j] += (t[j] < 0 ? 0 : d);
			for (int k = 0; k <= q; ++k) fx[s[k]] -= d;
		} 
		else ++i;
	}   
	
	int sum = 0;
	for (int i=0; i<N; i++) {
		if (x[i]==-1) return -INF;
		else {
			if (graph[i][x[i]]<0) return -INF;
			else sum += graph[i][x[i]];
		}
	}
	return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int k = 1;

	while (scanf("%d%d%d",&N,&M,&e)!=EOF) {
		n = max(N,M);
		for (int i=0; i<n; i++) {
			for (int j=0; j<n; j++) graph[i][j] = -INF;
		}
		
		for (int i=0; i<e; i++) {
			int s,r,v;
			scanf("%d%d%d",&s,&r,&v);
			graph[s][r] = max(graph[s][r],v);
			if (graph[s][r]<0) graph[s][r] = -INF;
		}
		
		int temp = hungarian();
		if (temp<0) temp = -1;
		
		printf("Case %d: %d\n",k++,temp);

	}

    return 0;

}
