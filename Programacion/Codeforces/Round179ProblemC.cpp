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

#define mod 1000000007

int n,w;
int x,y;
long long dp[55][55][55];
long long c[101][101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>w;
	w /= 50;
	for (int i=0; i<n; i++) {
		int a;
		cin>>a;
		if (a==50) x++;
		else y++;
	}
	
	for (int i=0; i<100; i++) {
		c[i][0] = 1; c[i][i] = 1;
		for (int j=1; j<i; j++) c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}
	
	dp[0][0][0] = 1;
	
	for (int i=1; i<=50; i++) {
		for (int j=0; j<=x; j++) {
			for (int k=0; k<=y; k++) {
				for (int t=0; t<=x; t++) {
					if (t>j || t>w) continue;
					int p = (w-t)/2;
					p = min(p,k);
					if (t==0) {
						if (j==x && k==y) dp[i][j][k] = (dp[i][j][k] + dp[i-1][x][k-p])%mod;
						else if (j>0) dp[i][j-1][k] = (dp[i][j-1][k] + (dp[i-1][j][k-p]*j*c[y-(k-p)][p])%mod)%mod;
						if (k>0) dp[i][j][k-1] = (dp[i][j][k-1] + (dp[i-1][j][k-p]*k*c[y-(k-p)][p])%mod)%mod;
					}
					else {
						if (k==y && j==x) dp[i][j][k] = (dp[i][j][k] + dp[i-1][j-t][k-p])%mod;
						dp[i][j-1][k] = (dp[i][j-1][k] + (dp[i-1][j-t][k-p]*j*(c[x-(j-t)][t]*c[y-(k-p)][p])%mod)%mod)%mod;
						if (k>0) dp[i][j][k-1] = (dp[i][j][k-1] + (dp[i-1][j-t][k-p]*k*(c[x-(j-t)][t]*c[y-(k-p)][p])%mod)%mod)%mod;
					}
				}
			}
		}
		for (int j=0; j<=x; j++) for (int k=0; k<=y; k++) cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
	}
	
	bool done = 0;
	for (int i=0; i<=50; i++) {
		if (dp[i][x][y]!=0) {
			cout<<i*2-1<<endl;
			cout<<dp[i][x][y]<<endl;
			done = 1;
			break;
		}
	}
	if (!done) cout<<-1<<endl<<0<<endl;

    return 0;

}
