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

int l,n,m;
int p[310];
int d[310];
vector<int> v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>l;
	cin>>m;
	for (int i=0; i<m; i++) scanf("%d",p+i);
	cin>>n;
	for (int i=1; i<n; i++) scanf("%d",d+i);
	for (int i=0; i<n; i++) v.push_back(d[i]);
	sort(v.begin(),v.end());
	l *= 2;
	for (int i=0; i<n; i++) v[i] *= 2;
	for (int i=0; i<m; i++) p[i] *= 2;
	
	int best = 0;
	int pos = 0;
	for (int i=0; i<=l; i++) {
		if (v[v.size()-1]+i>l) continue;
		int cost = 0;
		for (int k=0; k<m; k++) {
			vector<int>::iterator it = upper_bound(v.begin(),v.end(),p[k]-i);
			int t = 0;
			t = abs(i+(*it)-p[k]); 
			if (it!=v.begin()) {
				it--;
				t = min(t, abs(i+(*it)-p[k]));
			}
			cost += t;
			//cout<<k<<" "<<i<<" "<<t<<endl;
		}
		if (best<cost) {
			best = cost;
			pos = i;
		}
		//cout<<i<<" "<<cost<<endl;
	}
	
	if (pos%2==0) printf("%d ",pos/2);
	else printf("%d.%d ",pos/2,5);
	if (best%2==0) printf("%d ",best/2);
	else printf("%d.%d ",best/2,5);

    return 0;

}
