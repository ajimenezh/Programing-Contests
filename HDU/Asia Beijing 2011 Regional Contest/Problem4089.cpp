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

typedef double Double;

const Double eps = 1.0e-12;

int n,m,k;
double p1,p2,p3,p4;

Double dp[2010][2010];
Double p[2010];
Double c[2010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d",&n,&m,&k)!=EOF) {
		
		scanf("%lf%lf%lf%lf",&p1,&p2,&p3,&p4);
		
		if (fabs(1.0-p1-p2)<eps) {
			printf("%.5lf\n",(double)0.0);
			continue;
		}
		
		Double p12 = p2 / (1.0-p1);
		Double p14 = p4 / (1.0-p1);
		Double p13 = p3 / (1.0-p1);
		
		p[0] = 1.0;
		for (int i=1; i<=n; i++) {
			if (p[i-1]>eps) p[i] = p[i-1]*p12;
			else p[i] = 0.0;
		}
		
		dp[1][1] = (Double)p4 / (1.0 - p1 - p2); 
		c[1] = p14; 
		
		for (int i=2; i<=n; i++) {
			for (int j=2; j<=min(i,k); j++) {
				c[j] = p14 + p13*dp[i-1][j-1];
			}
			for (int j=k+1; j<=i; j++) {
				c[j] = p13*dp[i-1][j-1];
			}
			
			dp[i][i] = 0.0;
			
			for (int j=1; j<=i; j++) {
				dp[i][i] += c[j]*p[i-j];
			}
			dp[i][i] /= (1.0-p[i]);
			
			dp[i][1] = c[1] + p[1]*dp[i][i];
			
			for (int j=2; j<i; j++) dp[i][j] = c[j] + p[1]*dp[i][j-1];
		
		}

		printf("%.5lf\n",(double)dp[n][m]);
		
	}

    return 0;

}
