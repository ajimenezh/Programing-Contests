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

map<pair<int,int>,long long> dp;
int n,m,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d",&n,&m,&k) && n!=0) {
		dp.clear();
		for (int i=0; i<n; i++) for (int j=0; j<=n*m; j++) dp[make_pair(i,j)] = 0;
		long long p = 1;
		for (int i=0; i<n; i++) p *= (long long)m;
		for (int i=0; i<n; i++) {
			for (int j=0; j<=n*m; j++) {
				for (int t=1; t<=m; t++) {
					if (i==0) dp[make_pair(i,t)] = 1;
					else {
						if (t+j<=m*n) dp[make_pair(i,t+j)] += dp[make_pair(i-1,j)];
					}
				}
			}
		}
		//for (int i=0; i<=m*n; i++) cout<<i<<" "<<dp[make_pair(n-1,i)]<<endl;
		long long ans = 0;
		for (int i=0; i<=k+1; i++) ans += dp[make_pair(n-1,i)];
		for (int i=k+2; i<=n*m; i++) ans += (long long)(i-k)*dp[make_pair(n-1,i)];
		printf("%.12lf\n",(double)ans/p); 
	}

    return 0;

}
