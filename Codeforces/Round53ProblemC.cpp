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
long long c[100010];
long long res;

long long fast_pow(long long a, long long m) {
    if (m==0) return 1LL;
    if (m==1) return a;
    long long tmp = fast_pow(a,m/2)%mod;
    if (m%2==0) return tmp*tmp%mod;
    return (a*((tmp*tmp)%mod))%mod;
}

long long inv_mod(long long t) {return fast_pow(t,mod-2);}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    c[0] = 1;
    res = 1;
    for (int i=1; i<n; i++) {
        c[i] = c[i-1]*(long long)(n-1+i)%mod;
        c[i] = c[i]*inv_mod((long long)i);
        c[i] %= mod;

        res += c[i];
        res %= mod;
    }

    res = res + (res - n + mod)%mod;
    res %= mod;

    cout<<res<<endl;

    return 0;

}
