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

typedef long double ldouble;

ldouble ab, ac, ad, bc, bd, cd;

struct point{
	ldouble x,y,z;
	point(ldouble x=0, ldouble y=0, ldouble z=0): x(x), y(y), z(z) {}
};

ldouble sqr(ldouble a) {return a*a;}

point operator -(const point &a, const point &b) {
	return point(a.x-b.x, a.y-b.y,a.z-b.z);
}

ldouble det(point a, point b, point c) {
	ldouble x = a.x*(b.y*c.z - b.z*c.y);
	x += -a.y*(b.x*c.z - b.z*c.x);
	x += a.z*(b.x*c.y - c.x*b.y);
	return x;
}

ldouble mabs(ldouble a) {
	if (a<0) return -a;
	return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>ab>>ac>>ad>>bc>>bd>>cd;
	
	point A((ldouble)0,(ldouble)0,(ldouble)0);
	point B(ab,(ldouble)0,(ldouble)0);
	
	ldouble x1 = (sqr(ac) - sqr(bc) + sqr(ab));
	
	x1 /= (2.0*ab);
	
	ldouble y1 = sqrtl(sqr(ac) - sqr(x1));
	
	point C(x1,y1,(ldouble)0);
	
	ldouble x2 = (sqr(ad) - sqr(bd) + sqr(ab));
	
	x2 /= (2.0*ab);
	
	ldouble y2 = (sqr(ad) - sqr(cd) - sqr(x2) + sqr(x2-x1) + sqr(y1));
	y2 /= (2.0*y1);
	
	ldouble z2 = sqrtl(sqr(ad) - sqr(x2) - sqr(y2));
	
	point D(x2,y2,z2);
	
	ldouble volume = mabs(det(B-A,C-A,D-A)) / 6.0;
	
	//long long vol = roundl(volume*100000);
	printf("%.4f\n",(double)volume); 
	//printf("%lld.%lld\n",vol/10000, vol%10000);
	

    return 0;

}
