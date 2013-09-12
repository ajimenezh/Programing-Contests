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

#define mod 1000000007LL

int n,m;
long long res;
int v[1001];

long long fastpow(long long a, long long b) {
    if (b==0) return 1;
    if (b==1) return a;
    long long tmp = fastpow(a,b/2)%mod;
    if (b%2==0) return (tmp*tmp)%mod;
    tmp = (tmp*tmp)%mod;
    return (tmp*a)%mod;
}

long long c(int a, int b) {
    long long tmp = 1;
    for (int i=1; i<=a; i++) tmp = (tmp*i)%mod;
    long long t = 1;
    for (int i=1; i<=b; i++) t = (t*i)%mod;
    for (int i=1; i<=(a-b); i++) t = (t*i)%mod;
    return (tmp*fastpow(t,mod-2))%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    int k = 0;
    int p = 0;
    res = 1;
    for (int i=0; i<m; i++) cin>>v[i];
    sort(v,v+m);
    for (int i=0; i<m; i++) {
        int t;
        t = v[i];
        if (k==0) {
            p += t-1;
            k = t;
        }
        else {
            for (int j=1; j<(t-k-1); j++) res = (res*2LL)%mod;
            res = (c(p+(t-k-1),t-k-1)*res)%mod;
            p += t-k-1;
            k = t;
        }
    }

    res = (c(p+(n-k),n-k)*res)%mod;

    cout<<res<<endl;

    return 0;

}
