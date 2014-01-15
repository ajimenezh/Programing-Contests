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

const double pi = acos(-1.0);
const double eps = 1.0e-6;

struct PT {
    double x,y;
    PT() {}
    PT(double x,double y) : x(x), y(y) {}
    PT(const PT &p) : x(p.x), y(p.y) {}
    PT operator + (const PT &p) const { return PT(x+p.x, y+p.y); }
    PT operator - (const PT &p) const { return PT(x-p.x, y-p.y); }
    PT operator * (double c) const { return PT(x*c, y*c); }
    PT operator / (double c) const { return PT(x/c, y/c); }
    bool operator < (const PT &p) const { return x < p.x; }
};

double cross(PT p, PT q) { return p.x*q.y - p.y*q.x; }
double dot(PT p, PT q) { return p.x*q.x + p.y*q.y; }
double modulo(PT p) { return sqrt(p.x*p.x+p.y*p.y); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }

PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
    b = b-a;
    d = c-d;
    c = c-a;
    return a + b*cross(c,d)/cross(b,d);
}

PT ComputeCircleCenter(PT a, PT b, PT c) {
    b = (a+b)/2.0;
    c = (a+c)/2.0;
    return ComputeLineIntersection(b, b+RotateCW90(a-b), c, c+RotateCW90(a-c));
}

double CalcAng(PT c, PT a, PT b) {
    PT v = a - c;
    PT u = b - c;

    double prod = dot(u,v);
    prod /= modulo(u);
    prod /= modulo(v);

    if (abs(1-prod)<eps) return 0.0;
    if (abs(-1-prod)<eps) return pi;
    double ang = acos(prod);

    return ang;

}

bool check(double ang, double t) {
    int k = int(ang/t + eps);
    if (abs(k*t-ang)<eps) return true;
    return false;
}

PT p[3];
PT center;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    while (getline(cin,s) && s!="END") {
        for (int i=0; i<3; i++) {
            stringstream ss(s);
            double x, y;
            ss>>x>>y;
            p[i] = PT(x,y);
            if (i!=2) getline(cin,s);
        }
        center = ComputeCircleCenter(p[0],p[1],p[2]);

        vector<pair<double,PT> > v;

        double ang;
        for (int i=0; i<3; i++) {
            ang = atan2(p[i].y, p[i].x);
            v.push_back(make_pair(ang,p[i]));
        }

        sort(v.begin(),v.end());

        double ang1 = CalcAng(center, v[0].second,v[1].second);
        double ang2 = CalcAng(center, v[1].second,v[2].second);
        double ang3 = CalcAng(center, v[2].second,v[0].second);

        bool done = 0;
        for (int i=3; i<1000; i++) {
            double cur = 2.0*pi / i;

            bool good1 = 0, good2 = 0;

            if (check(ang1,cur) && check(ang2,cur) && check(ang3,cur)) {
                done = 1;
                cout<<i<<endl;
                break;
            }
        }
        if (!done) cout<<1000<<endl;
    }

    return 0;

}
