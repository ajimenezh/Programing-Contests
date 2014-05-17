#include <iostream>
#include <stdio.h>
using namespace std;

const int mod = 1000000007;

int a[100000];
int n;
long long fact[100010];

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

long long C(int a, int b) {

  long long num = fact[a];
  long long den = (fact[b]*fact[a-b])%mod;

  return (num*fpow(den, mod-2))%mod;

}

int main() {
  	cin>>n;
	for (int i=0; i<n; i++) scanf("%d", a+i);

  	fact[0] = 1;
  	for (int i=1; i<=n; i++) fact[i] = (fact[i-1]*i)%mod;

  	int odd = 0, even = 0;

	for (int i=0; i<n; i++) {
      	if (a[i]%2==0) even++;
    	else odd++;
    }

  	long long res = 1;

  	if (even>0) res = (res*(fpow(2, even))%mod)%mod;

  	if (odd>1) {
        long long tot = 1;
   		for (int j=2; j<=odd; j+=2) {
            tot = (tot + C(odd, j))%mod;
        }
        res = (res*tot)%mod;
    }

    if (odd==1 && even==0) res = 0;
    else res = (res - 1 + mod)%mod;

  	cout<<res<<endl;

  	return 0;
}
