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
double r;
double x[110], y[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    scanf("%lf",&r);
    for (int i=0; i<n; i++) scanf("%lf%lf",x+i,y+i);

    double tot = 0.0;
    for (int i=0; i<n; i++) {
        int cur = i;
        int next = (i+1)%n;

        double d1 = sqrt((x[cur]-x[next])*(x[cur]-x[next]) + (y[cur]-y[next])*(y[cur]-y[next]));

        tot += d1;
    }
    tot += 2*r*acos(-1.0);

    printf("%.2f\n",round(tot*100.0)/100.0);

    return 0;

}
