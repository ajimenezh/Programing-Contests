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

const double eps = 1.0e-6;
const double pi = 3.1415926536;

struct pt{
    double x,y;
    pt(){};
    pt(double _x, double _y){
        x = _x;
        y = _y;
    }
};


double area(double r, int x) {
    return r*r*x*sin(2.0*pi/x)*0.5;
}

double dist(pt a, pt b) {
    return sqrt((double)(a.x-b.x)*(a.x-b.x) + (double)(a.y-b.y)*(a.y-b.y));
}

double vect(pt a, pt b, pt c) {
    double ux = a.x - b.x;
    double uy = a.y - b.y;
    double vx = c.x - b.x;
    double vy = c.y - b.y;

    return ux*vy - uy*vx;
}

double angle(double r, double a) {
    return acosl((2*r*r - a*a)/(2.0*r*r));
}

double gcd(double a, double b) {
    return b < 1e-4 ? a : gcd(b, fmod(a, b));
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    double x,y;
    pt a,b,c;
    scanf("%lf%lf",&x,&y);
    a = pt(x,y);
    scanf("%lf%lf",&x,&y);
    b = pt(x,y);
    scanf("%lf%lf",&x,&y);
    c = pt(x,y);


    double aa = dist(a,b);
    double bb = dist(b,c);
    double cc = dist(a,c);

    double r = (aa*bb*cc)/(2.0*abs(vect(a,b,c)));
    cout<<r<<endl;

    double ab = angle(r,aa);
    double ac = angle(r,bb);
    double bc = angle(r,cc);

    cout<<ab<<" "<<bc<<" "<<ac<<endl;

    double n = gcd(ab, gcd(bc,ac));

    cout<<n<<endl;

    cout<<(int)(2.0*pi/n)<<endl;

    printf("%.8lf", area(r,(int)(2*pi/n)));

    return 0;

}
