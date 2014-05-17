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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int Y1,y2,yw,x,y,r;

const double eps = 0.000001;

double dist(double x0, double y0, double px1, double py1, double px2, double py2)
{
    double vx = px2 - px1;
    double vy = py2 - py1;

    double m1 = vy/vx;
    double m2 = -vx/vy;

    double xi = (py1 - y0 + m2*x0 - m1*px1)/(m2-m1);

    double yi = y0 + m2*(xi-x0);

    return sqrt((x0-xi)*(x0-xi) + (y0-yi)*(y0-yi));
}

int main() {

    cin>>Y1>>y2>>yw>>x>>y>>r;

    Y1 += r;
    yw -= r;

    double p = 1.0*(yw + (yw-Y1))-eps;

    double x0 = 1.0*x;
    double y0 = 1.0*y;

    double m = (y0 - p)/x0;

    double xw = (1.0*yw - y0)/m + x0;

    double d = dist(0,y2-eps,xw,yw,0,Y1+eps);

    if (d<(r+eps)) cout<<-1;
    else printf("%.10f",xw);


	return 0;

}
