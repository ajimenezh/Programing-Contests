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

#ifdef _WIN32
	#define readlong(x) scanf("%I64d",&x)
#else
	#define readlong(x) scanf("%lld",&x)
#endif

//Convex Hull Optimization
//
// Works for the recursiom dp[i] = min(j<i){dp[j]+b[j]*a[i]}
// b[j]>=b[j+1]
//This algorithms is tested if a[i]<=a[i+1] but should work without this condition

int n;
long long a[100010];
long long b[100010];
long long c[100010];
long long qy0[100010];
long long qm[100010];
int x,y;

long long f(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3) {

	return (double)(x1-x2)*(y1-y3) - (double)(x1-x3)*(y1-y2) > 0;
		
}
	

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) readlong(a[i]);
	for (int i=0; i<n; i++) readlong(b[i]);
	
	x=y=0;
	qm[0] = -b[0];
	qy0[0] = 0;
	c[0] = 0;
	
	for (int i=1; i<n; i++) {
		
			while (x<y) {
				if (qy0[x+1]-qy0[x]>a[i]*(qm[x+1]-qm[x])) break;
				x++;
			}
			
			c[i] = qy0[x] - a[i]*qm[x];
			y++;
			qm[y] = -b[i];
			qy0[y] = c[i];
			while (x+1<y) {
				if (f(qm[y-2],qy0[y-2],qm[y-1],qy0[y-1],qm[y],qy0[y])) break;
				qm[y-1] = qm[y];
				qy0[y-1] = qy0[y];
				y--;
			}
	}
		
	cout<<c[n-1]<<endl;

    return 0;

}
