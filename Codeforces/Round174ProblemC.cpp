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

int n,m,t;
int a[301];
int s[301];
int cnt;
int sum[301];
vector<int> e[301];
vector<int> r[301];
bool vis[301];
bool bad;
int ind[301];

void dfs(int p, int c) {
	vis[p] = 1;
	s[c] = a[p];
	cnt++;
	for (int i=0; i<(int)e[p].size(); i++) {
		if (vis[e[p][i]]) bad = 1;
		else dfs(e[p][i],c+1);
	}
} 

long long dp[2][100010][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m>>t;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<m; i++) {
		int a,b;
		cin>>a>>b;
		a--;b--;
		r[a].push_back(b);
		e[b].push_back(a);
	}
	
	int now = 0;
	for (int i=0; i<n; i++) if (!vis[i] && r[i].size()==0) {
		dfs(i,cnt);
		if (bad) {
			cout<<0<<endl;
			return 0;
		}
		ind[now] = 2;
		if (cnt>now+1) ind[now+1] = 1;
		for (int j=now; j<cnt; j++) {
			for (int k=j; k<cnt; k++) sum[j] += s[k]*(k-j+1);
		}
		for (int j=now; j<cnt; j++) cout<<sum[j]<<" "; cout<<endl;
		//for (int j=now; j<cnt; j++) cout<<s[j]<<" "; cout<<endl;
		now = cnt;
	}
	for (int i=0; i<n; i++) if (!vis[i]) {
		cout<<0<<endl;
		return 0;
	}
	
	dp[0][t][0] = 1;
	for (int i=1; i<=cnt; i++) {
		int y = i%2;
		int x = 1-i%2;
		for (int j=t; j>=0; j--) {
			dp[y][j][0] = 0;
			dp[y][j][1] = 0;
			if (ind[i-1]==2) {
				if (j+sum[i-1]<=t) dp[y][j][1] = (dp[y][j][1] + dp[y][j+sum[i-1]][1])%mod;
				if (j+sum[i-1]<=t) dp[y][j][1] = (dp[y][j][1] + dp[y][j+sum[i-1]][0])%mod;
				dp[y][j][0] = (dp[y][j][0] + dp[x][j][1])%mod;
				dp[y][j][0] = (dp[y][j][0] + dp[x][j][0])%mod;
			}
			else {
				if (ind[i-1]==1) {
					if (j+sum[i-1]<=t) dp[y][j][1] = (dp[y][j][1] + dp[y][j+sum[i-1]][1])%mod;
					if (j+sum[i-1]<=t) dp[y][j][1] = (dp[y][j][1] + dp[y][j+sum[i-1]][0])%mod;
					dp[y][j][0] = (dp[y][j][0] + dp[x][j][0])%mod;
					dp[y][j][1] = (dp[y][j][1] + dp[x][j][1])%mod;
				}
				else {
					if (j+sum[i-1]<=t) dp[y][j][1] = (dp[y][j][1] + dp[y][j+sum[i-1]][1])%mod;
					dp[y][j][1] = (dp[y][j][1] + dp[x][j][1])%mod;
					dp[y][j][0] = (dp[y][j][0] + dp[x][j][0])%mod;
				}
			}
			cout<<i<<" "<<j<<" "<<dp[y][j][0]<<" "<<dp[y][j][1]<<" "<<ind[i-1]<<endl;
		}
	}
	
	cout<<(dp[cnt%2][0][1]+dp[cnt%2][0][0])%mod<<endl;
	

    return 0;

}
