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

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    if (b==0) return a;
    if (a<b) return  gcd(b,a);
    return gcd(b,a%b);
}

bool isprime(int p) {
    for (int i=2; (long long)i*i<=p; i++) if (p%i==0) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        int p = n;
        int q = n+1;
        while (!isprime(p)) p--;
        while (!isprime(q)) q++;

        unsigned long long den = 2LL*p*q;
        unsigned long long num = (unsigned long long)p*q - 2LL*q + 2LL*(n-p+1);

        unsigned long long g = gcd(num, den);
        num /= g;
        den /= g;

        cout<<num<<"/"<<den<<"\n";
    }

    return 0;

}
