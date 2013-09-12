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

bool prime(int t) {
    if (t==2) return 1;
    for (int i=2; i*i<=t; i++) if (t%i==0) return 0;
    return 1;
}

int f(int t, int i) {
    if (t<i) return 0;
    if (!prime(i)) return 0;
    int sol = t/i;
    t = sol;
    if (t<i) return 1;
    for (int j=2; j<i; j++) {
        sol -= f(t,j);
    }
    return sol;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>k;

    if (!prime(k)) {
        cout<<0;
        return 0;
    }

    res = f(b,k) - f(a-1,k);

    cout<<res;


    return 0;

}
