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
#include <iomanip>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

double eps = 1e-12;

struct point { 
    double x, y; 
    point() {}
    point(double x, double y) : x(x), y(y) {}
    point(const point &p) : x(p.x), y(p.y)    {}
    point operator +(const point &p)  const { return point(x+p.x, y+p.y); }
    point operator -(const point &p)  const { return point(x-p.x, y-p.y); }
    point operator *(double c)     const { return point(x*c,   y*c  ); }
    point operator /(double c)     const { return point(x/c,   y/c  ); }

    bool operator<(const point &rhs)  const { return make_pair(y,x) < make_pair(rhs.y,rhs.x);  }
    bool operator==(const point &rhs) const { return make_pair(y,x) == make_pair(rhs.y,rhs.x); }
};

double dot(point p, point q)         { return p.x*q.x+p.y*q.y; }
double dist2(point p, point q)       { return dot(p-q,p-q); }
double cross(point p, point q)       { return p.x*q.y-p.y*q.x; }
double area2(point a, point b, point c) { return cross(a,b) + cross(b,c) + cross(c,a); }

point ProjectPointLine(point a, point b, point c) {
    return a + (b-a)*dot(c-a, b-a)/dot(b-a, b-a);
}

double DistancePointLine(point a, point b, point c) {
    return sqrt(dist2(c, ProjectPointLine(a, b, c)));
}

void ConvexHull(vector<point> &pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = (int) up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

int n;
int sw;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>sw;
	for (int tt=1; tt<=sw; tt++) {
		cin>>n;
		vector<point> vpts;
		for (int i=0; i<n; i++) {
			double x,y;
			cin>>x>>y;
			vpts.push_back(point(x,y));
		}
		
		ConvexHull(vpts);
		
		vector<double> heights(vpts.size(),0.0);
		
		for (int i=0; i<vpts.size(); i++) {
			for (int j=0; j<vpts.size(); j++) {
				heights[i] = max(heights[i], DistancePointLine(vpts[i],vpts[(i+1)%vpts.size()],vpts[j]));
			}
		}
		
		double area = 1000000000.0;
		for (int i=0; i<vpts.size(); i++) {
			for (int j=i+1; j<vpts.size(); j++) {
				point v1 = vpts[(i+1)%vpts.size()] - vpts[i];
				point v2 = vpts[(j+1)%vpts.size()] - vpts[j];
				double theta = acos(dot(v1,v2)/(sqrt(dot(v1,v1))*sqrt(dot(v2,v2))));
				if (theta<=eps) continue; 
				double tmp = heights[i]*heights[j]/sin(theta);
				area = min(area,tmp);
			}
		}
		
		cout << "Swarm " << (tt) << " Parallelogram Area: " << fixed << setprecision(4) << area << endl;
	}
	
    return 0;

}
