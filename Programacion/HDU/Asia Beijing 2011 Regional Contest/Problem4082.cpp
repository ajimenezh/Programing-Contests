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

const Double eps = 1.0e-12;

int n;
int x[20];
int y[20];

struct triangle {
	Double a, b, c;
	triangle() {}
	triangle(Double p, Double r, Double s) {
		vector<Double> v;
		v.push_back((r*r+s*s-p*p)/(2.0*r*s));
		v.push_back((r*r-s*s+p*p)/(2.0*r*p));
		v.push_back((-r*r+s*s+p*p)/(2.0*p*s));
		sort(v.begin(),v.end());
		a = v[0]; b = v[1]; c = v[2];
	}
};

bool operator<(const triangle t,const triangle p) {
	if (abs(t.a-p.a)<eps) return t.b<p.b;
	return t.a<p.a;
}

bool operator==(triangle &t, triangle &p) {
	return abs(t.a-p.a)<eps && abs(t.b-p.b)<eps;
}

map<triangle,int> all;
vector<triangle> v;
set<pair<int,int> > sp;

Double sqr(int a) {
	return (Double)a*a;
}

Double dist(int i, int j) {
	return sqrtl(sqr(x[i]-x[j])+sqr(y[i]-y[j]));
}

int vect(int i, int j, int k) {
	int vx1 = x[j]-x[i];
	int vy1 = y[j]-y[i];
	int vx2 = x[k]-x[i];
	int vy2 = y[k]-y[i];
	
	return vx1*vy2 - vx2*vy1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>n && n!=0) {
		for (int i=0; i<n; i++) {
			scanf("%d%d",x+i,y+i);
			if (sp.find(make_pair(x[i],y[i]))!=sp.end()) {
				i--; n--;
			}
			else sp.insert(make_pair(x[i],y[i]));
		}
		
		all.clear();
		v.clear();
		sp.clear();
		
		for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++) {
			
			if (vect(i,j,k)==0) continue;
			
			Double a = dist(i,j);
			Double b = dist(j,k);
			Double c = dist(k,i);
			
			triangle t = triangle(a,b,c);
			
			//cout<<a<<" "<<b<<" "<<c<<endl;cout<<i<<" "<<j<<" "<<k<<endl;
			
			if (all.find(t)==all.end()) all[t] = 1;
			else all[t]++;
			
			v.push_back(t);
		}
		
		int ans = 0;
		
		for (int i=0; i<v.size(); i++) {
			int tmp = 1;
			for (int j=i+1; j<v.size(); j++) {
				if (v[i]==v[j]) tmp++;
			}
			ans = max(tmp,ans);
		}
		
		cout<<ans<<endl;
	}

    return 0;

}
