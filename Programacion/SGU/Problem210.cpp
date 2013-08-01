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
int p[410];
int w[410];
bool ady[401][401];

bool cmp(int i, int j) {
	return w[i]>w[j];
}

int match[410];
bool vis[410];
int ans[410];

bool dfs(int i) {
	if (vis[i]) return false;
	vis[i] = 1;
	for (int j=0; j<n; j++) if (ady[i][j]) {
		if (!match[j] || dfs(match[j]-1)) {
			match[j] = i+1;
			return true;
		}
	}
	return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) {
		scanf("%d",w+i);
	}
	for (int i=0; i<n; i++) {
		int k;
		scanf("%d",&k);
		while (k--) {
			int b; scanf("%d",&b);
			b--;
			ady[i][b] = 1;
		}
	}
	for (int i=0; i<n; i++) p[i] = i;
	sort(p,p+n,cmp);
	for (int i=0; i<n; i++) {
		if (dfs(p[i])) {
			for (int j=0; j<n; j++) vis[j] = 0;
		}
	}
	
	for (int i=0; i<n; i++) if (match[i]) ans[match[i]-1] = i+1;
	
	for (int i=0; i<n; i++) cout<<ans[i]<<" ";
			

    return 0;

}
