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
vector<int> e[100010];
double res;

void dfs(int p, int q, int t) {
	res += 1.0 / (double)t;
	for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) dfs(e[p][i],p,t+1);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n-1; i++) {
		int a,b;
		cin>>a>>b;
		a--;b--;
		e[a].push_back(b);
		e[b].push_back(a);
	}
	
	dfs(0,-1,1);
	
	printf("%.12f",res);

    return 0;

}
