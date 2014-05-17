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

const long long mod = 1000000007;

long long fact[2000010];

long long fpow(long long a, int b) {
    if (b==0) return 1LL;
    long long tmp = fpow(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    fact[0] = 1;
    for (int i=1; i<=2000005; i++) fact[i] = (fact[i-1]*i)%mod;

    int t;
    cin>>t;
    while (t--) {
        int n,m;
        scanf("%d%d",&n,&m);

        long long ans = fact[n+m-2];
        ans = (ans*fpow(fact[m-1], mod-2))%mod;
        ans = (ans*fpow(fact[n-1], mod-2))%mod;

        printf("%d\n", (int)ans);
    }

    return 0;

}
