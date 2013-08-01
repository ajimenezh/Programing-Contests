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

#define mod 1000000007LL

long long dp[101][10010];
int n,k;
long long m;
long long c[101][101];
long long p[101][101][101];

long long fpow(long long a, long long b) {
	if (b==0) return 1LL;
	long long tmp = fpow(a,b/2LL);
	tmp = (tmp*tmp)%mod;
	if (b%2==0) return tmp;
	return (tmp*a)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m>>k;
	
	for (int i=0; i<=100; i++) {
		c[i][0] = 1;
		c[i][i] = 1;
		for (int j=1; j<i; j++) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}
	for (int i=0; i<=100; i++) for (int j=0; j<=i; j++) for (int t=1; t<=100; t++) p[i][j][t] = fpow(c[i][j],(m+n-t)/n);
	dp[0][0] = 1;
	
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=k; j++) {
			for (int t=0; t<=n; t++) {
				if (j-t<0) continue;
				
				dp[i][j] = (dp[i][j] + (dp[i-1][j-t]*p[n][t][i])%mod)%mod;
				
			}
			
			//cout<<dp[i][j]<<" "<<i<<" "<<j<<endl;
		}
	}
	
	cout<<dp[n][k]<<endl;

    return 0;

}
