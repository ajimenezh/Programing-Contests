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

const Double eps = 1.0e-8;

struct point{
	Double x,y;
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

Double operator*(point &a, point &b) {
	return a.x*b.x + a.y*b.y;
}

Double mod(point &a) {
	return sqrtl(a.x*a.x + a.y*a.y);
}

int n,m;
point a[100010];
point b[20010];
int p[20010];

Double vect(point v, point u) {
	return v.x*u.y - v.y*u.x;
}

Double absf(Double x) {
	if (x<0.0) return -x;
	return x;
}

Double area(point x, point y, point w) {
	return absf(vect(y-x,w-x));
}

Double ang(point v, point u) {
	Double alp;
	if (absf(u.x-v.x)<eps && absf(u.y-v.y)<eps) alp = 0.0;
	else alp = acosl(u*v/(mod(u)*mod(v)));
	if (vect(v,u)<0.0) alp = 2.0*acosl(-1.0)-alp;
	return alp;
} 

bool cmp(int i, int j) {
	return ang(b[i]-a[0],a[1]-a[0])<ang(b[j]-a[0],a[1]-a[0]);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%d",&n);
	for (int i=0; i<n; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		a[i] = point(x,y);
	}
			
	cin>>m;
	for (int i=0; i<m; i++) {
		int x,y;
		scanf("%d%d",&x,&y);
		b[i] = point(x,y);
	}
	for (int i=0; i<m; i++) {
		if (area(a[0],a[1],b[i])<eps) {
			cout<<"NO"<<endl;
			return 0;
		}
		if (area(a[0],a[n-1],b[i])<eps) {
			cout<<"NO"<<endl;
			return 0;
		}
	}
	for (int i=0; i<m; i++) p[i] = i;
	sort(p,p+m,cmp);
	
	int i=1;
	int j = (i+1)%n;
	bool bad = 0;
	for (int t=0; t<m; t++) {
		int k = p[t];
		while (ang(b[k]-a[0],a[1]-a[0])>ang(a[j]-a[0],a[1]-a[0])+eps) {
			i++;
			j = (i+1)%n;
			if (j==0) {
				bad = 1;
				break;
			}
		}
		if (j==0) break;
		
		//cout<<i<<" "<<j<<endl;
		//cout<<b[k].x<<" "<<b[k].y<<" "<<ang(b[k]-a[0],a[1]-a[0])<<endl;
		//cout<<ang(a[j]-a[0],a[1]-a[0])<<" "<<ang(a[i]-a[0],a[1]-a[0])<<endl;
		
		if (absf(area(a[0],b[k],a[i])+area(a[0],a[j],b[k])+area(a[i],a[j],b[k])-area(a[0],a[i],a[j]))>eps || absf(area(b[k],a[i],a[j]))<eps) {
			bad = 1;
			//cout<<area(a[0],b[k],a[i])+area(a[0],a[j],b[k])+area(a[i],a[j],b[k])<<" "<<area(a[0],a[i],a[j])<<endl;
			break;
		}
	}
	
	if (bad) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;

    return 0;

}
