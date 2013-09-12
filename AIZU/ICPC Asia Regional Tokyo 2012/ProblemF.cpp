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
int par[100010];
long long w[100010];

int get(int a) {
	if (a==par[a]) return a;
	int p = par[a];
	p = get(p);
	w[a] += w[par[a]];
	par[a] = p;
	return par[a];
}

void connect(int a, int b, int c) {
	int i = get(a);
	int j = get(b);
	par[i] = j;
	w[i] = -(w[a] - c - w[b]);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d",&n,&m) && n!=0) {
		for (int i=0; i<n; i++) par[i] = i;
		for (int i=0; i<n; i++) w[i] = 0;
		
		for (int i=0; i<m; i++) {
			char c[5];
			scanf("%s",c);
			if (c[0]=='!') {
				int a,b,d;
				scanf("%d%d%d",&a,&b,&d);
				a--; b--;
				if (get(a)==get(b)) continue;
				connect(a,b,d);
			}
			else {
				int a,b;
				scanf("%d%d",&a,&b);
				a--; b--;
				if (get(a)!=get(b)) {
					printf("UNKNOWN\n");
				}
				else {
					printf("%lld\n",w[a]-w[b]);
				}
			}
		}
	}
	
    return 0;

}
