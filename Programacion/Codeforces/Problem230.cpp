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

int n,m;
vector<int> e[101];
bool vis[101];
int q[110];
vector<int> v;

bool topsort(int a) {
	int in = 0, fn = 0;
	q[fn++] = a;
	for (int i=0; i<n; i++) vis[i] = 0;
	
	while (in<fn) {
		int p = q[in++];
		v.push_back(a);
		vis[p] = 1;
		for (int i=0; i<e[p].size(); i++) {
			if (vis[e[p][i]]) return false;
			q[fn++] = e[p][i];
		}
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
		vis[b] = 1;
		e[a].push_back(b);
	}
	for (int i=0; i<n; i++) if (!vis[i]) {
		if (!topsort(i)) {
			cout<<"No solution"<<endl;
		}
	}
	
	for (int i=0; i<v.size(); i++) cout<<v[i]+1<<" ";

    return 0;

}
