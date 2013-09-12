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

int n,m;
double p;
double dp[51][51][51][2];
int a[51];
double ways;
double sum;
double c[51][51];
int cnt;
bool vis[51][51][51][2];


double solve(int rest, int i, int maxq, int f) {
    if (vis[rest][i][maxq][f]) return dp[rest][i][maxq][f];
    if (i==m && rest==0) {
        dp[rest][i][maxq][f] = f;
        return f;
    }
    if (i==m && rest>0) {
        dp[rest][i][maxq][f] = 0;
        return 0;
    }


    double tmp = 0;
    for (int k=0; k<=min((maxq-1)*a[i],rest); k++) {
        if (!vis[rest-k][i+1][maxq][f]) solve(rest-k,i+1,maxq,f);
        tmp += c[rest][k]*dp[rest-k][i+1][maxq][f];
    }
    for (int k=min((maxq-1)*a[i],rest)+1; k<=min((maxq)*a[i],rest); k++) {
        if (!vis[rest-k][i+1][maxq][1]) solve(rest-k,i+1,maxq,1);
        tmp += c[rest][k]*dp[rest-k][i+1][maxq][1];
    }

    vis[rest][i][maxq][f] = 1;

    dp[rest][i][maxq][f] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        scanf("%d",a+i);
    }

    c[0][0] = 1;
    for (int i=1; i<=n; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j=1; j<i; j++) c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=0; k<=n; k++)  vis[i][j][k][0] = 0;
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=0; k<=n; k++)  vis[i][j][k][1] = 0;
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=1; k<=n; k++)  if (!vis[i][j][k][0]) solve(i,j,k,0);

    for (int i=1; i<=n; i++) {
        double tmp = dp[n][0][i][0];
        sum += tmp*i;
        ways += tmp;
    }

    p = 1.0*sum/(1.0*ways);

    printf("%.15f",p);

    return 0;

}
