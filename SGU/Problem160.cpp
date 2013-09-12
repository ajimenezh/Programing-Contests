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
bool dp[10005][1005];
bool pre[10005][1005];
int a[10005];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%d",a+i);

	dp[0][1] = 1;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<m; j++) if (dp[i-1][j]) {
			dp[i][(j*a[i-1])%m] = 1;
			pre[i][(j*a[i-1])%m] = 1;
			dp[i][j] = 1;
			pre[i][j] = 0;
		}
	}
	
	int ans = 1;
	for (int i=1; i<m; i++) if (dp[n][i]) {
		ans = i;
	}
	vector<int> v;
	int p = ans;
	for (int i=n; i>=1; i--) {
		if (pre[i][p]) {
			v.push_back(i);
			for (int j=1; j<m; j++) {
				if ((j*a[i-1])%m==p && dp[i-1][j]) {
					p = j;
					break;
				}
			}
		}
	}
	cout<<ans<<endl;
	reverse(v.begin(),v.end());
	for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";

    return 0;

}
