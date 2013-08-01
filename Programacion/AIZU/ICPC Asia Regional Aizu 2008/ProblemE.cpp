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

typedef long double Double;

const Double eps = 1.0e-12;

struct point{
	Double x,y,z;
	point(){}
	point(Double x, Double y,Double z):x(x),y(y),z(z){}
};
struct circle{
	point c;
	Double r;
	circle(){};
	circle(point p, Double r):c(p),r(r){}
};

point operator-(const point &a, const point &b) {
	return point(a.x-b.x,a.y-b.y,a.z-b.z);
}
point operator+(const point &a, const point &b) {
	return point(a.x+b.x,a.y+b.y,a.z+b.z);
}
Double operator*(const point &a, const point &b) {
	return a.x*b.x + a.y*b.y + a.z*b.z;
}
point operator*(const Double &t, const point &a) {
	return point(t*a.x,t*a.y,t*a.z);
}

int n;
point u;
circle v[110];
point O;

Double dist(point a, point b) {
	point c = a-b;
	return sqrt(c.x*c.x+c.y*c.y+c.z*c.z);
}

bool intersect(point p, circle c) {
	Double A = p*p;
	Double B = 2.0*(O*p) - 2.0*(c.c*p);
	Double C = O*O + c.c*c.c - 2.0*(O*c.c) - c.r*c.r;
	
	Double delta = B*B - 4.0*A*C;
	
	return delta > eps;
}

point intersection(point p, circle c) {
	p = (1.0/(p*p))*p;
	
	Double A = p*p;
	Double B = 2.0*(O*p) - 2.0*(c.c*p);
	Double C = O*O + c.c*c.c - 2.0*(O*c.c) - c.r*c.r;
	
	Double delta = B*B - 4.0*A*C;
	if (abs(delta)<eps) {
		Double m = -B/(2.0*A);
		return point(O+m*p);
	}
	else {
		if (delta<eps) return O;
		Double m = (-B + sqrtl(delta)) / (2.0*A); 
		point a1 = O + m*p;
		m = (-B - sqrtl(delta)) / (2.0*A);
		point a2 = O + m*p;
		if (dist(O,a1)<dist(O,a2)) return a1;
		else return a2;
	}
	
	return point(0,0,0);
}

point reflexion(point dir, circle c, point q) {
	
	point n = q - c.c;
	
	n = (1.0 / sqrtl(n*n))*n;
	dir = (-1.0 / sqrtl(dir*dir))*dir;
	
	point b = (2.0*(dir*n))*n - dir;
	
	return b;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		int x,y,z,r;
		scanf("%d%d%d",&x,&y,&z);
		u = point(x,y,z);
		O = point(0,0,0);
		for (int i=0; i<n; i++) {
			scanf("%d%d%d%d",&x,&y,&z,&r);
			v[i] = circle(point(x,y,z),r);
		}
		int last = -1;
		for (int i=0; i<10; i++) {
			bool exist = 0;
			point next;
			point dir;
			for (int j=0; j<n; j++) if (j!=last) {
				if (intersect(u,v[j])) {
					point p = intersection(u,v[j]);
					if ((p-O)*u<eps) continue;
					
					if (!exist || dist(O,p)<dist(O,next)) {
						exist = 1;
						next = p;
						dir = reflexion(u,v[j],p);
						last = j;
					}
				}
			}
			if (!exist) break;
			u = dir;
			O = next;
		}
		printf("%.4lf %.4lf %.4lf\n",(double)O.x, (double)O.y, (double)O.z);
	}

    return 0;

}
