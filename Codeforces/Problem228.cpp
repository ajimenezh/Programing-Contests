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

#define y1 Y1

const long double eps = 1.0e-12;

typedef long double Double;
int n,n1,n2;

Double x1,y1,x2,y2;

Double sqr(Double a) {
	return a*a;
}

Double dist(Double a, Double b, Double c, Double d) {
	return sqrtl(sqr(a-c)+sqr(b-d));
}

Double mabs(Double a) {
	if (a<0) return -a;
	return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>n1>>n2;
	
	cin>>x1>>y1>>x2>>y2;
	
	Double alp = 360.0/((Double)n);
	
	Double h = dist(x1,y1,x2,y2) / (sinl(360/(n)*mabs(n2-n1)/2.0));
	
	Double mx = x1-x2;
	Double my = y2-y1;
	
	Double A = -mx;
	Double B = -my;
	
	Double C = -A*x1 - B*y1;
	
	Double xm = (x1+x2)/2.0;
	Double ym = (y1+y2)/2.0;
	
	Double x0,y0;
	
	if (abs(B)<eps) {
		Double x = -C/A;
		
		Double lo = -100000000.0;
		Double hi = 100000000.0;
		
		for (int i=0; i<100; i++) {
			Double mi = (lo+hi)/2;
			if (dist(xm,ym,x,mi)<dist(xm,ym,x,hi) || dist(xm,ym,x,mi)>dist(xm,ym,x,lo)) {
				if (dist(xm,ym,x,mi)>h) {
					hi = mi;
				}
				else {
					lo = mi;
				}
			}
			else {
				if (dist(xm,ym,x,mi)>h) {
					lo = mi;
				}
				else {
					hi = mi;
				}
			}
		}
		
		x0 = x;
		y0 = lo;
	}
	else {
		Double lo = -100000000.0;
		Double hi = 100000000.0;
		
		for (int i=0; i<100; i++) {
			Double mi = (lo+hi)/2;
			Double y = (-C-A*mi) / B;
			Double x = mi;
			Double yhi = (-C-A*hi) / B;
			Double ylo = (-C-A*lo) / B;
			if (dist(xm,ym,x,y)<dist(xm,ym,hi,yhi) || dist(xm,ym,x,y)>dist(xm,ym,lo,ylo)) {
				if (dist(xm,ym,x,y)>h) {
					hi = mi;
				}
				else {
					lo = mi;
				}
			}
			else {
				if (dist(xm,ym,x,y)>h) {
					lo = mi;
				}
				else {
					hi = mi;
				}
			}
		}
		
		y0 = (-C-A*lo) / B;
		x0 = lo;
	}
	
	cout<<x0<<" "<<y0<<endl;

    return 0;

}
