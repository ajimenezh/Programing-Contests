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

#define mod 1000000007LL

long long fpow(long long a, int b) {
	if (b==0) return 1;
	long long tmp = fpow(a,b/2);
	tmp = (tmp*tmp)%mod;
	if (b%2==0) return tmp;
	return (tmp*a)%mod;
}

long long inv(long long a) {
	return fpow(a,mod-2);
}

int n;
int p[16];
int a[16];
long long prod[16];
long long fact[16];
long long dp1[16];
long long dp2[16];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

	int c;
	cin>>c;
	int k = 1;
	while (c--) {
		cin>>n;
		for (int i=1; i<=n; i++) scanf("%d%d",p+i,a+i);
		for (int i=1; i<=n; i++) prod[i] = fpow(p[i],a[i]);
		for (int i=1; i<=n; i++) {
			fact[i] = (prod[i]*p[i])%mod;
			fact[i] = (fact[i]-1+mod)%mod;
			fact[i] = (fact[i]*inv(p[i]-1))%mod;
		}
			
		dp1[0] = 1;
		dp2[0] = 1;
		
		for (int i=1; i<=n; i++) {
			dp1[i] = fact[i];
			dp1[i] = (dp1[i] + prod[i]*(a[i]))%mod;
			dp1[i] = (dp1[i]*dp1[i-1])%mod;
			dp2[i] = (dp2[i-1]*prod[i])%mod;
		}
		//cout<<dp1[n]<<" "<<dp2[n]<<endl;
		long long res = (dp1[n] + dp2[n])%mod;
		
		printf("Case %d: %d\n",k++,(int)res);
	}

    return 0;

}
