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

#define MAXN 110

int state[MAXN];
int us[MAXN];
int n, m;
int N;
vector<int> e[MAXN];
bool vis[MAXN];
int box[MAXN];

bool dfs(int p) {
    state[p] = 1;
    for (int i=0; i<e[p].size(); i++) {
        if (state[e[p][i]]==1 || (state[e[p][i]]==0 && !dfs(e[p][i]))) return false;
    }
    vis[p] = 1;
    us[--N] = p;
    state[p] = 2;
    return true;
}

bool topologicalSort() {
    N = n;
    for (int i=0; i<n; i++) if (!vis[i]) {
        if (!dfs(i)) return false;
    }
    return true;
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
	}
	
	if (!topologicalSort()) {
		cout<<"No solution"<<endl;
	}
	else {
		for (int i=0; i<n; i++) box[us[i]] = i+1;
		for (int i=0; i<n; i++) cout<<box[i]<<" ";
	}

    return 0;

}
