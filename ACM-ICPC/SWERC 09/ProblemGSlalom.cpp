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
double xx,yy;
double y[1001], x[2][1010];
double dp[1001][2];

double dist(double a, double b) {
    return sqrt(a*a + b*b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        scanf("%lf%lf",&xx,&yy);
        y[0] = yy;
        x[0][0] = xx;
        x[1][0] = xx;
        for (int i=1; i<=n; i++) scanf("%lf%lf%lf",y+i,x[0]+i,x[1]+i);
        double ans;

        dp[n][0] = dp[n][1] = 0;

        for (int i=n-1; i>=0; i--) {
            for (int s=0; s<2; s++) {
                dn[i][s] = min(dp[i+1][0] + dist(x[s][i]-x[0][i+1],y[i]-y[i+1]), dp[i+1][1] + dist(x[s][i]-x[1][i+1],y[i]-y[i+1]));
            }
        }

        printf("%.12lf\n",ans);
    }

    return 0;

}
