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
vector<int> e[16010];
int w[16010];
int d[16010];
int ans;

void dfs(int u, int v) {
	d[u] = w[u];
	
	rep(it,e[u]) {
		int p = *it;
		if (p==v) continue;
		
		dfs(p,u);
		if (d[p]>0) d[u] += d[p];
	}
	ans = max(ans,d[u]);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",w+i);
	for (int i=0; i<n-1; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	ans = -1000000000;
	dfs(0,-1);
	
	cout<<ans<<endl;

    return 0;

}
