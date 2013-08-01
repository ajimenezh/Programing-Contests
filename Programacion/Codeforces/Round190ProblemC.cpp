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

vector<pair<int,int> > e[100010];
bool good[100010];
map<pair<int,int>, int> id;
int si[100010];
int n;
char l[100010];
int pre[100010];
int k;
int vis[100010];
int loc[100010];
vector<int> now;

int dfs(int p, int q, int t) {
	now.push_back(p);
	pre[p] = q;
	si[p] = 1;
	vis[p] = t;
	loc[p] = 0;
	for (int i=0; i<(int)e[p].size(); i++) {
		if (e[p][i].first==q) continue;
		if (!good[e[p][i].second]) continue;
		si[p] += dfs(e[p][i].first,p,t);
		loc[p] = max(si[e[p][i].first],loc[p]);
	}

	return si[p];
}

void solve(int r,char c) {
	if (l[r]!=0) return;
	
	now.clear();
	int tot = dfs(r,-1,++k); //cout<<r<<" "<<tot<<endl;
	
	if (tot==1) {
		l[r] = c;
		return;
	}
	if (tot==2) {
		l[r] = c;
		for (int j=0; j<(int)e[r].size(); j++) {
			if (!good[e[r][j].second]) continue;
			l[e[r][j].first] = c+1;
			break;
		}
		return;
	}
	
	int t = -1;
	int best = 10000000;
	for (int j=0; j<(int)now.size(); j++) {
		int i = now[j];
		loc[i] = max(loc[i],tot-si[i]);
		if (loc[i]<best) {
			t = i;
			best = loc[i];
		}
	}
	
	l[t] = c;
	
	//cout<<t<<" "<<pre[t]<<endl;
	
	if (pre[t]!=-1) good[id[make_pair(t,pre[t])]] = 0;
	if (pre[t]!=-1) solve(pre[t],c+1);
	
	for (int j=0; j<(int)e[t].size(); j++) {
		if (!good[e[t][j].second]) continue;
		if (e[t][j].first==pre[t]) continue;
		good[e[t][j].second] = 0;
		solve(e[t][j].first,c+1);
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
		e[a].push_back(make_pair(b,i));
		e[b].push_back(make_pair(a,i));
		id[make_pair(a,b)] = i;
		id[make_pair(b,a)] = i;
		good[i] = 1;
	}
	
	solve(0,'A');
	
	for (int i=0; i<n; i++) printf("%c ",l[i]);

    return 0;

}
