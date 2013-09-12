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

int n,w,h;
int x[1010], y[1010];
int m;
int p[1010];

bool cmp(int i, int j) {
	if (y[i]==y[j]) return x[i]<x[j];
	return y[i]<y[j];
}

set<int> s;
int h2,w2;


int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int t;
	cin>>t;
	while (t--) {
		cin>>n>>w>>h;
		m = 0;
		for (int i=0; i<n; i++) {
			int x1,y1,x2,y2;
			scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
			x[m] = x1;
			y[m++] = y1;
			x[m] = x2;
			y[m++] = y1;
			x[m] = x1;
			y[m++] = y2;
			x[m] = x2;
			y[m++] = y2;
			x[m] = (x1+x2)>>1;
			y[m++] = (y1+y2)>>1;
		}
		x[m] = 0;
		y[m++] = 0;
		x[m] = 0;
		y[m++] = h;
		x[m] = w;
		y[m++] = 0;
		x[m] = w;
		y[m++] = h;
		for (int i=0; i<m; i++) p[i] = i;
		sort(p,p+m,cmp);
		s.clear();
		int j = 2;
		cin>>w2>>h2;
		s.insert(0);
		s.insert(w);
		bool done = 0;
		for (int i=1; i<m; i++) {
			s.insert(x[p[i]]);
			while (j<m && y[p[j]]-y[p[i]]<=h2) {
				s.insert(x[p[j]]); 
				j++;
			}
			set<int>::iterator it2 = s.begin();
			it2++;
			rep(it,s) {
				if (it2==s.end()) break;
				if (*it2-*it>w2) {
					done = 1;
					cout<<*it<<" "<<y[p[i-1]]<<endl;
					break;
				}
				it2++;
			}
			if (done) break;
			s.erase(x[p[i]]);
		}
		if (!done) cout<<"Fail!"<<endl;
	}
	
    return 0;

}
