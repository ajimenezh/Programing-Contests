//Ulm Local 2006
//Problem: Basic Wall Maze
//
// Solution: BFS

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

#define n 6

int a[10][10];
bool bad[10][10][10][10];
int q[100];
int in,fn;
int sx,sy,ex,ey;
int dist[10][10];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
char dir[] = {'E', 'S', 'W', 'N'}; 
int pre[10][10];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&sx,&sy) && sx) {
		scanf("%d%d",&ex,&ey);
		for (int i=0; i<8; i++) for (int j=0; j<8; j++) {
			for (int ii=0; ii<8; ii++) for (int jj=0; jj<8; jj++) {
				bad[i][j][ii][jj] = 0;
			}
		}
		for (int i=0; i<3; i++) {
			int xl,yl,xr,yr;
			cin>>xl>>yl>>xr>>yr;
			if (yl==yr) {
				for (int j=xl+1; j<=xr; j++) {
					bad[j][yl][j][yl+1] = 1;
					bad[j][yl+1][j][yl] = 1;
				}
			}
			else {
				for (int j=yl+1; j<=yr; j++) {
					bad[xl][j][xl+1][j] = 1;
					bad[xl+1][j][xl][j] = 1;
				}
			}
		}
		
		in = fn = 0;
		for (int i=1; i<7; i++) for (int j=1; j<7; j++) dist[i][j] = -1;
		dist[sx][sy] = 0;
		q[fn++] = sx*10+sy;
		
		while (in<fn && dist[ex][ey]==-1) {
			int x = q[in]/10;
			int y = q[in++]%10;
			
			for (int i=0; i<4; i++) {
				int u = x + dx[i];
				int v = y + dy[i];
				
				if (u<1 || u>6) continue;
				if (v<1 || v>6) continue;
				if (bad[x][y][u][v]) continue;
				if (dist[u][v]!=-1) continue;
				
				dist[u][v] = dist[x][y] + 1;
				q[fn++] = u*10 + v;
				pre[u][v] = i;
			}
		}
		
		int x = ex, y = ey;
		vector<char> v;
		while (x!=sx || y!=sy) {
			v.push_back(dir[pre[x][y]]);
			int tmp = x;
			x = x - dx[pre[x][y]];
			y = y - dy[pre[tmp][y]];
		}
		
		reverse(v.begin(),v.end());
		for (int i=0; i<v.size(); i++) {
			cout<<v[i];
		}
		cout<<endl;
	}
	
    return 0;

}
