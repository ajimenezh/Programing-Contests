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

map<pair<int,int>, int> to;
int par[200010];
int si[200010];
int n;
int t;
bool done;

int get(int a) {
	if (a==par[a]) return a;
	par[a] = get(par[a]);
	return par[a];
}

bool connect(int a, int b) {
	a = get(a);
	b = get(b);
	if (a==b) return false;
	if (si[a]>si[b]) {
		par[a] = b;
		si[b]++;
	}
	else {
		par[b] = a;
		si[a]++;
	}
	return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
	
	cin>>n;
	for (int i=0; i<n; i++) par[i] = i;
	for (int i=0; i<n; i++) {
		int x,y,x2,y2;
		scanf("%d%d%d%d",&x,&y,&x2,&y2); 
		if (abs(x2-x)+abs(y2-y)==0) {
			if (!done) {
				done = 1;
				t = i+1;
			}
		}
		if (!done) {
			
			if (to.find(make_pair(x,y))==to.end()) to[make_pair(x,y)] = i;
			if (to.find(make_pair(x2,y2))==to.end()) to[make_pair(x2,y2)] = i;
			
			int p = to[make_pair(x,y)];
			connect(p,i);

			p = to[make_pair(x2,y2)];
			if (p!=i) {
				if (!connect(p,i)) {
					t = i+1;
					done = 1;
					break;
				}
			}
		}
	}
	
	cout<<t<<endl;

    return 0;

}
