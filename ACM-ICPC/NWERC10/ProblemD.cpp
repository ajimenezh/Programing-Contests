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

double alp, beta, vmax, f;
int r;
double x[10010], y[10010];
bool done[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>alp>>beta>>vmax>>f;
        double t = 0.0;
        double c = 0.0;
        cin>>r;
        r++;
        x[0] = 0;
        y[0] = 0;
        for (int i=1; i<r; i++) {
            cin>>x[i]>>y[i];
            x[i] /= 1000.0;
            y[i] /= 1000.0;
            x[i] += x[i-1];
            y[i] += y[i-1];
        }
        for (int i=0; i<r; i++) done[i] = 0;
        for (int i=1; i<r; i++) {
            double s = (double)(y[i]-y[i-1]) / (x[i]-x[i-1]);

            if (s<0.0) {
                double v = -beta*s/alp;
                if (v>vmax+eps) {
                    done[i] = 1;
                    v = vmax;
                    double l = sqrt((x[i]-x[i-1])*(x[i]-x[i-1]) + (y[i]-y[i-1])*(y[i]-y[i-1]));
                    t += l/v;
                }
            }
            else {
                c += beta*s;
            }
        }

        if (c>f+eps) {
            cout<<"IMPOSSIBLE"<<endl;
            continue;
        }


        double lo = 0.0;
        double hi = vmax;
        t = 0.0;
        for (int k=0; k<50; k++) {
            double v = (lo+hi)/2.0;
            double ff = 0.0;
            t = 0.0;
            for (int i=1; i<r; i++) {
                double s = (double)(y[i]-y[i-1]) / (x[i]-x[i-1]);
                double l = sqrt((x[i]-x[i-1])*(x[i]-x[i-1]) + (y[i]-y[i-1])*(y[i]-y[i-1]));

                c = v*alp + beta*s;
                if (c<0) {
                    double vv = -beta*s/alp;
                    vv = min(vv,vmax);
                    vv = max(vv,0.0);
                    c = 0;
                    t += l/vv - l/v;
                }
                ff += c*l;
                t += l/v;
            }

            if (ff>f+eps ) hi = v;
            else lo = v;
        }
        printf("%.12lf\n",t);
    }

    return 0;

}
