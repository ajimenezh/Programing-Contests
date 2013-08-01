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
struct point{
	double x,y;
	point(int x=0, int y=0): x(x),y(y){}
};
vector<point> xy,xz;
vector<int> xs;

double area(double x, vector<point> &v) {
	double lo = 100000;
	double hi = -100000;
	
	for (int i=0; i<v.size(); i++) {
		double x1 = v[i].x;
		double x2 = v[(i+1)%v.size()].x;
		double y1 = v[i].y;
		double y2 = v[(i+1)%v.size()].y;
		
		if ((x-x2)*(x-x1)<=0) {
			double m = (x-x1)/(x2-x1);
			double yy = m*(y2-y1) + y1;
			
			hi = max(hi, yy);
			lo = min(lo, yy);
		}
	}

	return (hi-lo);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&m,&n) && n!=0) {
		xy.clear();
		xz.clear();
		xs.clear();

		int minim = 100000, maxim = -10000;
		int tm = 1000000, tma = -1000000;
		for (int i=0; i<m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			xy.push_back(point(a,b));
			xs.push_back(a);
			tm = min(tm,a);
			tma = max(tma, a);
		}
		minim = tm;
		maxim = tma;
		tm = 1000000;
		tma = -100000;
		for (int i=0; i<n; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			xz.push_back(point(a,b));
			xs.push_back(a);
			tm = min(tm,a);
			tma = max(tma, a);
		}
		minim = max(minim,tm);
		maxim = min(maxim, tma);
		
		sort(xs.begin(),xs.end());
		xs.erase(unique(xs.begin(),xs.end()),xs.end());
		
		double vol = 0.0;
		
		for (int i=0; i<xs.size()-1; i++) {
			if (xs[i]>=minim && xs[i]<=maxim && xs[i+1]>=minim && xs[i+1]<=maxim) {
				double l = xs[i];
				double r = xs[i+1];
				double mid = (l+r)/2;
				
				double a1 = area(l,xz)*area(l,xy);
				double a2 = area(r,xz)*area(r,xy);
				double a3 = area(mid,xz)*area(mid,xy);
				
				vol += (r-l)*(a1 + a2 + a3*4.0) / 6.0;
			}
		}
		
		printf("%.12lf\n",vol);
	}

    return 0;

}
