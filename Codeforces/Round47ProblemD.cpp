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

#define eps 0.000000000001

int n,k,e;
int x,y;
int vx[101],vy[101];
double dp[101][101];
double m;

double go(int i, int t) {
    if (t<0) return 0.0;
    if (i==n && t==0) return 1.0;
    if (i==n && t>0) return 0.0;
    if (dp[i][t]>-0.5) return dp[i][t];

    int d2 = (vx[i]-x)*(vx[i]-x) + (vy[i]-y)*(vy[i]-y);
    if (abs(m)<eps) {
        if (d2==0) {
            dp[i][t] = go(i+1,t-1);
            return dp[i][t];
        }
        else {
            dp[i][t] = go(i+1,t);
            return dp[i][t];
        }
    }
    if (d2-m*m<2*m*eps) {
        dp[i][t] = go(i+1,t-1);
        return dp[i][t];
    }
    double ex = 1.0*d2/(m*m);
    double p = exp(1.0-ex);

    dp[i][t] = p*go(i+1,t-1) + (1.0-p)*go(i+1,t);

    return dp[i][t];
}

double solve() {
    double lo = 0;
    double hi = 1100;

    for (int i=0; i<200; i++) {
        m = (lo+hi)/2.0;
        cout<<lo<<" "<<hi<<" "<<m<<endl;
        for (int j=0; j<=n; j++) for (int p=0; p<n; p++) dp[p][j] = -1;
        double est = 0.0;
        for (int j=k; j<=n; j++) est += go(0,j);
        printf("%.12f\n",est);
        if (1000.0*(est-eps)>e) hi = m+eps;
        else lo = m;
    }

    m = hi;

    return m;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>e;
    cin>>x>>y;
    for (int i=0; i<n; i++) cin>>vx[i]>>vy[i];

    double sol = solve();

    printf("%.16f",sol);

    return 0;

}
