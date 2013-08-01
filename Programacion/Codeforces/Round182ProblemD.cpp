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

#ifdef _WIN32
	#define printlong(x) printf("%I64d\n",x);
#else 
	#define printlong(x) printf("%lld",x);
#endif

int n;
int p[200010];
int w[200010];
int m;
vector<int> next[200010];
vector<pair<int,int> > intv[200010];
long long ans[200010];
long long v[200010];
long long v2[200010];

void update(int a, int x) {
	for (int i=a; i<=n; i += i & -i) v[i] += x;
}
void update2(int a, int x) {
	for (int i=a; i<=n; i += i & -i) v2[i] += x;
}
long long get(int a) {
	int x = 0;
	for (int i=a; i>=1; i-= i & -i) x += v[i];
	return x;
}
long long get2(int a) {
	int x = 0;
	for (int i=a; i>=1; i-= i & -i) x += v2[i];
	return x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m;
	for (int i=0; i<n; i++) scanf("%d",p+i);
	for (int i=0; i<n; i++) w[p[i]] = i;
	
	for (int i=0; i<n; i++) {
		for (int j=p[i]; j<=n; j+=p[i]) {
			int t = w[j];
			if (t>i) next[i].push_back(t);
			else next[t].push_back(i);
		}
	}
	
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		a--;
		b--;
		intv[a].push_back(make_pair(b,i));
	}
	
	int c = 0;
	for (int i=n-1; i>=0; i--) {
		for (vector<int>::iterator it = next[i].begin(); it!=next[i].end(); it++) {
			update(i+1,-1);
			update2(i+1,1);
			update(*it+1,1);
			c++;
		}
		for (vector<pair<int,int> >::iterator it = intv[i].begin(); it!=intv[i].end(); it++) {
			ans[(*it).second] = get2((*it).first+1) + get((*it).first+1);
		}
	}
	
	for (int i=0; i<m; i++) {printlong(ans[i]); printf("\n");}

    return 0;

}
