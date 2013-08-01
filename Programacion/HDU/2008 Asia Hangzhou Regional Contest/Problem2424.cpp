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
#include <iomanip>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

struct bignum {
	long long num[100];
	int len;
	bignum() {len = 0;};
};

bignum& operator += (bignum& a, long long num) {
	long long tmp = num;
	for (int i=0; tmp&&i<a.len; i++) {
		a.num[i] += tmp;
		tmp = a.num[i]/1000000;
		a.num[i] %= 1000000;
	}
	if (tmp) {
		a.num[a.len] = tmp;
		a.len++;
	}
	return a;
}

bignum& operator += (bignum& a, const bignum& b) {
	bignum c;
	long long tmp = 0;
	for (int i=0; i<a.len||i<b.len; i++) {
		c.num[i] = tmp;
		if (i<a.len) {
			c.num[i] += a.num[i];
		}
		if (i<b.len) {
			c.num[i] += b.num[i];
		}
		tmp = c.num[i]/1000000;
		c.num[i] %= 1000000;
	}
	c.len = a.len>b.len ? a.len : b.len;
	if (tmp) {
		c.num[c.len] = tmp;
		c.len++;
	}
	a = c;
	return a;
}

bignum& operator *= (bignum& a, long long num) {
	long long tmp = 0;
	for (int i=0; i<a.len; i++) {
		a.num[i] *= num;
		a.num[i] += tmp;
		tmp = a.num[i]/1000000;
		a.num[i] %= 1000000;
	}
	while (tmp) {
		a.num[a.len] = tmp%1000000;
		tmp /= 1000000;
		a.len++;
	}
	return a;
}

bignum& operator *= (bignum& a, bignum& b) {
	bignum c;
	for (int i=0; i<100; i++) c.num[i] = 0;
	for (int i=0; i<a.len; i++) for (int j=0; j<b.len; j++) 
		c.num[i+j] += a.num[i]*b.num[j];
		
	c.len = a.len + b.len -1;
	long long tmp = 0;
	for (int i=0; i<c.len; i++) {
		c.num[i] += tmp;
		tmp = c.num[i]/1000000;
		c.num[c.len] = tmp%1000000;
	}
	while (tmp) {
		c.num[c.len] = tmp%1000000;
		tmp /= 1000000;
		c.len++;
	}
	a = c;
	return a;
}

ostream& operator<<(ostream& out, const bignum& a) {
	if (a.len==0) {
		out<<"0";
		return out;
	}
	out << a.num[a.len-1];
	for (int i=a.len-2; i>=0; i--) {
		out<<setfill('0')<<setw(6)<<a.num[i];
	}
	return out;
}

vector<bignum> v;
int n;
string s;
string pre;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int k = 1;

	while (scanf("%d",&n)!=EOF) {
		bool bad = 0;
		v.clear(); 
		pre = "0";
		for (int i=0; i<n; i++) {
			cin>>s;
			if (v.size()==0 && (s=="+" || s=="*")) {
				bad = 1;
			}
			else if (s=="+") {
				if (i==n-1 || (pre=="+" || pre=="*")) {
					bad = 1;
				}
			}
			else if (s=="*") {
				if (i==n-1 || (pre=="+" || pre=="*")) {
					bad = 1;
				}
				else {
					cin>>s;
					if ((s=="+" || s=="*")) {
						bad = 1;
					}
					else {
						bignum tmp = v[v.size()-1];
						v.pop_back();
						tmp *= atoll(s.c_str());
						v.push_back(tmp); 
						i++;
					}
				}
			}
			else if (s!="*" && s!="+") {
				if (i!=0 && pre!="+" && pre!="*") {
					bad = 1;
				}
				else {
					bignum tmp;
					tmp += atoll(s.c_str());
					v.push_back(tmp);
				}
			}
			pre = s;
		}
		if (bad) {
			printf("Case %d: Invalid Expression!\n",k++);
			continue;
		}
		bignum sum;
		for (int i=0; i<v.size(); i++) {
			sum += v[i];
		}
		
		printf("Case %d: ",k++);
		cout<<sum<<endl;

	}

    return 0;

}
