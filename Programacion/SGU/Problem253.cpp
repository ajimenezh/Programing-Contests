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

const Double eps = 1.0e-16;
const Double pi = acosl(-1.0);

struct Point{
	Double x,y;
	Point() {}
	Point(Double x, Double y) : x(x), y(y) {}
};

int n,m,k;
Point p[100010];
Point q[100010];
int id[100010];
Point O;

Point operator-(Point a, Point b) {
	return Point(a.x-b.x,a.y-b.y);
}

Point operator/(Point a, Double b) {
	return Point(a.x/b,a.y/b);
}

Double operator*(Point a, Point b) {
	return a.x*b.x + a.y*b.y;
}

bool operator==(Point a, Point b) {
	return abs(a.x-b.x)<eps && abs(a.y-b.y)<eps;
}

Double mod(Point a) {
	return sqrtl(a.x*a.x + a.y*a.y);
}

Double vect(Point a, Point b) {
	return a.x*b.y - a.y*b.x;
}

Double ang(Point a, Point b, Point c) {
	if (a==b || c==b) return 0;
	Double ans = (a-b)*(c-b);
	ans /= mod(a-b)*mod(c-b);
	ans = acosl(ans);
	if (vect(a-b,c-b)<-eps) {
		ans = 2.0*pi - ans;
	}
	return ans;
}

bool cmp(int i, int j) {
	if (q[i]==O) return 1;
	if (q[j]==O) return 0;
	return ang(p[0],O,q[i]) < ang(p[0],O,q[j]);
}

Double mabs(Double a) {
	if (a<0.0) return -a;
	return a;
}

Double area(Point B, Point A, Point C) {
	return mabs(vect(B-A,C-A))/2.0;
}

bool inside(Point P, Point B, Point A, Point C) {
	if (area(B,A,P)+area(P,A,C) + area(B,P,C) > area(B,A,C) + eps) return false;
	return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n>>m>>k;
	for (int i=0; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		p[i] = Point(a,b);
	}
	
	O = (p[n/2+1]-p[0])/2.0;
	
	
	for (int i=0; i<m; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		q[i] = Point(a,b);
		id[i] = i;
	}
	
	sort(id,id+m,cmp);
	
	int t = 0;
	int tot = 0;
	for (int i=0; i<m; i++) {
		if (q[id[i]]==p[0] || q[id[i]]==O) {
			tot++;
			continue;
		}
		//cout<<i<<" "<<ang(p[0],O,q[id[i]])<<endl;
		while (t<n-1 && ang(p[0],O,q[id[i]])>ang(p[0],O,p[(t+1)%n])) t = (t+1)%n; 
		
		if (inside(q[id[i]],p[t],O,p[(t+1)%n])) tot++;
	}
	
	if (tot>=k) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;

    return 0;

}
