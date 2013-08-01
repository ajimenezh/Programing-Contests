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

int a[100010];
pair<int,int> v[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int n,h;
	cin>>n>>h;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	for (int i=0; i<n; i++) v[i] = make_pair(a[i],i);
	sort(v,v+n);
	
	int p = (v[n-1].first+v[n-2].first - (v[1].first+v[0].first));
	
	int m1 = 1000000000;
	if (n>2) m1 = min(v[1].first+v[0].first+h,v[1].first+v[2].first);
	else m1 = v[1].first+v[0].first+h;
	
	int m2 = 0;
	if (n>2) m2 = max(v[n-1].first+v[0].first+h,v[n-1].first+v[n-2].first);
	else m2 = v[n-1].first+v[0].first+h;
	
	//cout<<m1<<" "<<m2<<" "<<p<<" "<<m2-m1<<endl;
	
	if (m2-m1<p) {
		cout<<m2-m1<<endl;
		for (int i=0; i<n; i++) {
			if (i==v[0].second) printf("1 ");
			else printf("2 ");
		}
	}
	else {
		cout<<p<<endl;
		for (int i=0; i<n; i++) printf("1 ");
	}
	
	

    return 0;

}
