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

int n,k;
int a[10010];

bool check(double m) {
    double lo = 0.0;
    double hi = 0.0;
    for (int i=0; i<n; i++) {
        if (a[i]>m) hi += a[i]-m;
        else lo += m-a[i];
    }
    if (lo>hi) return 0;
    if (hi*(1.0-k*0.01)<lo) return 0;
    return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) cin>>a[i];

    double lo = 0.0;
    double hi = 1010.0;

    for (int i=0; i<100; i++) {
        double mi = (lo+hi)*0.5;
        if (check(mi)) {
            lo = mi;
        }
        else hi = mi;
    }

    printf("%.12lf",lo);

    return 0;

}
