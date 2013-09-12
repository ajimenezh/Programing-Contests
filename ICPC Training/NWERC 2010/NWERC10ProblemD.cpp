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

int t;
double a,b,vmax,f;
int n;
double x[51000], y[51000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;

    while (t--) {
        cin>>a>>b>>vmax>>f;
        cin>>n;

        for (int i=0; i<n; i++) cin>>x[i]>>y[i];
        for (int i=0; i<n; i++) x[i] /= 1000.0;
        for (int i=0; i<n; i++) y[i] /= 1000.0;

        double sum = 0;

        for (int i=0; i<n; i++) sum += sqrt(x[i]*x[i] + y[i]*y[i]);
        sum = sum*sum;

        double fuel = f;

        for (int i=0; i<n; i++) if (b*y[i]/x[i]/a>=-1.0) fuel -= b*y[i]/x[i]*sqrt(x[i]*x[i] + y[i]*y[i]);

        double res = a*sum/fuel;

        double tmp = 0;

        for (int i=0; i<n; i++) tmp += sqrt(x[i]*x[i] + y[i]*y[i])/vmax;

        double f2 = 0;
        for (int i=0; i<n; i++) if (vmax*a + b*y[i]/x[i]>=0.0) f2 += sqrt(x[i]*x[i] + y[i]*y[i])*(vmax*a + b*y[i]/x[i]);

        if (f2<f) res = max(res,tmp);

        res = round(a*sum/fuel*1000000.0)/1000000.0;

        printf("%.6f\n",res);
    }


    return 0;

}
