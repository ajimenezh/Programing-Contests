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

int tt;
int c,t,l;
int e[25][1000], p[25][1000];
int dp[25][1000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>tt;
	while (tt--) {
		cin>>c>>t>>l;
		for (int i=0; i<c; i++) {
			for (int j=0; j<t; j++) scanf("%d%d",&p[i][j],&e[i][j]);
		}
		
		for (int i=0; i<t; i++) dp[0][i] = p[0][i] + e[0][i];
		
		for (int i=1; i<c; i++) {
			for (int k=0; k<t; k++) {
				dp[i][k] = 1000000000;
				for (int j=0; j<t; j++) {
					dp[i][k] = min(dp[i][k], dp[i-1][j] + e[i][k] + abs(p[i][k]-p[i-1][j]));
				}
			}
		}
		
		int ans = 1000000000;
		for (int i=0; i<t; i++) ans = min(ans, dp[c-1][i] + abs(l-p[c-1][i]));
		
		cout<<ans<<endl;
	}

    return 0;

}
