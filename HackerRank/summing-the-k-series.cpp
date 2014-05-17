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

const int mod = 1000000007;

long long c[1010][1010];
long long B[1010];

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long  tmp = fpow(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (a*tmp)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    c[0][0] = 1;
    for (int i=1; i<=1001; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
        for (int j=1; j<i; j++) c[i][j] = (c[i-1][j-1] + c[i-1][j])%mod;
    }

    B[0] = 1;
    for (int i=1; i<=1000; i++) {
        B[i] = 1;
        long long sum = 0;
        for (int j=0; j<i; j++) {
            long long tmp = (B[j]*fpow(i-j+1, mod-2))%mod;
            tmp = (tmp * c[i][j])%mod;
            sum = (sum + tmp)%mod;
        }
        B[i] = 1 - sum;
        B[i] = (B[i]%mod + mod)%mod;
    }

    int t;
    cin>>t;
    while (t--) {
        long long n,k;
        cin>>n>>k;

        if (k==0) {
            cout<<(n%mod)<<endl;
            continue;
        }

        n++;

        n %= mod;

        long long res = 0;

        for (int i=0; i<=k; i++) {
            long long tmp = 0;
            tmp = c[k+1][i]*fpow(n, k+1-i);
            tmp %= mod;
            tmp = (tmp*B[i])%mod;
            if (i%2!=0) tmp = -tmp;

            res = (res + tmp)%mod;

            res = (res + mod)%mod;
        }

        res = ((res*fpow(k+1, mod-2))%mod)%mod;

        cout<<res<<endl;

    }

    return 0;

}
