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
int a[100010];
vector<int> e[100010];
vector<int> c[100010];

long long dp[100010][2];

long long dfs(int u, int v, bool done) {
	if (dp[u][done]) return dp[u][done];
	
	long long tmp = 0;
	
	long long sum = 0;
	
	for (int i=0; i<e[u].size(); i++) {
		int p = e[u][i];
		if (p==v) continue;
		sum += dfs(p,u,1) + (long long)c[u][i]*2LL;
	}
	tmp = sum;
	if (done) {
		dp[u][done] = tmp;
		return tmp;
	}
	
	tmp += a[u];
	
	for (int i=0; i<e[u].size(); i++) {
		int p = e[u][i];
		if (p==v) continue;
		tmp = min(tmp, sum - dfs(p,u,1) - (long long)c[u][i] + dfs(p,u,0));
	}
	
	dp[u][done] = tmp;
	return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	n++;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n-1; i++) {
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		e[x].push_back(y);
		e[y].push_back(x);
		c[x].push_back(w);
		c[y].push_back(w);
	}
	
	cout<<dfs(0,-1,0);


    return 0;

}
