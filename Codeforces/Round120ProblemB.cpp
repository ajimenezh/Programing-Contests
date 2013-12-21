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

int x[2],y[2],r[2];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<2; i++) cin>>x[i]>>y[i]>>r[i];

    int d = (x[0]-x[1])*(x[0]-x[1]) + (y[0]-y[1])*(y[0]-y[1]);

    int s = d - r[0]*r[0] - r[1]*r[1] - 2*r[0]*r[1];

    if (s==0) printf("0.000000\n");
    else {
        double ans = (sqrt(d) - r[1] - r[0])/2.0;

        if (ans<0) ans = 0;

        if (sqrt(d)<r[0] || sqrt(d)<r[1]) {

            ans = max(r[0],r[1]) - min(r[0],r[1]) - sqrt(d);
            ans /= 2.0;
            if (ans<0) {
                ans = 0;
            }
        }

        printf("%.12lf",ans);
    }

    return 0;

}
