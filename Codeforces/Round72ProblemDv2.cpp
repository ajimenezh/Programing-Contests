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

int a,b,k;
bool isprime[45000];
int primes[40000];
int cnt;
long long res;

int f(int n, long long t, int i) {
    long long sol = 0;
    if (n>10 || t>b || i>=cnt) return 0;
    for (int j=i; j<cnt; j++) {
        long long tmp = t*primes[j];
        if (n%2==0) {
            sol -= b/tmp - (a-1)/tmp;
        }
        else {
            sol += b/tmp - (a-1)/tmp;
        }
        sol += f(n+1,tmp,j+1);
    }
    return sol;
}
bool prime(int t) {
    if (t==2) return 1;
    for (int i=2; i*i<=k; i++) if (t%i==0) return 0;
    return 1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>k;

    if (!prime(k)) {
        cout<<0;
        return 0;
    }
    if ((long long)k*(long long)k>=b) {
        if ((long long)k*(long long)k==b && a!=b) cout<<2<<endl;
        else if (k>=a && k<=b) cout<<1;
        else cout<<0;
        return 0;
    }
    for (long long i=2; i*i<=b; i++) isprime[i] = 1;
    for (long long i=2; i*i*i*i<=b; i++) if (isprime[i]) {
        for (long long j = i*i; j*j<=b; j+=i) isprime[j] = 0;
    }
    for (int i=2; i<k; i++) if (isprime[i]) primes[cnt++] = i;
    res = b/k - (a-1)/k;

    res += f(0,k,0);

    cout<<res;


    return 0;

}
