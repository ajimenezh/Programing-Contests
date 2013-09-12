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

int n;
long long a[100010];
long long b[100010];
pair<long long, int> p[200010];
long long m;
long long fact[200010];
long long mod;

long long euclide(long long a, long long b, long long &x, long long &y) {
    if (a<0) {
        long long d = euclide(-a,b,x,y);
        x = -x;
        return d;
    }
    if (b<0) {
        long long d = euclide(a,-b,x,y);
        y = -y;
        return d;
    }
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        long long d = euclide(b,a%b,x,y);
        long long t = x;
        x = y;
        y = t - (a/b)*y;
        return d;
    }
}



long long divide(long long a , long long b) {
    long long x,y;
    euclide(b,mod,x,y);
    x = (x%mod+mod)%mod;
    return (x*a)%mod;
}

long long bin(int a, int b) {
    //cout<<a<<" "<<b<<" "<<fact[a]<<" "<<fact[b]<<" "<<fact[a-b]<<endl;
    return divide(fact[a], (fact[b]*fact[a-b])%m);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d", &a[i]);
    for (int i=0; i<n; i++) scanf("%I64d", &b[i]);
    cin>>m;
    mod = m;
    for (int i=0; i<n; i++) p[i] = mp(a[i],i+1);
    for (int i=0; i<n; i++) p[n+i] = mp(b[i],i+1);

    sort(p,p+2*n);

    long long res = 1;

    fact[0] = 1;

    for (int i=1; i<2*n+1; i++) fact[i] = (fact[i-1]*i)%m;

    int d = 0;
    for (int i=0; i<2*n; i++) {
        int c = 1;
        long long t = p[i].first;
        i++;
        int j = i-1;
        while (i<2*n && p[i].first==t) {
            c++;
            i++;
        }
        i = j;

        for (int j=1; j<c; j++) {
            if (p[i+j].second==p[i-1+j].second) d++;
        }
        long long q = 1;
        for (int i=0; i<c; i++) {
            long long s = (c-i);
            while (s%2==0 && d>0)  {s /= 2LL; d--;}
            q = q*s;
            while (q%2==0 && d>0)  {q /= 2LL; d--;}
            q = q%m;
        }
        res = res*q%m;
    }

    cout<<res;

    return 0;

}
