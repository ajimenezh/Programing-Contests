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

int n, r;
int x[1100], y[1100];
const double eps = 1.0e-8;

bool inside(int xx, int yy) {
    return xx*xx + yy*yy <= r*r;
}

vector<pair<double,double> > v;
vector<bool> st;

double vect(double x1, double y1, double x2, double y2) {
    return x1*y2 - x2*y1;
}

double ang(double x1, double y1, double x2, double y2) {
    return acos((x1*x2 + y1*y2)/sqrt(x1*x1+y1*y1)/sqrt(x2*x2+y2*y2));
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&r)!=EOF) {
        for (int i=0; i<n; i++) {
            scanf("%d%d",x+i,y+i);
        }

        for (int i=0; i<n; i++) {
            int j = (i+1)%n;
            if (!inside(x[i],y[i]) && !inside(x[j],y[j])) continue;
            if (inside(x[i],y[i]) && inside(x[j],y[j])) {
                v.push_back(make_pair(x[i],y[i]));
                st.push_back(0);
                continue;
            }
            double a = -(y[i]-y[j]);
            double b = (x[i]-x[j]);
            double c = -a*x[i] - b*y[i]; cout<<a<<" "<<b<<" "<<c<<endl;

            double aa = b*b+a*a;
            double bb = 2.0*c*b;
            double cc = c*c - a*a*r*r;

            double delta = bb*bb - 4*aa*cc;

            if (delta<0.0) cout<<"ERROR"<<endl;

            double yy = max((-bb + sqrt(delta))/2/aa,(-bb - sqrt(delta))/2/aa);

            double xx = (-c - b*yy)/a;

            if (inside(x[i],y[i])) {
                v.push_back(make_pair(x[i],y[i]));
                v.push_back(make_pair(xx,yy));
                st.push_back(0);
                st.push_back(1);
            }
            else {
                v.push_back(make_pair(xx,yy));
                st.push_back(1);
            }
        }

        double total = 0.0;
        for (int i=0; i<v.size(); i++) {

            double px1 = v[i].first;
            double py1 = v[i].second; cout<<px1<<" "<<py1<<" "<<st[i]<<endl;
            double px2 = v[(i+1)%v.size()].first;
            double py2 = v[(i+1)%v.size()].second;

            if (abs(px1*px1+py1*py1)<eps) continue;
            if (abs(px2*px2+py2*py2)<eps) continue;
            double area = vect(px1,py1,px2,py2)*0.5;
            int sgn = area/abs(area);
            if (st[i]&&st[(i+1)%v.size()]) {
                area = ang(px1,py1,px2,py2)/2.0*r*r;
            }
            total += abs(area)*sgn;

            cout<<abs(area)*sgn<<endl;
        }
        printf("%.12lf\n",total);
    }

    return 0;

}

