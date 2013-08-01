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

int n,m;
int vp,vs,vt;
priority_queue<pair<int,int> > q;
char buf[25][25];
int dist[25][25];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int k = 1;

	while (scanf("%d%d",&n,&m)!=EOF) {
		scanf("%d%d%d",&vp,&vs,&vt);
		for (int i=0; i<n; i++) scanf("%s",buf+i);
		int xs,ys,xt,yt;
		scanf("%d%d%d%d",&xs,&ys,&xt,&yt);
		
		for (int i=0; i<n; i++) for (int j=0; j<m; j++) dist[i][j] = INF;
		dist[xs][ys] = 0;
		while (!q.empty()) q.pop();
		q.push(make_pair(0,xs*m+ys));
		
		while (!q.empty() && dist[xt][yt]==INF) {
			int x = q.top().second/m;
			int y = q.top().second%m;
			q.pop();
			for (int k=0; k<4; k++) {
				int u = x + dx[k];
				int v = y + dy[k];
				if (u<0 || u>=n) continue;
				if (v<0 || v>=m) continue;
				if (buf[u][v]=='@') continue;
				
				if (buf[u][v]=='#') {
					if (dist[u][v]>vp+dist[x][y]) {
						dist[u][v] = vp+dist[x][y];
						q.push(make_pair(-dist[u][v],u*m+v));
					}
				}
				if (buf[u][v]=='.') {
					if (dist[u][v]>vs+dist[x][y]) {
						dist[u][v] = vs+dist[x][y];
						q.push(make_pair(-dist[u][v],u*m+v));
					}
				}
				if (buf[u][v]=='T') {
					if (dist[u][v]>vt+dist[x][y]) {
						dist[u][v] = vt+dist[x][y];
						q.push(make_pair(-dist[u][v],u*m+v));
					}
				}
			}
		}
		
		if (dist[xt][yt]==INF) dist[xt][yt] = -1;
		
		printf("Case %d: %d\n",k++,dist[xt][yt]);
	}

    return 0;

}
