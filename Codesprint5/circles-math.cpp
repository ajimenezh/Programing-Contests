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

long long d[1000000];
const int mod = 1000000007;

long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a, b/2);
    tmp = (tmp*tmp)%mod;
    if (b%2==0) return tmp;
    return (tmp*a)%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    d[0] = 1;
    d[1] = 0;
    d[2] = 1;

    for (int i=3; i<1000001; i++) d[i] = (long long)(i-1)*(d[i-1]+d[i-2])%mod;

    int t;
    cin>>t;
    while (t--) {

        int n,k;
        cin>>n>>k;

        long long ans = 0;
        long long tmp = 1;

        for (int cyq=1; k*cyq<=n; cyq++) {
            long long t = 1;

            if (n-k*cyq>0) {
                for (int i=n-k*(cyq-1); i>n-k*(cyq-1)-k; i--) tmp = (tmp*i)%mod;
                for (int i=1; i<=k; i++) t = (t*i)%mod;
                tmp = tmp*fpow(t,mod-2)%mod;
            }

            for (int i=1; i<k; i++) tmp = (tmp*i)%mod;

            t = 1;
            for (int i=1; i<=cyq; i++) t = (t*i)%mod;
            tmp = tmp*fpow(cyq,mod-2)%mod;

            long long cur = (tmp*d[n-k*cyq])%mod;

            if (cyq&1) {
                ans = (ans + cur)%mod;
            }
            else {
                ans = (ans - cur)%mod;
                ans = (ans + mod)%mod;
            }
        }
        if (k==1) ans = 0;
        cout<<ans<<endl;
    }

    return 0;

}
