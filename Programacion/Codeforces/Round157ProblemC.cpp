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

#define mod 1000000007

int n;
int a[100010];

long long mul(long long a, long long b) {
	long long tmp = a*b;
	tmp = (tmp - (tmp/mod)*mod);
	return tmp;
}

long long fpow(long long a, int b) {
	if (b==0) return 1;
	long long tmp = fpow(a,b/2);
	tmp = mul(tmp,tmp);
	if (b%2==0) return tmp;
	return mul(a,tmp);
}

int sum[100020];
int m;
int v[1001];
int c;
long long res;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	cin>>n;
	for (int i=0; i<n; i++) scanf("%d",a+i);
	
	for (int i=0; i<n; i++) sum[a[i]]++;
	for (int i=0; i<n; i++) m = max(m,a[i]);
	
	for (int i=1; i<=m+10; i++) sum[i] = sum[i] + sum[i-1];
	
	for (int i=1; i<=m; i++) {
		c = 0;
		int t = i;
		long long tot = 1;
		for (int j=1; j*j<=i; j++) if (t%j==0) {
			if (t/j!=j) v[c++] = t/j;
			v[c++] = j;
		}
		sort(v,v+c);
		for (int j=0; j<c-1; j++) {
			tot = mul(tot, fpow(j+1,sum[v[j+1]-1]-sum[v[j]-1]));
			//cout<<j<<" "<<v[j]<<" "<<tot<<endl;
		}
		t = sum[m+10] - sum[v[c-1]-1];
		tot = mul(tot,(fpow(c,t)-fpow(c-1,t)+mod)%mod);
		res = res + tot;
		if (res>mod) res -= mod;
		
		//cout<<i<<" "<<tot<<endl;
	}
	cout<<res<<endl;
	
    return 0;

}
