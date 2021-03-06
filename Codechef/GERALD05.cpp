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

int t;
long long a0,a1,a2,a3,s;
long long dp[110][110];
const int mod = 1000000007;

long long add(long long a, long long b) {
    a += b;
    if (a>=mod) a -= mod;
    return a%mod;
}

long long mul(long long a, long long b) {
    return (a*b)%mod;
}

long long fpow(long long a, int b) {
    if (b==0) return 1LL;
    long long tmp = fpow(a,b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

long long solve(int i, int sum) {
    if (sum>s) return 0;
    if (sum==s) return 1;
    if (i>100) return 0;
    if (dp[i][sum]>=0) return dp[i][sum];

    long long num = a0 + a1*i + a2*i*i + a3*i*i*i;
    long long f = a0 + a1*i + a2*i*i + a3*i*i*i;
    long long m = f;
    long long den = 1;
    long long t = 1;

    long long tmp = solve(i+1, sum);

    for (int k=1; k<=(s-sum); k++) {
        if (sum+k*i>s) break;
        tmp = add(tmp, mul(solve(i+1,sum+k*i), mul(num, fpow(den, mod-2)) ));
        num = mul(num, ++f);
        den = mul(den, ++t);
    }
    dp[i][sum] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>a0>>a1>>a2>>a3;
        cin>>s;
        for (int i=1; i<=100; i++) {
            for (int j=0; j<=s; j++) {
                dp[i][j] = -1;
            }
        }
        cout<<solve(1,0)<<"\n";
    }

    return 0;

}
