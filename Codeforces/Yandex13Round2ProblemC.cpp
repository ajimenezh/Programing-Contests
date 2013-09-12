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

int n;
int x[2010];
int y[2010];
long long sumx,sumy;
long long sum2x, sum2y;
double pr;
int p[2010];
int z[2010];
int k;


bool cmp(int i, int j) {
	return atan2(x[i]-x[k],y[i]-y[k])>atan2(x[j]-x[k],y[j]-y[k]);
}

bool cmp2(int i, int j) {
	if (y[i]==y[j]) return x[i]<x[j];
	return y[i]<y[j];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	
	for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
	for (int i=0; i<n; i++) sumx += (long long)x[i];
	for (int i=0; i<n; i++) sumy += (long long)y[i];
	
	for (int i=0; i<n; i++) p[i] = i;
	sort(p,p+n,cmp2);
	for (int i=0; i<n; i++) z[i] = x[i];
	for (int i=0; i<n; i++) x[i] = z[p[i]];
	for (int i=0; i<n; i++) z[i] = y[i];
	for (int i=0; i<n; i++) y[i] = z[p[i]];
	
	for (int i=0; i<n; i++) p[i] = i;
	
	for (int i=0; i<n-2; i++) {
		if (i==0) {
			p[i] = i;
			k = i;
			for (int j=i+1; j<n; j++) p[j] = j;
			sort(p+i+1,p+n,cmp);
		}
		
		sumx -= (double)x[p[i]];
		sumy -= (double)y[p[i]];
		sum2x = sumx;
		sum2y = sumy;
				
		for (int j=i+1; j<n-1; j++) {
			sum2x -= (double)x[p[j]];
			sum2y -= (double)y[p[j]];
			double t = 0.0;
			t += (double)(n-j-1)*(double)x[p[i]]*y[p[j]] + (double)(sum2x)*(-y[p[j]]+y[p[i]]);
			t += (double)(n-j-1)*(double)(-x[p[j]])*y[p[i]] + (double)(sum2y)*(x[p[j]]-x[p[i]]);
			pr += fabs(t);
			//cout<<i<<" "<<j<<" "<<t<<endl;
		}
	}
	
	
	pr /= 2;
	
	pr /= (double)n;
	pr /= (double)(n-1);
	pr /= (double)(n-2);
	pr *= 6.0;
	pr = fabs(pr);
	
	printf("%.12f\n",pr);

    return 0;

}
