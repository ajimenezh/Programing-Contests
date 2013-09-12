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

#define mod 1000000000LL

int n,m;
long long a[200010];
long long f[200010];
long long v[500010][2];
int ll,rr;

void build(int t, int link, int l, int r) {
    if (l==r) {
        v[link][t] = (a[l-1]*f[l-1+t])%mod;
        return;
    }
    int h = (l+r)/2;
    build(t,2*link,l,h);
    build(t,2*link+1,h+1,r);
    v[link][t] = (v[2*link][t] + v[2*link+1][t])%mod;
}

void update(int t, int link, int l, int r, int val) {
    if (l>=ll && r<=rr) {
        v[link][t] = (f[ll-1+t]*val)%mod;
        return;
    }
    if (r<ll || l>rr) return;
    int h = (l+r)/2;
    update(t,2*link,l,h,val);
    update(t,2*link+1,h+1,r,val);
    v[link][t] = (v[2*link][t] + v[2*link+1][t])%mod;
}

long long getsum(int t, int link, int l, int r) {
    if (l>=ll && r<=rr) {
        return v[link][t];
    }
    if (r<ll || l>rr) return 0;
    int h = (l+r)/2;
    return (getsum(t,2*link,l,h) + getsum(t,2*link+1,h+1,r))%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%I64d",a+i);

    f[0] = 1;
    f[1] = 1;
    for (int i=2; i<=n; i++) f[i] = (f[i-1] + f[i-2])%mod;

    build(0,1,1,n);
    build(1,1,1,n);

    for (int i=0; i<m; i++) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int x,va;
            scanf("%d%d",&x,&va);
            ll = rr = x;
            update(0,1,1,n,va);
            update(1,1,1,n,va);
        }
        else if (t==2) {
            int l,r;
            scanf("%d%d",&l,&r);
            ll = l;
            rr = r;
            long long sum1 = getsum(0,1,1,n);
            long long sum2 = getsum(1,1,1,n);

            long long sum;
            if (ll==1) sum = sum1;
            else if (ll==2) sum = (sum2 - sum1 + mod)%mod;
            else sum = ((sum1*f[ll-1-3+1+2] - sum2*f[ll-1-3+2])*(1-2*((ll-1)%2)) + mod)%mod;

            printf("%I64d\n",(sum%mod + mod)%mod);
        }
    }


    return 0;

}
