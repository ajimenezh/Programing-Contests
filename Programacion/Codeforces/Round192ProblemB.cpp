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

int r,c;
char buf[1010][1010];
int dist[1010][1010];
int q[1000100];
int in,fn;

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void bfs(int x, int y) {
	for (int i=0; i<r; i++) for (int j=0; j<c; j++) dist[i][j] = -1;
	dist[x][y] = 0;
	in = 0; fn = 0;
	q[fn++] = x*c + y;
	
	while (in<fn) {
		int p = q[in++];
		x = p/c;
		y = p%c;
		for (int k=0; k<4; k++) {
			int u = x + dx[k];
			int v = y + dy[k];
			if (u<0 || u>=r) continue;
			if (v<0 || v>=c) continue;
			if (buf[u][v]=='T') continue;
			if (dist[u][v]!=-1) continue;
			
			dist[u][v] = 1 + dist[x][y];
			q[fn++] = u*c + v;
		}
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>r>>c;
	for (int i=0; i<r; i++) scanf("%s",buf+i);
	
	for (int i=0; i<r; i++) for (int j=0; j<c; j++) if (buf[i][j]=='E') {
		bfs(i,j);
		break;
	}
	
	int d = -1;
	for (int i=0; i<r; i++) for (int j=0; j<c; j++) if (buf[i][j]=='S') {
		d = dist[i][j];
		break;
	}
	
	int ans = 0;
	for (int i=0; i<r; i++) for (int j=0; j<c; j++) if (buf[i][j]>='0' && buf[i][j]<='9') {
		if (dist[i][j]<=d && dist[i][j]!=-1) ans += (buf[i][j]-'0');
	}
	
	cout<<ans<<endl;

    return 0;

}
