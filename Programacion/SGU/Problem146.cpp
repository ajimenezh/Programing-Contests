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

const double eps = 1.0e-9;

float l;
int n;
int v[20010];
int t[20010];
double d;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	scanf("%f",&l);
	cin>>n;
	long long l2 = (int)((l+0.0000001)*10000.0);
	long long d2 = 0;
	for (int i=0; i<n; i++) scanf("%d%d",v+i,t+i);
	for (int i=0; i<n; i++) d2 = (d2 + ((long long)v[i]*(long long)t[i])%l2)%l2;
	
	d2 = (d2*10000)%l2;
	
	d2 = d2%l2;
	
	if (l2-d2<d2) d2 = l2-d2;
	
	printf("%lld.%04lld",d2/10000,d2%10000);

    return 0;

}
