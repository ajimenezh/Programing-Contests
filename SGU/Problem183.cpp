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

#define INF 1000000000

int n,m;
int dp[110][110];
int sum[110][110];
int c[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%d",c+i);
	
	int ans = INF;
	
	for (int i=n-1; i>=0; i--) {
		dp[i%m][0] = INF;
		for (int j=1; j<m; j++) {
			if (i+j>=n) {
				sum[i%m][j] = INF;
			}
			else {
				if (i+m>=n) {
					sum[i%m][j] = c[i] + c[i+j];
				}
				else {
					sum[i%m][j] = c[i] + dp[(i+j)%m][m-j];
				}
			}
			if (i+j<m) ans = min(ans, sum[i%m][j]);
			dp[i%m][j] = min(dp[i%m][j-1], sum[i%m][j]);
		}
	}
	
	cout<<ans<<endl;

    return 0;

}
