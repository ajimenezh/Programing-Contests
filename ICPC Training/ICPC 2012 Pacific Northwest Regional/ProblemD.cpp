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

const double eps = 1.0e-8;

typedef long long ll;

struct point{
	ll ox,oy;
	ll x,y;
	bool neg;
	point(int x=0, int y=0):ox(x),oy(y){}
};

int n,w,h;
point v[50010];
int p[50010];

double ang(point a) {
	double alp = (double)a.x/(sqrtl(a.x*a.x + a.y*a.y));
	
	if (a.y<0) alp = 2.0*acosl(-1.0) - alp;
	
	if (abs(alp)<eps) alp = eps;
	
	return alp;
}

bool cmp(int i, int j) {
	return v[i].x*v[j].y - v[i].y*v[j].x > 0;
}

void print(int i, int j) {
	for (int k=i; k<=j; k++) {
		cout<<v[p[k]].x<<" "<<v[p[k]].y<<endl;
	}
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (scanf("%d%d%d",&n,&w,&h) && n!=0) {
		
		int neg = 0;
		for (int i=0; i<n; i++) {
			int a,b;
			scanf("%d%d",&a,&b);
			v[i] = point(a,b);
			v[i].x = 2*a - w;
			v[i].y = 2*b - h;
			v[i].neg = 0;
			if (v[i].y<0 || (v[i].y==0 && v[i].x<0)) {
				v[i].y = -v[i].y;
				v[i].x = -v[i].x;
				v[i].neg = 1;
			}
			neg += v[i].neg;
		}
		
		for (int i=0; i<n; i++) p[i] = i;
		sort(p,p+n,cmp);
		
		int i;
		for (i=0; i<n && 2*neg!=n; i++) {
			if (v[i].neg) neg--;
			else neg++;
		}
		
		for (int j=0; j<i; j++) {
			if (v[j].neg) {
				cout<<v[j].ox<<" "<<v[j].oy<<endl;
			}
		}
		for (; i<n; i++) {
			if (!v[i].neg) {
				cout<<v[i].ox<<" "<<v[i].oy<<endl;
			}
		}
	}
	
    return 0;

}
