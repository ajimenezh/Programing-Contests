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

int k;
long long dp[61][31];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>k;
	
	dp[0][0] = 1;
	
	for (int i=1; i<=2*k; i++) {
		dp[i][0] = 1;
		dp[i][i] = 1;
		for (int j=1; j<i; j++) dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
	}
	
	cout<<dp[2*k][k]/(k+1)<<" "<<k+1<<endl;

    return 0;

}
