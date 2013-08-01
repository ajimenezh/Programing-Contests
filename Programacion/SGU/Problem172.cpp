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

vector<int> e[201];
int n,m;
int c[201];
int vis[201];

void dfs(int u, int t) {
	vis[u] = 1;
	c[u] = t;
	if (t==1) t++;
	else t--;
	
	rep(it,e[u]) {
		if (!vis[*it]) {
			dfs(*it,t);
		}
		else {
			if (c[*it]!=t) {
				c[*it] = 0;
			}
		}
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--; b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	for (int i=0; i<n; i++) if (!vis[i]) dfs(i,1);
	
	for (int i=0; i<n; i++) if (!vis[i] || c[i]==0) {
		cout<<"no"<<endl;
		return 0;
	}
	cout<<"yes"<<endl;
	int k = 0;
	for (int i=0; i<n; i++) if (c[i]==1) k++;
	cout<<k<<endl;
	for (int i=0; i<n; i++) if (c[i]==1) cout<<(i+1)<<" ";

    return 0;

}
