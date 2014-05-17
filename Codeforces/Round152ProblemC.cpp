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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
int a[100010];
double dp[100010][101];
double tmp[101];
double c[10];
double b[10];
int q;
double res;

void update(int p, int d)
{
    fo(i,100) tmp[i] = 0;

    fo(i,100) if (a[p]<i)
    {
        int tot = a[p];
        int untast = i;
        int tast = a[p]-i;

        double t = 1.0;
        for (int j=0; j<d; j++) t = t*(1.0*i-j)/(j+1.0);

        b[0] = tast;
        c[0] = untast;

        for (int j=0; j<=d; j++) b[j] = b[j-1]*(tast-j)/(j+1.0);
        for (int j=0; j<=d; j++) c[j] = c[j-1]*(untast-j)/(j+1.0);

        for (int j=0; j<d; j++) tmp[i-j] += dp[p][i]*b[j]*c[d-j]/t;


    }

    fo(i,100) dp[p][i] = tmp[i];
}


int main() {

    res = 0;

    cin>>n;
    fo(i,n) scanf("%d",a[i]);

    fo(i,n) fo(j,100) dp[i][j] = 0;
    fo(i,n) dp[i][a[i]] = 1.0;

    fo(i,n) if (a[i]==0) res += 1.0;

    cin>>q;

    fo(i,q)
    {
        int u,v,k;
        scanf("%d%d%d",&u,&v,&k);
        u--; v--;

        res -= dp[u][0];

        update(u,k);

        res += dp[u][0];

        a[u] -= k;
        a[v] += k;
    }


	return 0;

}
