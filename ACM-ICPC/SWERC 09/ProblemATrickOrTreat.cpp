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

int n;
double x[50010], y[50010];

double f(double xx) {
    double t = 0;
    for (int i=0; i<n; i++) {
        t = max(t, sqrt((x[i]-xx)*(x[i]-xx) + y[i]*y[i]));
    }
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        for (int i=0; i<n; i++) scanf("%lf%lf",x+i,y+i);

        double xlo = 1000000.0;
        double xhi = -1000000.0;

        for (int i=0; i<n; i++) {
            xlo = min(xlo, x[i]);
            xhi = max(xhi, x[i]);
        }

        for (int i=0; i<100; i++) {
            double lt = (2*xlo + xhi)/3.0;
            double rt = (xlo + 2*xhi)/3.0;

            double lf = f(lt);
            double rf = f(rt);

            if (lf<rf) {
                xhi = rt;
            }
            else xlo = lt;
        }

        printf("%.8lf %.8lf\n",xlo, f(xlo));
    }

    return 0;

}
