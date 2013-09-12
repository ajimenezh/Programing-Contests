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
int res;
bool isprime[45000];
bool good;
int c;
int prime[40000];

bool primes(int t) {for (long long i=3; i*i<=t; i+=2) if(t%i==0) return 0; return 1;}
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d%d",&a,&b,&k); a--;
    if (!primes(k) || (k%2==0 && k!=2)) {cout<<0; return 0;}
    if ((long long)k*(long long)k>=b) {
        if (k>a && k<=b) {
            if ((long long)k*(long long)k==b) cout<<2;
            else cout<<1;
        }
        else cout<<0;
        return 0;
    }
    if (k<8) {
        if (k==2) {
            res = b/k - a/k;
        }
        else if (k==3) {
            res = b/k - a/k;
            res -= b/6 - a/6;
        }
        else if (k==5) {
            res = b/k - a/k;
            res -= b/15 - a/15;
            res -= b/10 - a/10;
            res += b/30 - a/30;
        }
        else if (k==7) {
            res = b/k - a/k;
            res -= b/21 - a/21;
            res -= b/14 - a/14;
            res -= b/35 - a/35;
            res += b/42 - a/42;
            res += b/105 - a/105;
            res += b/70 - a/70;
            res -= b/210 - a/210;
        }
        cout<<res;
        return 0;
    }
    isprime[2] = 1;
    for (int i=3; i*i<=b; i+=2) isprime[i] = 1;
    for (int i=3; i*i*i*i<=b; i++) if (isprime[i]) {
        for (int j=i*i; j*j<=b; j+=i) isprime[j] = 0;
    }
    for (int i=5; i<k; i++) if (isprime[i]) prime[c++] = i;
    //for (int i=2; i<100; i++) cout<<i<<" "<<isprime[i]<<endl;
    int f = (((a/k)-1)/5)*5 + 5;
    if (f%2==0) f += 5;
    if (f%3==0) f += 2;
    if ((f+2)%3==0) f -= 2;
    if ((long long)f*(long long)k<=a) f += 6;
    for (int i=(a+1)/k; i<f; i++) if (i%2!=0 && i%3!=0 && (long long)i*(long long)k>a) {
        good = 1;
        if ((long long) i*(long long)k>b) break;
        for (int j=0; j<c; j++) if (i%prime[j]==0) {
            good = 0;
            break;
        }
        res += good;
    }
    b /= k;
    for (int i=f; i<=(b); i+=6) {
        good = 1;
        for (int j=0; j<c; j++) if (i%prime[j]==0) {
            good = 0;
            break;
        }
        res += good;
        if (i+2>b) break;
        good = 1;
        for (int j=0; j<c; j++) if ((i+2)%prime[j]==0) {
            good = 0;
            break;
        }
        res += good;
    }
    cout<<res<<endl;

    return 0;

}
