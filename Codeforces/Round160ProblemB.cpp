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

int n;
int a[55];
int p;
double dp[55][55][55];
double res;
double f[55];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
	int sum = 0;
	for (int i=0; i<n; i++) sum += a[i];
	cin>>p;
	if (sum<=p) {
		res = n;
		printf("%.12f\n",res);
		return 0;
	}
	f[0] = 1;
	for (int i=1; i<=n; i++) f[i] = f[i-1]*i;
	
	for (int ii=0; ii<n; ii++) {
		for (int i=0; i<=n; i++) for (int j=0; j<=p; j++) for (int k=0; k<n; k++) dp[i][j][k] = 0;
		dp[0][p][0] = 1;
		
		for (int i=1; i<=n; i++) {
			for (int j=0; j<=p; j++) {
				for (int k=0; k<n; k++) {
					if (i-1==ii) dp[i][j][k] = dp[i-1][j][k];
					else {
						dp[i][j][k] = dp[i-1][j][k];
						if (j+a[i-1]<=p && k>0) dp[i][j][k] += dp[i-1][j+a[i-1]][k-1];
					}
					//cout<<ii<<" "<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
				}
			}
		}
		
		for (int j=0; j<=p; j++) for (int k=0; k<n; k++) {
			if (a[ii]+(p-j)>p) {
				res += f[k]*f[n-1-k]*dp[n][j][k]*k;
				//cout<<ii<<" "<<j<<" "<<k<<" "<<dp[n][j][k]<<endl;
			}
		}
	}
	
	//cout<<res<<endl;
	
	res /= f[n];
	
	printf("%.12f\n",res);


    return 0;

}
