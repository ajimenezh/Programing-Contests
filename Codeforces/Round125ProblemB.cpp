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

struct circle{
	int x,y;
	int r;
	circle() {}
	circle(int x, int y, int r) : x(x), y(y), r(r) {}
};

int dist(int x, int y) {
	return x*x + y*y;
}

bool intersect(circle &a, circle &b) {
	int d = dist(a.x-b.x, a.y-b.y);
	
	if (d>=a.r*a.r + b.r*b.r + 2*a.r*b.r) return false;
	if (d<=a.r*a.r + b.r*b.r - 2*a.r*b.r) return false;
	return true;
}

circle e1,i1,e2,i2;

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int x,y,r;
	cin>>x>>y;
	cin>>r;
	e1 = circle(x,y,r);
	cin>>r;
	i1 = circle(x,y,r);
	cin>>x>>y;
	cin>>r;
	e2 = circle(x,y,r);
	cin>>r;
	i2 = circle(x,y,r);
	
	int ans = 0;
	if (!intersect(e1,e2) && !intersect(e1,i2)) ans++;
	if (!intersect(i1,e2) && !intersect(i1,i2)) ans++;
	if (!intersect(e2,e1) && !intersect(e2,i1)) ans++;
	if (!intersect(i2,e1) && !intersect(i2,i1)) ans++;
	
	cout<<ans<<endl;

    return 0;

}
