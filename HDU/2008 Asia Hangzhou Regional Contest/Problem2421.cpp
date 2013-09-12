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

#define mod 10007

bool isprime[1010];
int primes[1010];
int k;
int n,m;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    
    int tt = 1;
    
    for (int i=2; i<=1000; i++) isprime[i] = 1;
    for (int i=2; i*i<=1000; i++) if (isprime[i]) {
		for (int j=i*i; j<=1000; j+=i) isprime[j] = 0;
	}
	for (int i=2; i<=1000; i++) if (isprime[i]) primes[k++] = i;

	while (scanf("%d%d",&n,&m)!=EOF) {
		int ans = 1;
		for (int i=0; i<k; i++) if (n%primes[i]==0) {
			int c = 0;
			while (n%primes[i]==0) {
				n /= primes[i];
				c++;
			}
			c = (c*m+1)%mod;
			c = (c*(c+1)/2)%mod;
			c = (c*c)%mod;
			ans = (ans*c)%mod;
			if (n==1) break;
		}
		if (n!=1) {
			int c = 1;
			c = (c*m+1)%mod;
			c = (c*(c+1)/2)%mod;
			c = (c*c)%mod;
			ans = (ans*c)%mod; 
		}
		printf("Case %d: %d\n",tt++,ans);
	}
	
    return 0;

}
