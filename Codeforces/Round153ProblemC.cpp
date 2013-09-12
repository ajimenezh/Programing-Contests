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

#define M 360365

long long a,b,k;

int gcd(int a, int b) {
	if (b>a) return gcd(b,a);
	return (b==0?a:gcd(b,a%b));
}

int lcm (int a, int b) {return a*b/gcd(a,b);}

long long res;
long long q[M+100];
int d[M+10];
int in,fn;

int bfs(long long s, long long t) {
	in = 0;
	fn = 0;
	q[fn++] = t;
	for (long long i=s; i<=t; i++) d[(int)(i-s)] = 1000000000;
	d[t-s] = 0;

	while (in<fn) {
		long long p = q[in++];
		
		if (p==s) break;
		if (d[p-1-s]>d[p-s]+1) {
			d[p-1-s] = 1+d[p-s];
			q[fn++] = p-1;
		}
		for (int i=2; i<=k; i++) {
			if (p-p%i>=s && d[p-p%i-s]>d[p-s]+1) {
				d[p-p%i-s] = 1+d[p-s];
				q[fn++] = p-p%i;
			}
		}
	}
	
	return d[0];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>b>>a>>k;
	
	int l = 1;
	for (int i=2; i<=k; i++) l = lcm(l,i);
	
	long long c1 = b/l;
	long long c2 = a/l;
	
	long long ll = a - a%l + l;
	long long rr = b - b%l;
	
	if (ll>rr) {
		res = bfs(a,b);
	}
	else {
		res = (c1-c2-1)*bfs(0,l) + bfs(a,ll) + bfs(rr,b);
	}
	
	cout<<res<<endl;


    return 0;

}
