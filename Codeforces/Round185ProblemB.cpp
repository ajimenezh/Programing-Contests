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

int n,m,p;
int q[100010];
int x,y;
long long sum[100010];
long long dp[100010][101];
int h[100010];
long long t[100010];

long long f(long long x1,long long y1,long long x2,long long y2,long long x3,long long y3) {

	return (double)(x1-x2)*(y1-y3) - (double)(x1-x3)*(y1-y2) > 0;
		
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


	cin>>m>>n>>p;
	for (int i=1; i<m; i++) {
		scanf("%d",h+i);
		h[i] += h[i-1];
	}
	for (int i=1; i<=n; i++) {
		int tmp, w;
		scanf("%d%d",&w,&tmp);
		t[i] = tmp - h[w-1];
	}
	sort(t+1,t+n+1);
	for (int i=1; i<=n; i++) {
		sum[i] = sum[i-1] + t[i];
	}
	
	for (int i=1; i<=n; i++) dp[i][1] = t[i]*i - sum[i];
	x = y = 0;
	
	for (int k=2; k<=p; k++) {
		
		x = y = 0;
		q[y] = 0;
		
		for (int i=1; i<=n; i++) {
			
			while (x+1<y) {
				if (f(q[y],dp[q[y]][k-1]+sum[q[y]],q[y-1],dp[q[y]-1][k-1]+sum[q[y]],q[y-2],dp[q[y-2]][k-1]+sum[q[y-2]])) break;
				q[y-1] = q[y];
				y--;
			}
			
			//cout<<x<<" "<<y<<endl;
			
			y++;
			q[y] = i;
			
			while (x<y) {
				if (dp[q[x+1]][k-1]+sum[q[x+1]]-dp[q[x]][k-1]-sum[q[x]]>=t[i]*(q[x+1]-q[x])) break;
				x++;
			}
			
			dp[i][k] = dp[q[x]][k-1]+sum[q[x]]-sum[i]+t[i]*(i-q[x]);
			
			//cout<<i<<" "<<k<<" "<<dp[i][k]<<" "<<t[i]<<" "<<sum[i]<<endl;

		}
	}
	
	cout<<dp[n][p]<<endl;
			 

    return 0;

}
