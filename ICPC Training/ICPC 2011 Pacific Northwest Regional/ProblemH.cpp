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

const double eps1 = 1.0e-8;

double a[6];

double parse(string s) {
	bool exp = 0;
	for (int i=0; i<s.length(); i++) if (s[i]=='e') exp = 1;
	
	if (!exp) {
		int t = 0;
		int i = 0;
		for (; i<s.length() && s[i]!='.'; i++) t = t*10 + (s[i]-'0');
		double d = 1;
		for (i = i+1; i<s.length(); i++) d = d*10.0 + (s[i]-'0');
		while (d>1.0-eps1) d /= 10.0;
		d = d*10 - 1.0;
		return (double)t + d;
	}
	else {
		int i = 0;
		for (; i<s.length() && s[i]!='e'; i++);
		string str = s.substr(0,i);
		double p = parse(str);
		i++;
		bool neg = 0;
		if (s[i]=='-' || s[i]=='+') {
			if (s[i]=='-') neg = -1;
			i++;
		}
		int e = 0;
		for (; i<s.length(); i++) e = 10*e + (s[i]-'0');
		double d = 1.0;
		for (int j=0; j<e; j++) d = d / 10.0;
		d = d * p;
		return d;
	}
}

int main() {

    freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	string s;
	while (getline(cin,s)) {
		stringstream ss(s);
		int i = 0;
		while (ss>>s) {
			a[i++] = parse(s);
		}
		
		double lo = 0.0;
		double hi = 1000000.0;
		
		for (int i=0; i<100; i++) {
			double mid = (lo+hi)/2.0;
			
			double c = a[0]*pow(mid,4.0) + a[1]*pow(mid,3.0);
			c += a[2]*pow(mid,2.0) + a[3]*pow(mid,1.0);
			
			c *= a[4] / mid;
			
			if (c>a[5]) hi = mid;
			else lo = mid;
		}
		
		printf("%.2f\n",(double)((int)(100.0*lo))/100.0);
		
	}
	
    return 0;

}
