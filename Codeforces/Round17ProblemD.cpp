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

string b,n;
long long c,k;
void restan(int i) {
    if (n[n.length()-1-i]!='0') n[n.length()-1-i] = char(n[n.length()-1-i]-1);
    else {
        n[n.length()-1-i] = '9';
        restan(i+1);
    }
}
void restab(int i) {
    if (b[b.length()-1-i]!='0') b[b.length()-1-i] = char(b[b.length()-1-i]-1);
    else {
        b[b.length()-1-i] = '9';
        restab(i+1);
    }
}
long long div(string s, long long d) {
    long long r = 0;
    for (int i=0; i<s.length(); i++) {
        r = r*10LL + (s[i]-'0');
        if (r>=d) {
            r = r%d;
        }
    }
    return r;
}

long long phi(long long a)
{
    long long res = a;
    for (long long i=2; i*i<=a; i++)
    {
        if (a%i==0) res -= res/i;
        while(a%i==0) a /= i;
    }
    if (a>1) res -= res/a;
    return res;
}

long long fastpow(long long a, long long m, long long mod) {
    if (m==0) return 1;
    if (m==1) return a;
    long long tmp = fastpow(a,m/2LL,mod);
    tmp = (tmp*tmp)%mod;
    if (m%2==0) return tmp;
    return (a*(tmp))%mod;
}
long long gcd(long long r,long long p) {if (p==0) return r; if (r<p) return gcd(p,r); else return gcd(p,r%p);}

long long solve(long long a, string exp, long long mod) {
    long long g = gcd(a,mod);
    long long d = a/g;
    long long f = mod/g;

    long long p = phi(f);
    long long e = div(exp,p);
    long long res = fastpow(d,e,f)%f;

    restan(0);
    exp = n;
    if (gcd(g,f)!=1 && g%f!=0 && g%f!=1) res = (res*solve(g,n,f))%f;
    else {
        if (g%f==0) {
            res = 0;
        }
        else if (gcd(g,f)==1) {
            e = div(exp,p);
            res = (res*fastpow(g,e,f))%f;
        }
    }
    res = (res*g)%mod;
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>b>>n>>c;
    restan(0);
    k = div(b,c);
    //cout<<n<<" "<<k<<endl;
    long long res;
    if (n=="0") {
        restab(0);
        cout<<div(b,c);
        return 0;
    }

    res = solve(k,n,c);

    restab(0);
    res = (res*(div(b,c)))%c;
    if (res==0) res += c;
    cout<<res<<endl;

    return 0;

}
