#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

const double eps = 1.0e-8;
const double pi = acos(-1.0);

struct point{
    double x,y;
    point(double x=0, double y=0) : x(x),y(y){}
};
point cen, p[4],a, tan1, tan2;
double r;
point rotate(point p,double angle)
{
	point res;
	res.x=p.x*cos(angle)-p.y*sin(angle);
	res.y=p.x*sin(angle)+p.y*cos(angle);
	return res;
}
void tangency(point poi,point o,double r,point &r1,point &r2)
{
	double line=sqrt((poi.x-o.x)*(poi.x-o.x)+(poi.y-o.y)*(poi.y-o.y));
	double angle=acos(r/line);
	point unit,lin;
	lin.x=poi.x-o.x;
	lin.y=poi.y-o.y;
	unit.x=lin.x/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
	unit.y=lin.y/sqrt(lin.x*lin.x+lin.y*lin.y)*r;
	r1=rotate(unit,-angle);
	r2=rotate(unit,angle);
	r1.x+=o.x; r1.y+=o.y;
	r2.x+=o.x; r2.y+=o.y;

	//cout<<r1.x<<" "<<r1.y<<endl;
	//cout<<r2.x<<" "<<r2.y<<endl;

}

double dist(point p1, point p2) {
    return sqrt((p1.x-p2.x)*(p1.x-p2.x) + (p1.y-p2.y)*(p1.y-p2.y));
}

double distPtSg(point p1, point r1, point r2) {
    double a1 = -(r1.x - r2.x);
    double b1 = -(r1.y - r2.y);
    double c1 = -a1*p1.x - b1*p1.y;

    double b2 = r1.x - r2.x;
    double a2 = -(r1.y - r2.y);
    double c2 = -a2*r1.x - b2*r1.y;

    double y = (c1*a2 - a1*c2) / (b2*a1 - a2*b1);
    double x;
    if (abs(a1)>eps) x = (-c1-b1*y)/a1;
    else x = (-c2-b2*y)/a2;

    double tmp = (r1.x-x)*(r2.x-x) + (r1.y-y)*(r2.y-y);

    if (tmp>0) {
        return min(dist(p1,r1),dist(p1,r2));
    }
    else return dist(point(x,y),p1);
}

double calc(double ang) {
    point t;
    t.x = cen.x + r*cos(ang);
    t.y = cen.y + r*sin(ang);
    double ans = 1.0e15;
    for (int i=0; i<4; i++) {
        ans = min(ans, distPtSg(t,p[i],p[(i+1)%4]));
    }
    return dist(t,a) + ans;
}

void solve(double l, double r) {
    for (int i=0; i<100; i++) {
        double lt = l + (r-l)/3.0;
        double rt = l + (r-l)/3.0*2.0;
        if (calc(lt)<calc(rt)) r = rt;
        else l = lt;
    }
    double ans = calc(l);
    printf("%.2lf\n",1.0*((int)round(ans*100.0))/100.0);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    double xxx, yyy;
    while (cin>>xxx>>yyy && !(xxx==0&&yyy==0)) {
        a = point(xxx,yyy);
        cin>>xxx>>yyy;
        cen = point(xxx,yyy);
        cin>>r;
        cin>>xxx>>yyy;
        p[0] = point(xxx,yyy);
        cin>>xxx>>yyy;
        p[3] = point(xxx,yyy);
        p[1].x = p[0].x; p[1].y = p[3].y;
        p[2].x = p[3].x; p[2].y = p[0].y;

        tangency(a,cen,r,tan1,tan2);

        double th1 = atan2(tan1.y-cen.y,tan1.x-cen.x);
        double th2 = atan2(tan2.y-cen.y,tan2.x-cen.x);
        if (th1<0) th1 += 2*pi;
        if (th2<0) th2 += 2*pi;
        if (th1>th2) swap(th1,th2);
        if (th2-th1<pi) solve(th1,th2);
        else solve(th2-2*pi,th1);
    }

    return 0;

}

