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

set<pair<int,int> > s;

vector<int> e[5010];
int n;
int si[5010];

int dfs(int u, int v) {
	si[u] = 1;
	for (int i=0; i<(int)e[u].size(); i++) {
		int x = e[u][i];
		if (x==v) continue;
		si[u] += dfs(x,u);
	}
	return si[u];
}

int dp[5001][5001];

void solve(int u, int q) {
	vector<int> v;
	if (q!=-1) v.push_back(si[0]-si[u]);
	for (int i=0; i<(int)e[u].size(); i++) {
		int x = e[u][i];
		if (x==q) continue;
		v.push_back(si[x]);
	}
	
	dp[0][0] = 1;
	for (int i=0; i<(int)v.size(); i++) {
		for (int j=0; j<n; j++) dp[i+1][j] = 0;
		for (int j=0; j+v[i]<n; j++) dp[i+1][j+v[i]] |= dp[i][j];
		for (int j=0; j<n; j++) dp[i+1][j] |= dp[i][j];
	}
	
	for (int i=1; i<n-1; i++) if (v.size()>1 && dp[(int)v.size()][i]) {
		s.insert(make_pair(i,n-1-i));
		s.insert(make_pair(n-1-i,i));
	}
	v.clear();
	for (int i=0; i<(int)e[u].size(); i++) {
		int x = e[u][i];
		if (x==q) continue;
		solve(x,u);
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	dfs(0,-1);
	solve(0,-1);
	
	cout<<s.size()<<endl;
	
	rep(it,s) cout<<(*it).first<<" "<<(*it).second<<endl;

    return 0;

}
