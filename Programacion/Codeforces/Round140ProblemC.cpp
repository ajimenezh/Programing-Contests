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

typedef vector<vector<long long> > mat;
#define mat0 mat (2,vector<long long> (2,0) )

long long l,r,mod,k;

long long fpow(long long a, long long b) {
	if (b==0) return 1;
	long long tmp = fpow(a,b/2);
	tmp = tmp*tmp;
	if (b%2==0) return tmp;
	return a*tmp;
}

void print(mat v) {
	cout<<v[0][0]<<" "<<v[0][1]<<endl;
	cout<<v[1][0]<<" "<<v[1][1]<<endl;
}

mat mmul(mat v1,mat v2) {
	mat v = mat0;
	
	v[0][0] = ((v1[0][0]*v2[0][0])%mod + (v1[0][1]*v2[1][0])%mod)%mod;
	v[0][1] = ((v1[0][0]*v2[1][0])%mod + (v1[0][1]*v2[1][1])%mod)%mod;
	v[1][0] = ((v1[1][0]*v2[0][0])%mod + (v1[1][1]*v2[1][0])%mod)%mod;
	v[1][1] = ((v1[1][0]*v2[1][0])%mod + (v1[1][1]*v2[1][1])%mod)%mod;
	
	return v;
}

mat mpow(mat m, long long b) {
	mat v = mat0;
	v[0][0] = 1; v[1][1] = 1;
	if (b==0) return v;
	
	v = mpow(m,b/2); 
	v = mmul(v,v);
	
	if (b%2==0) return v;
	
	v = mmul(m,v);
		
	return v;
}

int gcd(int a , int b) {
	return (b==0?a:gcd(b,a%b));
} 

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>mod>>l>>r>>k;
	
	long long g = 1;
	for (long long i=2; i*i<=r; i++) {
		if (r/i-(l-1)/i>=k) g = max(g,i);
		long long j = r/i;
		if (r/j-(l-1)/j>=k) g = max(g,j);
	}
	
	if (g<=2) {
		cout<<1%mod<<endl;
		return 0;
	}

	mat m = mat0;
	m[0][0] = 1; m[1][0] = 1;
	m[0][1] = 1; m[1][1] = 0;
	
	m = mpow(m,g-2);
	
	long long f = (m[0][0] + m[0][1])%mod;
	
	cout<<f<<endl;

    return 0;

}
