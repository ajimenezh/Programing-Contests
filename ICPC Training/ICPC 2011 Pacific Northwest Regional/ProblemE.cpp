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

int n,m;
int dist[65][65][33][33];
int px,py;
int sx,sy;
struct seg{
	long long x1,y1,x2,y2;
	seg(int x1, int y1, int x2, int y2):x1(x1),y1(y1),x2(x2),y2(y2){}
	seg() {}
}sg[8];

pair<int,int> q[4000000];


bool IsOnSegment(int xi, int yi, int xj, int yj,
                        int xk, int yk) {
  return (xi <= xk || xj <= xk) && (xk <= xi || xk <= xj) &&
         (yi <= yk || yj <= yk) && (yk <= yi || yk <= yj);
}

char ComputeDirection(int xi, int yi, int xj, int yj,
                             int xk, int yk) {
  int a = (xk - xi) * (yj - yi);
  int b = (xj - xi) * (yk - yi);
  return a < b ? -1 : a > b ? 1 : 0;
}

bool intersect(seg a, seg b) {
	
	int x1 = a.x1, x2 = a.x2, y1 = a.y1, y2 = a.y2;
	int x3 = b.x1, x4 = b.x2, y3 = b.y1, y4 = b.y2;
	
	char d1 = ComputeDirection(x3, y3, x4, y4, x1, y1);
	char d2 = ComputeDirection(x3, y3, x4, y4, x2, y2);
	char d3 = ComputeDirection(x1, y1, x2, y2, x3, y3);
	char d4 = ComputeDirection(x1, y1, x2, y2, x4, y4);
	return (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
		  ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) ||
		 (d1 == 0 && IsOnSegment(x3, y3, x4, y4, x1, y1)) ||
		 (d2 == 0 && IsOnSegment(x3, y3, x4, y4, x2, y2)) ||
		 (d3 == 0 && IsOnSegment(x1, y1, x2, y2, x3, y3)) ||
		 (d4 == 0 && IsOnSegment(x1, y1, x2, y2, x4, y4));
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		ss>>n>>m;
		ss>>sx>>sy>>px>>py; 
		int t;
		ss>>t;
		for (int i=0; i<t; i++) {
			int x1,y1,x2,y2;
			ss>>x1>>y1>>x2>>y2;
			sg[i] = seg(x1,y1,x2,y2);
		}
		
		for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) {
			for (int vx=0; vx<=32; vx++) for (int vy=0; vy<=32; vy++) {
				dist[i][j][vx][vy] = -1;
			}
		}
		dist[sx][sy][16][16] = 0;
		int in = 0;
		int fn = 0;
		q[fn++] = mp(sx*m+sy,(0+16)*40+0+16);
	
		while (in<fn && dist[px][py][16][16]==-1) {
			int x,y;
			x = q[in].first/m;
			y = q[in].first%m;
			int vx,vy;
			vx = q[in].second/40 - 16;
			vy = q[in].second%40 - 16;
			in++;
			
			//cout<<x<<" "<<y<<" "<<vx<<" "<<vy<<endl;
			
			for (int i=-1; i<=1; i++) for (int j=-1; j<=1; j++) {
				if (vx+i<-16 || vy+i<-16 || vx+i>16 || vy+i>16) continue;
				
				if (i!=0 && j!=0) continue;
				
				seg cur = seg(x,y,x+vx+i,y+vy+j);
				
				//cout<<x+vx+i<<" "<<y+vy+j<<" "<<vx+i<<" "<<vy+j<<endl;
				
				if (x+vx+i<0 || x+vx+i>=n) continue;
				if (y+vy+j<0 || y+vy+j>=m) continue;
				
				if (dist[x+vx+i][y+vy+j][vx+i+16][vy+j+16]!=-1) continue;
				
				//cout<<x+vx+i<<" "<<y+vy+j<<" "<<vx+i<<" "<<vy+j<<endl;
				
				bool good = 1;
				for (int k=0; k<t; k++) {
					if (intersect(cur,sg[k])) {
						good = 0;
						break;
					}
				}
				
				//cout<<good<<" "<<x+vx+i<<" "<<y+vy+j<<" "<<vx+i<<" "<<vy+j<<endl;
				
				if (good) {
					dist[x+vx+i][y+vy+j][vx+i+16][vy+j+16] = dist[x][y][vx+16][vy+16] + 1;
					q[fn++] = mp((x+vx+i)*m+y+vy+j,(vx+i+16)*40+vy+j+16);
				}
			}
		}
			
		cout<<dist[px][py][16][16]<<endl;
	}
	
    return 0;

}
