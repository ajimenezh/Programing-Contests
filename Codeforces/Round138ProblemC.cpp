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
long long k;

long long c[2001];
long long a[2001];
long long res[2001];

long long fast_pow(long long a, long long b) {
    if (b==0) return 1LL;
    if (b==1) return a;
    long long tmp = fast_pow(a,b/2LL)%mod;
    if (b%2LL==0) return (tmp*tmp)%mod;
    return (a*((tmp*tmp)%mod))%mod;
}

long long inv(long long a) {
    return fast_pow(a,mod-2)%mod;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;

    c[0]=1;

    for (int i=1; i<=n; i++) {
        c[i] = c[i-1]*(k+i-1LL)%mod;
        c[i] = (c[i]*inv((long long)i))%mod;
    }

    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

    for (int i=0; i<n; i++) res[i] = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<=i; j++) {
            res[i] = (res[i] + (c[j]*a[i-j])%mod)%mod;
        }
    }

    for (int i=0; i<n; i++) printf("%I64d ",res[i]);

    return 0;

}
