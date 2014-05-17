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

int n,k;
long long a[10010];
long long fact[10010];

long long fast_pow(long long a, long long b) {
    if (b==0) return 1;
    if (b==1) return a;
    long long tmp = fast_pow(a,b/2LL)%mod;
    if (b%2==0) return (tmp*tmp)%mod;
    return (a*((tmp*tmp)%mod))%mod;
}

long long c(long long k, long long t) {
    long long num = 1;
    long long den = 1;

    num = fact[k];
    den = (fact[t]*fact[k-t])%mod;

    return num*(fast_pow(den,mod-2)%mod)%mod;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    fact[0] = 1;

    for (int i=1; i<=10010; i++) {
        fact[i] = (fact[i-1]*i)%mod;
    }

    int tt;
    cin>>tt;
    for (int t=0; t<tt; t++) {
        cin>>n>>k;

        for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

        long long res = 0;

        sort(a,a+n);
        reverse(a,a+n);

        for (int i=0; i<n; i++) a[i] = a[i]%mod;

        for (int i=0; i<=(n-k); i++) {
            res = (res + (c(n-i-1,k-1)*a[i])%mod)%mod;
            //cout<<res<<endl;
            //cout<<c(n-i-1,k-1)<<" "<<i<<" "<<a[i]<<endl;
        }

        printf("Case #%d: %I64d\n",t+1,res);
    }

    return 0;

}
