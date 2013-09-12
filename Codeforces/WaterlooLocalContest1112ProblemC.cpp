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

double x[210],y[210];
int n;
const double eps = 1.0e-10;

double sqr(double a) {
	return a*a;
}

double dist(double a, double b, double c, double d) {
	return sqrt(sqr(a-c)+sqr(b-d));
}

bool cmp(int i, int j) {
	return y[i]<y[j];
}

double tmp[210];
int p[210];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	while (cin>>x[n]>>y[n]) n++;
	
	int ans = 1;
	
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
		double xm = (x[i] + x[j])/2.0;
		double ym = (y[i] + y[j])/2.0;
		
		int t = 0;
		for (int k=0; k<n; k++) {
			if (dist(x[k],y[k],xm,ym)<2.5+eps) t++;
		}
		ans = max(ans,t);
	}
	
	for (int i=0; i<n; i++) p[i] = i;
	
	sort(p,p+n,cmp);
	
	for (int i=0; i<n; i++) tmp[i] = x[i];
	for (int i=0; i<n; i++) x[i] = tmp[p[i]];
	
	for (int i=0; i<n; i++) tmp[i] = y[i];
	for (int i=0; i<n; i++) y[i] = tmp[p[i]];	
	
	int l = 0;
	int h = n;
	
	for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
		for (int k=j+1; k<n; k++) {
			double d = 2*(x[i]*(y[j]-y[k])+x[j]*(y[k]-y[i]) + x[k]*(y[i]-y[j]));
			
			if (abs(d)<eps) continue;
			
			double x0 = ((sqr(x[i])+sqr(y[i]))*(y[j]-y[k])+(sqr(x[j])+sqr(y[j]))*(y[k]-y[i])+(sqr(x[k])+sqr(y[k]))*(y[i]-y[j]))/d;
			double y0 = -((sqr(x[i])+sqr(y[i]))*(x[j]-x[k])+(sqr(x[j])+sqr(y[j]))*(x[k]-x[i])+(sqr(x[k])+sqr(y[k]))*(x[i]-x[j]))/d;
			
			//cout<<x0<<" "<<y0<<endl;
			
			if (dist(x0,y0,x[k],y[k])>2.5+eps) continue;
			if (dist(x0,y0,x[i],y[i])>2.5+eps) continue;
			if (dist(x0,y0,x[j],y[j])>2.5+eps) continue;
			
			int t = 0;
			for (int r=0; r<n; r++) if (dist(x[r],y[r],x0,y0)<2.5+eps) t++;
			
			ans = max(t,ans);
		}
	}
				
	
	cout<<ans<<endl;

    return 0;

}
