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
vector<int> e[100010];
int v[100010];
int ed[100010][2];
int l, r;
vector<int> w;
bool vis[10];

void dfs(int p, int pre) {
	w.push_back(p+1);
	vis[p] = 1;
	rep(it,e[p]) if (*it!=pre && !vis[*it]) dfs(*it,p);
}

bool solve() {
	dfs(0,-1);
	if (w.size()!=6) return 0;
	cout<<w[0]<<" "<<w[2]<<endl;
	cout<<w[0]<<" "<<w[3]<<endl;
	cout<<w[1]<<" "<<w[4]<<endl;
	cout<<w[1]<<" "<<w[5]<<endl;
	cout<<w[2]<<" "<<w[4]<<endl;
	cout<<w[3]<<" "<<w[5]<<endl;
	return 1;
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
	for (int i=0; i<n; i++) while (e[i].size()<2) e[i].push_back(-1);
	
	if (n==6 && m==6) {
		if (solve())
			return 0;
	}
	for (int i=0; i<n; i++) ed[i][0] = -1;
	for (int i=0; i<n; i++) ed[i][1] = -1;
	for (int i=0; i<n; i++) v[i] = i;
	unsigned int c = 4%n;
	for (int j=0; j<min(n,10000000/n); j++) {
		for (int i=0; i<n; i++) {
			int tmp = v[i];
			v[i] = v[c];
			v[c] = tmp;
			c *= 787;
			c %= n;
		}
	}
	
	int cur = 1;
	int tot = 0;
	for (int i=cur; i<n; i++) if (v[i]!=-1) {
		if (tot<m && e[v[0]][0]!=v[i] && e[v[0]][1]!=v[i]) {
			l = v[i];
			v[i] = -1;
			while (v[cur]==-1) cur++;
			ed[v[0]][0] = l;
			tot++;
			break;
		}
	}
	for (int i=cur; i<n; i++) if (v[i]!=-1) {
		if (tot<m && e[v[0]][0]!=v[i] && e[v[0]][1]!=v[i]) {
			r = v[i];
			v[i] = -1;
			while (v[cur]==-1) cur++;
			ed[v[0]][1] = r;
			tot++;
			break;
		}
	}
	//cout<<l<<" "<<r<<endl;
	
	while (cur<n && tot<m) {
		bool ok = 0;
		for (int i=cur; i<n; i++) if (v[i]!=-1) {
			if (tot<m && e[l][0]!=v[i] && e[l][1]!=v[i]) {
				ed[l][0] = v[i];
				l = v[i];
				v[i] = -1;
				while (v[cur]==-1) cur++;
				ok = 1;
				tot++;
				break;
			}
		}
		if (tot==m) break;
		for (int i=cur; i<n; i++) if (v[i]!=-1) {
			if (tot<m && e[r][0]!=v[i] && e[r][1]!=v[i]) {
				ed[r][0] = v[i];
				r = v[i];
				v[i] = -1;
				while (v[cur]==-1) cur++;
				ok = 1;
				tot++;
				break;
			}
		}
		if (!ok) break;
	}
	
	while (tot<m && cur!=n) {
		if (e[0][0]!=v[cur] && e[0][1]!=v[cur]) {
			if (e[ed[0][0]][0]!=v[cur] && e[ed[0][0]][1]!=v[cur]) {
				int t = ed[0][0];
				ed[0][0] = v[cur];
				ed[v[cur]][0] = t;
				tot++;
			}
			else if (e[ed[0][1]][0]!=v[cur] && e[ed[0][1]][1]!=v[cur]) {
				int t = ed[0][1];
				ed[0][1] = v[cur];
				ed[v[cur]][0] = t;
				tot++;
			}
			else {
				cout<<-1;
				return 0;
			}
		}
		else {
			cout<<-1;
			return 0;
		}
		cur++;
	}
	
	if (tot<m) {
		if (e[l][0]==r || e[l][1]==r) {
			cout<<-1;
			return 0;
		}
		else {
			ed[l][0] = r;
			tot++;
		}
	}
	
	if (tot<m) {
		cout<<-1<<endl;
		return 0;
	}
	
	for (int i=0; i<n; i++) {
		if (ed[i][0]>=0) printf("%d %d\n",i+1,ed[i][0]+1);
		if (ed[i][1]>=0) printf("%d %d\n",i+1,ed[i][1]+1);
	}

    return 0;

}
