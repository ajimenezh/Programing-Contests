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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    double x,y,c;

    while (scanf("%lf%lf%lf", &x,&y,&c)!=EOF) {
        double lo = 0.0000001;
        double hi = min(x,y);

        for (int i=0; i<100; i++) {
            double m = (lo+hi)/2.0;
            double d = 1.0 / (sqrt(c*c + m*m) / m / y);

            double f = x/d - sqrt(c*c+(d-m)*(d-m))/(d-m);

            if (f<0) {
                hi = m;
            }
            else lo = m;
        }
        double d = 1.0 / (sqrt(c*c + lo*lo) / lo / y);
        printf("%.3lf\n",round(d*1000.0)/1000.0);
    }

    return 0;

}

