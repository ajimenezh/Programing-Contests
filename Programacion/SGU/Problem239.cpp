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
int dp[1010][2][2];
int a[1010];

int solve(int i, int x, int y) {
	if (i==n-1) {
		if (x+y==a[i]) return 1;
		return 0;
	}
	if (dp[i][x][y]>=0) return dp[i][x][y];
	
	if (x+y>a[i] || x+y+1<a[i]) {
		dp[i][x][y] = 0;
		return 0;
	}
	if (x+y==a[i]) {
		dp[i][x][y] = solve(i+1,y,0);
		return dp[i][x][y];
	}
	if (x+y+1==a[i]) {
		dp[i][x][y] = solve(i+1,y,1);
		return dp[i][x][y];
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) cin>>a[i];
	
	for (int i=0; i<n; i++) for (int j=0; j<2; j++) for (int k=0; k<2; k++) dp[i][j][k] = -1;
	cout<<(solve(0,0,0)+solve(0,0,1));

    return 0;

}
