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

int n,m,y;
int x[1001];
int k[1001];
set<pair<int,int> > s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m>>y;
	for (int i=0; i<n; i++) scanf("%d",x+i);
	
	int t = m;
	for (int i=0; i<n; i++) {
		k[i] = (x[i]*m)/y;
		t -= k[i];
		s.insert(mp(-x[i]*m+k[i]*y,i));
	}
	
	while (t>0) {
		pii p = (*s.begin());
		s.erase(s.begin());
		k[p.second]++;
		p.first = -x[p.second]*m+k[p.second]*y;
		s.insert(p);
		t--;
	}
	for (int i=0; i<n; i++) cout<<k[i]<<" ";
	

    return 0;

}
