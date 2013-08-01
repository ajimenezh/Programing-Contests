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

typedef long double Double;
typedef long long ll;

const Double eps = 1.0e-12;

struct point{
	ll x,y;
	point() {}
	point(int x, int y) : x(x),y(y) {}
};

point operator+(point &a, point &b) {
	point c(a.x+b.x,a.y+b.y);
	return c;
}

point operator-(point &a, point &b) {
	point c(a.x-b.x,a.y-b.y);
	return c;
}

ll operator*(point &a, point &b) {
	return a.x*b.x + a.y*b.y;
}


int n,m;
point a[100010];
point b[20010];
int p[20010];

ll vect(point v, point u) {
	return v.x*u.y - v.y*u.x;
}

ll absf(ll x) {
	if (x<0) return -x;
	return x;
}

ll area(point x, point y, point w) {
	return absf(vect(y-x,w-x));
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int x,y;
		scanf("%I64d%I64d",&x,&y);
		a[i] = point(x,y);
	}
			
	cin>>m;
	for (int i=0; i<m; i++) {
		int x,y;
		scanf("%I64d%I64d",&x,&y);
		b[i] = point(x,y);
	}
	for (int i=0; i<m; i++) {
		if (area(a[0],a[1],b[i])==0) {
			cout<<"NO"<<endl;
			return 0;
		}
		if (area(a[0],a[n-1],b[i])==0) {
			cout<<"NO"<<endl;
			return 0;
		}
	}

	bool bad = 0;
	for (int t=0; t<m; t++) {
		int lo = 1;
		int hi = n-1;
		while (lo<hi-1) {
			int mi = (lo+hi)/2;
			if (vect(a[mi]-a[0],b[t]-a[0])>=0) {
				hi = mi-1;
			}
			else lo = mi;
		}
		while (lo<n-1 && vect(a[lo+1]-a[0],b[t]-a[0])<0) lo++;
		if (lo==n-1 || (lo==1 && vect(a[1]-a[0],b[t]-a[0])>=0)) {
			bad = 1;
			break;
		}
		else {
			if (area(a[lo],a[lo+1],b[t])==0 || area(a[0],a[lo],a[lo+1])!=area(a[0],a[lo],b[t])+area(a[0],a[lo+1],b[t])+area(a[lo],a[lo+1],b[t])) {
				bad = 1;
				break;
			}
		}
	}
	
	if (bad) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

    return 0;

}
