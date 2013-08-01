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

typedef long long ll;

struct point{
	ll x,y;
	point(){}
	point (ll x, ll y):x(x),y(y){}
	bool operator<(const point &p) const {
		return x<p.x || (x==p.x && y<p.y);
	}
};

ll cross(const point &O,const point &a, const point &b) {
	return (a.x-O.x)*(b.y-O.y) - (a.y-O.y)*(b.x-O.x);
}	

ll dot(ll x1, ll y1, ll x2, ll y2) {
	return x1*x2 + y1*y2;
}

vector<point> convex_hull(vector<point> &p) {
	int k = 0;
	int n = p.size();
	vector<point> ch(2*n);
	sort(p.begin(),p.end());
	
	for (int i=0; i<n; i++) {
		while (k>=2 && cross(ch[k-2], ch[k-1], p[i]) <= 0) k--;
		ch[k++] = p[i];
	}
	
	for (int i=n-2, t=k+1; i>=0; i--) {
		while (k >= t && cross(ch[k-2], ch[k-1], p[i]) <= 0) k--;
		ch[k++] = p[i];
	}
	ch.resize(k);
	return ch;
}

vector<point> hull;
int n,m;
int xb[110], yb[110];
int xw[110], yw[110];

bool inside(const point &a) {
	if (hull.size()<=2) return false;
	for (int i=0; i<hull.size()-1; i++) {
		if (cross(a,hull[i],hull[i+1])<0) return false;
		if (cross(a,hull[i],hull[i+1])==0) {
			if (dot(hull[i].x-a.x,hull[i].y-a.y,hull[i+1].x-a.x,hull[i+1].y-a.y)<=0) {
				return true;
			}
			else return false;
		}
	}
	return true;
}

bool intersect(point a1, point a2, point b1, point b2) {
	return a1.x<=b2.x && a2.x>=b1.x && a1.y<=b2.y && a2.y>=b1.y;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&m) && n!=0 ) {
		for (int i=0; i<n; i++) scanf("%d%d",xb+i,yb+i);
		for (int i=0; i<m; i++) scanf("%d%d",xw+i,yw+i);
		
		vector<point> p(n);
		bool good = 1;
		if (m>2) {
			for (int i=0; i<n; i++) p[i] = point(xb[i],yb[i]);
			hull = convex_hull(p); 
			
			for (int i=0; i<m; i++) if (inside(point(xw[i],yw[i]))) {
				good = 0;
				break;
			}	
		}
		else {
			if (m==2) {
				for (int i=0; i<m; i++) for (int j=i+1; j<m; j++) {
					if (intersect(point(xw[i],yw[i]),point(xw[j],yw[j]),point(xb[0],yb[0]),point(xb[1],yb[1]))) {
						good = 0;
					}
				}
			}
			else {
				for (int i=0; i<m; i++) for (int j=i+1; j<m; j++) {
					if ((xb[0]==xw[i]&&yb[0]==yw[i])||(xb[0]==xw[j]&&yb[0]==yw[j])) {
						good = 0;
					}
					else {
						if (dot(xw[i]-xb[0],yw[i]-yb[0],xw[j]-xb[0],yw[j]-yb[0])<0) {
							good = 0;
						}
					}
				}
			}
		}
		
		p.clear();
		p.resize(m);
		if (m>2) {
			for (int i=0; i<m; i++) p[i] = point(xw[i],yw[i]);
			hull = convex_hull(p); 
			
			for (int i=0; i<n; i++) if (inside(point(xb[i],yb[i]))) {
				good = 0;
				break;
			}	
		}
		else {
			if (m==2) {
				for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
					if (intersect(point(xb[i],yb[i]),point(xb[j],yb[j]),point(xw[0],yw[0]),point(xw[1],yw[1]))) {
						good = 0;
					}
				}
			}
			else {
				for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
					if ((xw[0]==xb[i]&&yw[0]==yb[i])||(xw[0]==xb[j]&&yw[0]==yb[j])) {
						good = 0;
					}
					else {
						if (dot(xb[i]-xw[0],yb[i]-yw[0],xb[j]-xw[0],yb[j]-yw[0])<0) {
							good = 0;
						}
					}
				}
			}
		}
		
		if (good) printf("YES\n");
		else printf("NO\n");
	}

    return 0;

}
