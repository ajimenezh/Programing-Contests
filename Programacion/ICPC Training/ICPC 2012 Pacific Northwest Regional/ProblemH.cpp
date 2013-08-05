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

map<string,int> id;
int n;
int p[100010];

int v[100010];

int get(int x) {
	int s = 0;
	for (int i=x; i>=1; i -= i & -i) s += v[i];
	return s;
}

void update(int x) {
	for (int i=x; i<=n; i += i & -i) v[i] += 1;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d",&n) && n!=0) {
		id.clear();
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			id[s] = i+1;
		}
		for (int i=0; i<n; i++) {
			string s;
			cin>>s;
			p[i] = id[s];
		}
		
		for (int i=1; i<=n; i++) v[i] = 0;
		
		long long t = 0;
		for (int i=0; i<n; i++) {
			t += i - get(p[i]);
			update(p[i]);
		}
		
		cout<<t<<endl;
	}
	
    return 0;

}
