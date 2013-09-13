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

    int l,r;
    cin>>l>>r;
    double area = 0.0;

    double delta = acos(-1.0)/4.0;
    int n = 1000000;
    delta /= n;

    for (int i=0; i<n; i++) {
        double alpha = delta*i;
        double x = tan(alpha)*l/2.0;
        if (sqrt(x*x+(double)l*l/4.0)>(double)r) {
            area += delta/2.0*(double)r*r;
        }
        else {
            area +=  (tan(delta*(i+1))*l/2.0 - tan(alpha)*l/2.0)*l/4.0;
        }
    }

    area *= 8.0;

    printf("%.3f\n",round(area*1000.0)/1000.0);

    return 0;

}
