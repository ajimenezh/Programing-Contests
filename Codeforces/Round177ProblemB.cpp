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

int n,k;

long long fastpow(long long a, int b) {
    if (b==0) return 1;
    if (b==1) return a;
    long long tmp = fastpow(a,b/2);
    if (b%2==0) return (tmp*tmp)%mod;
    return (a*((tmp*tmp)%mod))%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;

    long long res = 0;

    res = (fastpow(k,k-1)*fastpow(n-k,n-k))%mod;

    cout<<res;

    return 0;

}
