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

long long a,b,k;
bool prime(long long f) {for (long long i=2;i*i<=f;i++) if (f%i==0) return 0; return 1;}
bool isprime[50000];
int d[50000];
bool good[50000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>k;
    if (!prime(k)) {
        cout<<0;
        return 0;
    }
    if (k>b || k*k>b) {
        cout<<(k>=a && k<=b);
        return 0;
    }
    isprime[0] = 0;
    isprime[1] = 0;
    for (long long i=2;i*i<=b; i++) isprime[i] = 1;
    for (long long i=2;i*i*i*i<=b;i++) if(isprime[i]) {
        for (long long j=i*i; j*j<=b;j+=i) isprime[j]=0;
    }
    //for(int i=0; i<100; i++) cout<<i<<" "<<isprime[i]<<endl;
    long long res = 0;
    for (int i=1; i<k; i++) d[i] = 0;
    for (long long i=1; i*i<=b; i++) {
        good[i] = 1;
        if (i==1) d[i] = 0;
        else if (isprime[i]) d[i] = 1;
        else {
            int t = i;
            for (int j=2; j*j<=t; j++) if (t%j==0) {
                d[i]++;
                int c = 0;
                while (t>0 && t%j==0) {t /= j; c++;}
                if (c>1) good[i] = 0;
            }
            if (t>1) d[i]++;
        }
    }
    int par = 0, impar = 0;
    int c = 0;
    for (int i=2; i<k; i++) if (isprime[i]) c++;
    long long f = 2;
    long long n = (c-1)*(c-2);
    for (int i=2; i<=c; i++) {

    }
    for (long long i=1; i*i<=b; i++) {
        if (!good[i] || i%k==0) continue;
        cout<<i<<" "<<res<<" "<<b/(i*k)<<" "<<d[i]<<endl;
        if (d[i]%2==0) res += (b/(i*k)) - (a-1)/(k*i);
        else res -= (b/(i*k)) - (a-1)/(k*i);
    }
    cout<<res<<endl;

    return 0;

}
