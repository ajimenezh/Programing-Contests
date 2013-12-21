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
int x[100010];
int y[100010];
int p[100010];
double ang[100010];

bool comp(int i, int j) {
    return ang[i]<ang[j];
}

double vect(double x1, double y1, double x2, double y2) {
    return x1*y2 - x2*y1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d%d",x+i,y+i);
        ang[i] = atan2(y[i],x[i]);
        p[i] = i;
    }

    sort(p,p+n,comp);

    if (n==1) {
        cout<<0<<endl;
        return 0;
    }

    double ans = 10;
    for (int i=0; i<n; i++) {
        int next = (i+1)%n;

        double lo = 0.0;
        double hi = 2.0*acos(-1.0);

        for (int k=0; k<50; k++) {
            double mi = (lo+hi)/2;
            //cout<<mi/acos(-1.0)*180<<" "<<x[i]*cos(mi)-y[i]*sin(mi)<<" "<<x[i]*sin(mi)+y[i]*cos(mi)<<endl;
            if (vect(x[p[i]]*cos(mi)-y[p[i]]*sin(mi),x[p[i]]*sin(mi)+y[p[i]]*cos(mi),x[p[next]],y[p[next]])<=0) {
                hi = mi;
            }
            else lo = mi;
        }

        //cout<<x[p[i]]<<" "<<y[i]<<endl;
        //cout<<x[next]<<" "<<y[next]<<endl;
        //cout<<lo/acos(-1.0)*180<<endl;

        ans = min(ans, 2*acos(-1.0) - lo);
    }
    ans = ans/acos(-1.0)*180;

    if (ans-360.00>-1.0e-8) ans -= 360.0;

    printf("%.12lf",ans);

    return 0;

}
