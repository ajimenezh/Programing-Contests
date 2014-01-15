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


long long fpow(long long a, int b) {
    if (b==0) return 1;
    long long tmp = fpow(a,b/2);
    tmp = tmp*tmp;
    if (b%2==0) return tmp;
    return a*tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n;
    while (scanf("%lld",&n)!=EOF) {
        long long k = n-1, r = 1;

        for (int i=2; i<=45; i++) {
            long long lo = 2;
            long long hi = (long long)pow(n,1.0/i);
            while (lo<=hi) {
                long long mi = (lo+hi)/2;
                long long f = (mi - fpow(mi,i+1))/(1-mi);
                if (f<n-1) lo = mi+1;
                else {
                    if (f>n) hi = mi-1;
                    else {
                        lo = mi;
                        break;
                    }
                }
            }
            long long f = (lo - fpow(lo,i+1))/(1-lo);
            if (f==n || f==n-1) {
                if ((long long)k*r>(long long)i*lo) {
                    k = lo;
                    r = i;
                }
            }
        }

        printf("%lld %lld\n",r,k);
    }

    return 0;

}
