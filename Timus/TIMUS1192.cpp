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

double v, a, k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%lf%lf%lf",&v,&a,&k);

    double x = 0;
    double pi = 3.1415926535; double tmp = 0.0, c=1.0;

    v = v*v;
    x += sin(a/90.0*pi)/10.0*v/(1.0-1.0/k);

    printf("%.2f\n",round(x*100.0)/100.0);

    return 0;

}
