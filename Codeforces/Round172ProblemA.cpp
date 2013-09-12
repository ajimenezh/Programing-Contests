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

#define pi acos(-1.0)

int w,h,a1;
double a;
vector<pair<double,double> > v,v2;

struct mycomp {
  bool operator() (pair<double,double> i,pair<double,double> j) { return (atan2(i.second,i.first)<atan2(j.second,j.first));}
} comp;

void intersect(double x, double y, double b) {
    v.push_back(make_pair((1.0*h/2.0-y)/tan(b) + x,1.0*h/2.0));
    v.push_back(make_pair((-1.0*h/2.0-y)/tan(b) + x,-1.0*h/2.0));
    v.push_back(make_pair(1.0*w/2.0,tan(b)*(1.0*w/2.0-x)+y));
    v.push_back(make_pair(-1.0*w/2.0,tan(b)*(-1.0*w/2.0-x)+y));
}

double vect(double x1, double x2, double y1, double y2) {
    return abs(0.5*(x1*y2 - x2*y1));
}
double dist(double x, double y) {return sqrt(x*x + y*y);}

bool inside(double x, double y) {
    if (abs(x-1.0*w/2.0)<0.0000001) {
        if (abs(y)>1.0*h/2.0) return false;
    }
    else if (abs(x+1.0*w/2.0)<0.0000001) {
        if (abs(y)>1.0*h/2.0) return false;
    }
    else if (abs(y-1.0*h/2.0)<0.0000001) {
        if (abs(x)>1.0*w/2.0) return false;
    }
    else if (abs(y+1.0*h/2.0)<0.0000001) {
        if (abs(x)>1.0*w/2.0) return false;
    }
    return true;
}

double area() {
    double a = 0.0;
    for (int i=0; i<v.size(); i++) {
        if (inside(v[i].first,v[i].second))
            v2.push_back(v[i]);
        //cout<<dist(v[i].first,v[i].second)<<endl;
    }
    v = v2;
    sort(v.begin(),v.end(),comp);
    //for (int i=0; i<v.size(); i++) cout<<v[i].first<<" "<<v[i].second<<endl;
    double x = v[0].first, y = v[0].second;
    for (int i=1; i<v.size(); i++) {
        a += vect(x,y,v[i].first,v[i].second);
        //cout<<a<<endl;
        x = v[i].first;
        y = v[i].second;
    }
    a += vect(x,y,v[0].first,v[0].second);
    return a;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>w>>h>>a1;
    a = a1/180.0*pi;

    if (a1==0 || a1==180) {
        cout<<(long long)w*(long long)h<<endl;
        return 0;
    }
    else if (a1==90) {
        cout<<(long long)min(w,h)*(long long)min(w,h)<<endl;
    }
    else {
        intersect(1.0*h/2.0*sin(1.0*a),-1.0*h/2.0*cos(1.0*a),a);
        intersect(-1.0*h/2.0*sin(1.0*a),1.0*h/2.0*cos(1.0*a),a);
        intersect(1.0*w/2.0*cos(1.0*a),1.0*w/2.0*sin(1.0*a),a+pi/2.0);
        intersect(-1.0*w/2.0*cos(1.0*a),-1.0*w/2.0*sin(1.0*a),a+pi/2.0);

        printf("%.9f",area());
    }

    return 0;

}
