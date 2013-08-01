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
long long x[100010], y[100010];
int p[100010];
long long rmi[100010], rma[100010], lmi[100010], lma[100010];

bool cmp(int i, int j) {
	return x[i]<x[j];
}

bool check(long long d) {
	for (int i=0, j=0; i<n&&j<n; i++) {
		while (j<n-1 && x[p[j+1]]-x[p[i]]<=d) j++;
		if (i==0 && j==n-1) return true;
		long long mi = min(rmi[p[j]+1],lmi[p[i]]);
		long long ma = max(rma[p[j]+1],lma[p[i]]);
		if (ma-mi<=d) return true;
	}
	return false;
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) {
		int a,b;
		scanf("%d%d",&a,&b);
		x[i] = a+b;
		y[i] = a-b;
	}
	for (int i=0; i<n; i++) p[i] = i;
	sort(p,p+n,cmp);
	
	lmi[0] = 10000000000LL;
	lma[0] = -10000000000LL;
	for (int i=0; i<n; i++) {
		lmi[i+1] = min(lmi[i],y[p[i]]);
		lma[i+1] = max(lma[i],y[p[i]]);
	}
	rmi[0] = 10000000000LL;
	rma[0] = -10000000000LL;
	for (int i=n-1; i>=0; i--) {
		rmi[i] = min(rmi[i+1],y[p[i]]);
		rma[i] = max(rma[i+1],y[p[i]]);
	}
	
	long long lo = 0;
	long long hi = 4000000000LL;
	while (lo<hi-1) {
		long long mi = (lo+hi)>>1; 
		if (check(mi)) {
			hi = mi;
		}
		else lo = mi+1;
	}
	
	while (!check(lo)) lo++;

	printf("%.16f",(double)lo*0.5);

    return 0;

}
