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
int a[510][510];	
int q[1000000];
int lv[1010];
int match[1010];
bool used[1010];
int m;

bool dfs(int v) {
	used[v] = 1;
	for (int i=0; i<n; i++) if ((v<n&&a[v][i]<=m)||(v>=n&&a[i][v-n]<=m)) {
		if (v<n) i += n;
		int w = match[i];
		if (w==-1 || (!used[w] && lv[v]<lv[w] && dfs(w))) {
			match[i] = v;
			match[v] = i;
			return true;
		}
	}
	return false;
}

int hopcroftKarp() {
	for (int i=0; i<2*n; i++) match[i] = -1;
	for (int tot=0;;) {
		int in = 0, fn = 0;
		for (int i=0; i<2*n; i++) lv[i] = -1;
		for (int i=0; i<2*n; i++) if (match[i]==-1) {
			lv[i] = 0;
			q[fn++] = i;
		}
		while (in<fn) {
			int v = q[in++];
			for (int i=0; i<n; i++) if ((v<n&&a[v][i]<=m)||(v>=n&&a[i][v-n]<=m)) {
				if (v<n) i += n;
				int w = match[i];
				if (w!=-1 && lv[w]<0) {
					lv[w] = lv[v] + 1;
					q[fn++] = w;
				}
			}
		}
		for (int i=0; i<2*n; i++) used[i] = 0;
		int d = 0;
		for (int i=0; i<2*n; i++) if (!used[i] && match[i]==-1 && dfs(i)) d++;
		if (d==0) return tot;
		tot += d;
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;

	for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d",&a[i][j]);
	
	int lo = -1000000;
	int hi = 1000000;
	while (lo+1<hi) {
		m = (lo+hi)/2; 
		
		if (hopcroftKarp()==n) {
			hi = m-1;
		}
		else lo = m;
	}
	
	m = lo;
	while (hopcroftKarp()<n) m = ++lo;
	hopcroftKarp();
	
	cout<<lo<<endl;
	
	for (int i=0; i<n; i++) cout<<i+1<<" "<<match[i]+1-n<<endl;

    return 0;

}

