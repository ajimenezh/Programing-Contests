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
vector<vector<int> > t;
set<pair<int,int> > sm[100010];
int bad[1000010];
set<pair<int,int> > next;
int v[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	t = vector<vector<int> > (n,vector<int> (m,0));
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) scanf("%d",&t[i][j]);
	}
	
	for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (t[i][j]!=-1) sm[i].insert(make_pair(t[i][j],j));
	for (int i=0; i<n; i++) {
		int small = -1;
		if (!sm[i].empty()) small = (*sm[i].begin()).first;
		for (int j=0; j<m; j++) if (t[i][j]!=-1 && t[i][j]>small) bad[j]++;
	}
	for (int i=0; i<m; i++) next.insert(make_pair(bad[i],i));
	
	bool good = 1;
	for (int k=0; k<m; k++) {
		int now = (*next.begin()).second;
		if (bad[now]>0) {
			good = 0;
			break;
		}
		int x = now;
		v[k] = x;
		next.erase(next.begin());
		
		for (int i=0; i<n; i++) if (t[i][x]!=-1) {
			sm[i].erase(make_pair(t[i][x],x));
			if (!sm[i].empty()) {
				if ((*sm[i].begin()).first==t[i][x]) continue;
				rep(it,sm[i]) {
					int id = (*it).second;
					if ((*it).first!=(*sm[i].begin()).first) break;
					next.erase(make_pair(bad[id],id));
					bad[id]--;
					next.insert(make_pair(bad[id],id));
				}
			}
		}
	}
	
	if (!good) cout<<-1;
	else {
		for (int i=0; i<m; i++) printf("%d ",v[i]+1);
	}

    return 0;

}
