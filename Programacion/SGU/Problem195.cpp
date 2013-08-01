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
vector<int> e[500010];
int dp[500010][2];

int dfs(int u, int pre, int c) {
	if (dp[u][c]>=0) return dp[u][c];
	int tot = 0;
	int sum = 0;
	
	for (int i=0; i<e[u].size(); i++) {
		int v = e[u][i];
		if (v==pre) continue;
		sum += dfs(v,u,0);
	}
	
	tot = sum;
	if (c==0) {
		for (int i=0; i<e[u].size(); i++) {
			int v = e[u][i];
			if (v==pre) continue;
			tot = max(tot, sum - dfs(v,u,0) + dfs(v,u,1));
		}
	}
	else tot++;
	
	dp[u][c] = tot;
	return tot;
}

vector<int> v;
int print(int u, int pre, int c) {
	int tot = 0;
	int sum = 0;
	
	if (c) v.push_back(u);
	
	for (int i=0; i<e[u].size(); i++) {
		int v = e[u][i];
		if (v==pre) continue;
		sum += dfs(v,u,0);
	}
	
	int p = -1;
	for (int i=0; i<e[u].size(); i++) {
		int v = e[u][i];
		if (v==pre) continue;
		if (dp[u][c]==sum - dfs(v,u,0) + dfs(v,u,1) && c==0) {
			p = v;
			break;
		}
	}
	
	for (int i=0; i<e[u].size(); i++) {
		int v = e[u][i];
		if (v==pre) continue;
		if (v==p) print(v,u,1);
		else print(v,u,0);
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=1; i<n; i++) {
		int c;
		scanf("%d",&c);
		c--;
		e[i].push_back(c);
		e[c].push_back(i);
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<2; j++) dp[i][j] = -1;
	int res = 1000*dfs(0,-1,0);
	
	cout<<res<<endl;
	print(0,-1,0);
	sort(v.begin(),v.end());
	for (int i=0; i<v.size(); i++) cout<<v[i]+1<<" ";

    return 0;

}
