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
int par[200100];
int rank[200100];
int s[200100];
map<string,int> id;
int c;

int get(int a) {
	if (a==par[a]) return a;
	par[a] = get(par[a]);
	return par[a];
}

void _union(int a,int b) {
	a = get(a);
	b = get(b);
	if (a==b) return;
	if (rank[a]>rank[b]) {
		par[a] = b;
		s[b] += s[a];
		rank[b]++;
	}
	else {
		par[b] = a;
		s[a] += s[b];
		rank[a]++;
	}
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while (t--) {
		cin>>n;
		for (int i=0; i<2*n; i++) par[i] = i;
		for (int i=0; i<2*n; i++) s[i] = 1;
		for (int i=0; i<2*n; i++) rank[i] = 0;
		c = 0;
		id.clear();
		for (int i=0; i<n; i++) {
			string s1,s2;
			cin>>s1>>s2;
			int k1,k2;
			if (id.find(s1)==id.end()) {
				id[s1] = c++;
			}
			if (id.find(s2)==id.end()) {
				id[s2] = c++;
			}
			k1 = id[s1];
			k2 = id[s2];
			_union(k1,k2);
			printf("%d\n",s[get(k1)]);
		}
	}

    return 0;

}
