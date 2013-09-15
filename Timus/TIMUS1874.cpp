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

double solve(int a, int b) {

    double lo = 0;
    double hi = a;
    for (int i=0; i<100; i++) {
        double m = (lo+hi)/2;
        double y = m;
        double x = y*y/2.0/sqrt(b*b-y*y) - sqrt(b*b-y*y)*0.5;
        double f = y + sqrt(a*a-x*x)*0.5 - x*x*0.5/sqrt(a*a-x*x);
        if (f>0) lo = m;
        else hi = m;
    }

    double y = lo;
    double x = y*y/2.0/sqrt(b*b-y*y) - sqrt(b*b-y*y)*0.5;
    double f = x*y + 0.5*x*sqrt(a*a-x*x) + 0.5*y*sqrt(b*b-y*y);

    return f;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int l1,l2;
    cin>>l1>>l2;

    printf("%.10lf",solve(max(l1,l2),min(l1,l2)));

    return 0;

}
