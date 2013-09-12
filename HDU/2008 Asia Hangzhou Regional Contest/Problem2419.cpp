#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <stdio.h>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 20010
#define MAXM 60010
#define MAXQ 300010

const double eps = 1.0e-8;

int n,m,q;
pair<int,int> e[MAXM];
set<pair<int,int> > forb;
multiset<int> cnt[MAXN];
int par[MAXN];
int rank[MAXN];
int x[MAXN];
pair<int,pair<int,int> > queries[MAXQ];

int get(int a) {
	int p = a, tmp;
	while (p!=par[p]) p = par[p];
	while (a!=p) {
		tmp = par[a];
		par[a] = p;
		a = tmp;
	}
	return p;
}

void merge(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return;
	if (rank[a]<rank[b]) {
		par[a] = b;
		rep(it,cnt[a]) {
			cnt[b].insert(*it);
		}
		cnt[a].clear();
		rank[b] += rank[a];
	}
	else {
		par[b] = a;
		rep(it,cnt[b]) {
			cnt[a].insert(*it);
		}
		cnt[b].clear();
		rank[a] += rank[b];
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int tt = 1;
	
	while (scanf("%d%d%d",&n,&m,&q)!=EOF) {
		for (int i=0; i<n; i++) scanf("%d",x+i);
		for (int i=0; i<n; i++) cnt[i].clear();
		for (int i=0; i<n; i++) par[i] = i;
		for (int i=0; i<n; i++) rank[i] = 0;
		forb.clear();
		for (int i=0; i<m; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			a--; b--;
			e[i] = make_pair(min(a,b),max(a,b));
		}
		for (int i=0; i<q; i++) {
			char c;
			scanf("%s",&c);
			if (c=='F') {
				int a,b;
				scanf("%d%d",&a,&b);
				a--;
				queries[i] = make_pair(1,make_pair(a,b));
			}
			else if (c=='U') {
				int a,b;
				scanf("%d%d",&a,&b);
				a--;
				int tmp = x[a];
				x[a] = b;
				queries[i] = make_pair(2,make_pair(a,tmp));
			}
			else {
				int a,b;
				scanf("%d%d",&a,&b);
				a--; b--;
				queries[i] = make_pair(3,make_pair(a,b));
				forb.insert(make_pair(min(a,b),max(a,b)));
			}
		}

		long long sum = 0;
		int tot = 0;
		
		for (int i=0; i<n; i++) {
			cnt[i].insert(x[i]);
		}
		
		for (int i=0; i<m; i++) {
			if (forb.find(e[i])==forb.end()) merge(e[i].first,e[i].second);
		}
		forb.clear();
		
		multiset<int>::iterator it;
		for (int i=q-1; i>=0; i--) {
			if (queries[i].first==1) {
				int p = get(queries[i].second.first);
				int k = queries[i].second.second;
				it = cnt[p].lower_bound(k);
				if (it!=cnt[p].end()) sum += (*it);
				tot++;
			}
			else if (queries[i].first==2) {
				int p = get(queries[i].second.first);
				int k = queries[i].second.second;
				
				 it = cnt[p].find(x[queries[i].second.first]);
				cnt[p].erase(it);
				cnt[p].insert(k);
				
				x[queries[i].second.first] = k;
			}
			else {
				merge(queries[i].second.first,queries[i].second.second);
			}
		}
		
		printf("Case %d: %.3lf\n",tt++, (double)sum/tot + eps);
	}

    return 0;

}
