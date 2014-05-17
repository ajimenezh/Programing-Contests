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

int phi(int n) {
    int res = n;
    for (int i=2; i*i<=n; i++) {
        if (n%i==0) res -= res/i;
        while(n%i==0) n /= i;
    }
    if (n>1) res -= res/n;
    return res;
}

long long fpow(long long a, int b, int mod) {
    if (b==0) return 1;
    long long tmp = fpow(a, b/2, mod);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int gcd(int a, int b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b, a%b);
}

int solve(int a, int b, int n) {
    long long g = gcd(a,n);
    long long d = a/g;
    long long f = n/g;

    long long p = phi(f);
    long long e = (b)%p;
    //long long e = div(exp,p);
    long long res = fpow(d,e,f)%f;

    //exp = n;
    if (gcd(g,f)!=1 && g%f!=0 && g%f!=1) res = (res*solve(g,n,f))%f;
    else {
        if (g%f==0) {
            res = 0;
        }
       else if (gcd(g,f)==1) {
            e = n%p;
            res = (res*fpow(g,e,f))%f;
        }
    }
    res = (res*g)%n;

    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        long long n1, n2, k1, k2;
        scanf("%lld%lld%lld%lld", &n1, &k1, &n2, &k2);
        int n;
        scanf("%d", &n);

        long long g = gcd(n1,n);
        long long d = n1/g;
        long long f = n/g;

        long long p = phi(f);
        long long e = fpow(n2, k2, p);
        e = (k1*e)%p;
        //long long e = div(exp,p);
        long long res = fpow(d,e,f)%f;

        //cout<<g<<" "<<d<<" "<<e<<" "<<f<<endl;

        //cout<<res<<endl;
        //cout<<p<<" "<<f<<endl;

        //exp = n;
        if (gcd(g,f)!=1 && g%f!=0 && g%f!=1) res = (res*solve(g,n,f))%f;
        else {
            if (g%f==0) {
                res = 0;
            }
           else if (gcd(g,f)==1) {
                e = n%p;
                //cout<<e<<endl;
                res = (res*fpow(g,e,f))%f;
                //cout<<res<<endl;
            }
        }

        res = (res*g)%n;

        cout<<res<<"\n";

    }

    return 0;

}
