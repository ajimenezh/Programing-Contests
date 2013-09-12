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
long long a[100010];


long long gcd(long long a, long long b) {
	if (b>a) return gcd(b,a);
	if (b==0) return a;
	return gcd(b,a%b);
}

pair<long long,long long> divm(long long a, long long b) { 
	long long g = gcd(abs(a),abs(b));
	return make_pair(a/g, b/g);
}

bool check(pair<long long,long long> &p, pair<long long,long long> &c) {
	//cout<<c.first<<" "<<c.second<<" "<<p.first<<" "<<p.second<<endl;
	if (c.first%p.first==0 && c.second%p.second==0) {
		int t1 = 0;
		while (c.first%p.first==0 && abs(c.first)!=abs(p.first)) {
			t1++;
			c.first /= p.first;
		}
		if (abs(c.first)!=abs(p.first)) return 0;
		if (c.first>0 && p.first<0 && t1%2!=0) return false;
		if (c.first<0 && p.first>0 && t1%2!=0) return false;
		int t2 = 0;
		while (c.second%p.second==0 && abs(c.second)!=abs(p.second)) {
			t2++;
			c.second /= p.second;
		}
		if (c.second>0 && p.second<0 && t1%2!=0) return false;
		if (c.second<0 && p.second>0 && t1%2!=0) return false;
		if (abs(c.second)!=abs(p.second)) return 0;
		if (t1!=t2) return 0;
		return true;
	}
	else if (p.first%c.first==0 && p.second%c.second==0) {
		int t1 = 0;
		while (p.first%c.first==0 && p.first!=c.first) {
			t1++;
			p.first /= c.first;
		}
		if (c.first!=p.first) return 0;
		int t2 = 0;
		while (p.second%c.second==0 && p.second!=c.second) {
			t2++;
			p.second /= c.second;
		}
		if (c.second!=p.second) return 0;
		if (t1!=t2) return 0;
		return true;
	}
	return false;
}

bool cmp(int i, int j) {
	return abs(i)<abs(j);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%lld",a+i);
	sort(a,a+n,cmp);
	if (a[0]==0) {
		cout<<0<<endl;
		return 0;
	}
	long long g = abs(a[1]);
	for (int i=2; i<n; i++) {
		g = gcd(g,abs(a[i])/abs(a[i-1]));
	}
	if (g==1) { 
		bool ok = 1;
		for (int i=0; i<n; i++) if (abs(a[i])!=abs(a[0])) ok = 0;
		for (int i=0; i<n; i++) if (a[i]<0) g = -1;
		bool all = 1;
		for (int i=0; i<n; i++) if (a[i]>0) all = 0;
		if (all) g = 1;
		if (ok) {
			cout<<g<<endl;
		}
		else cout<<0<<endl;
		return 0;
	}
	if (g%abs(a[0])==0) {
		bool ok = 1;
		long long r = g / abs(a[0]);
		for (int i=0; i<n; i++) if (a[i]<0) ok = 0;
		if (ok) {
			cout<<r<<endl;
			return 0;
		}
		r = -r;
		ok = 1; 
		for (int i=0; i<n-1; i++) {
			int t = 0;
			long long c1 = abs(a[i]);
			long long c2 = abs(a[i+1]);
			while (c2>c1) {
				c2 /= (-r);
				t++;
			}
			if ((a[i]>0 && a[i+1]>0 && t%2==0) || (a[i]>0 && a[i+1]<0 && t%2==1)  || (a[i]<0 && a[i+1]>0 && t%2==1) ) {
				;
			}
			else ok = 0;
		}
		if (ok) {
			cout<<r<<endl;
			return 0;
		}
	}
	
	pair<long long,long long> c = make_pair(-1,1);
	for (int i=0; i<n-1; i++) {
		pair<long long,long long> p = divm(a[i+1],a[i]);
		if (c.first==-1) c = p;
		else {
			if (!check(p,c)) {
				cout<<0<<endl;
				return 0;
			}
		}
	}

	printf("%.12f",(double)c.first/(double)c.second);
	
    return 0;

}
