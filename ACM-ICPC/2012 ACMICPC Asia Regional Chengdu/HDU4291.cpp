#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

typedef long long LL;

const LL MOD1 = 183120LL;
const LL MOD2 = 222222224LL;
const LL MOD3 = 1000000007LL;

vector<vector<LL> > mul(vector<vector<LL> > a, vector<vector<LL> > b, LL mod) {
    vector<vector<LL> > c = vector<vector<LL> >(2,vector<LL>(2,0));
    c[0][0] = (a[0][0]*b[0][0]%mod + a[0][1]*b[1][0]%mod)%mod;
    c[0][1] = (a[0][0]*b[0][1]%mod + a[0][1]*b[1][1]%mod)%mod;
    c[1][0] = (a[1][0]*b[0][0]%mod + a[1][1]*b[1][0]%mod)%mod;
    c[1][1] = (a[1][0]*b[0][1]%mod + a[1][1]*b[1][1]%mod)%mod;
    return c;
}

vector<vector<LL> > fpow(vector<vector<LL> > m, LL e, LL mod) {
    vector<vector<LL> > ii = vector<vector<LL> >(2,vector<LL>(2,0));
    ii[0][0] = 1;
    ii[0][1] = 0;
    ii[1][0] = 0;
    ii[1][1] = 1;

    if (e==0) {
        return ii;
    }
    ii = fpow(m, e/2, mod);
    ii = mul(ii,ii,mod);
    if (e%2==0) return ii;
    return mul(m,ii,mod);
}

long long solve(long long x, long long mod) {
    vector<vector<LL> > m = vector<vector<LL> >(2,vector<LL>(2,0));
    m[0][0] = 3;
    m[0][1] = 1;
    m[1][0] = 1;
    m[1][1] = 0;
    m = fpow(m,x%mod,mod);
    return m[1][0]%mod;
}

long long n;

int main() {
    while (cin>>n) {
        cout<<solve(solve(solve(n,MOD1),MOD2),MOD3)<<endl;;
    }
    return 0;
}
