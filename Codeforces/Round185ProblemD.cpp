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

#define mod 95542721

int n;
long long a[100010];
int v[48][300010];
int m;
int ll,rr;
int flag[300010];
int now[300010];

void build(int t, int u, int l, int r) {
    if (l>r) return;
    if (l==r) {
        v[t][u] = a[l];
        return;
    }
    int h = (l+r) >> 1;
    build(t,2*u,l,h);
    build(t,2*u+1,h+1,r);
    v[t][u] = (v[t][2*u] + v[t][2*u+1]);
    if (v[t][u]>=mod) v[t][u] -= mod;
}

void relax(int u) {
    if (flag[u]==0) return;
    flag[2*u] += flag[u];
    flag[2*u+1] += flag[u];
    now[u] = (now[u] + flag[u])%48;
    flag[u] = 0;
}

int getsum(int t, int u, int l, int r) {
    if (l>=ll && r<=rr) {
        return v[(t+flag[u]+now[u])%48][u];
    }
    if (r<ll || l>rr) return 0;

    relax(u);
    long long ret = 0;
    int h = (l+r) >> 1;
    ret = (ret + getsum(t,2*u,l,h));
    ret = (ret + getsum(t,2*u+1,h+1,r));
    if (ret>=mod) ret -= mod;
    return ret;
}

void doit(int u) {
    for (int i=0; i<48; i++) {
        v[i][u] = 0;
        v[i][u] = (v[i][u] + v[(i+now[2*u]+flag[2*u])%48][2*u]);
        v[i][u] = (v[i][u] + v[(i+now[2*u+1]+flag[2*u+1])%48][2*u+1]);
        if (v[i][u]>=mod) v[i][u] -= mod;
    }
    now[u] = 0;
}

void update(int t, int u, int l, int r) {
    if (l>=ll && r<=rr) {
        flag[u]++;
        return;
    }
    if (r<ll || l>rr) return;

    relax(u);
    int h = (l+r) >> 1;
    update(t,2*u,l,h);
    update(t,2*u+1,h+1,r);
    doit(u);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d",&n);
    for (int i=1; i<=n; i++) scanf("%I64d",a+i);
    for (int i=1; i<=n; i++) a[i] = a[i]%mod;

    for (int i=0; i<48; i++) {
        build(i,1,1,n);
        for (int j=1; j<=n; j++) {
            a[j] = ((a[j]*a[j])%mod)*a[j]%mod;
        }
    }

    scanf("%d",&m);

    for (int i=0; i<m; i++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            scanf("%d%d",&ll,&rr);
            int tmp = getsum(0,1,1,n);
            printf("%d\n",tmp);
        }
        else {
            scanf("%d%d",&ll,&rr);
            update(0,1,1,n);
        }
    }

    return 0;

}
