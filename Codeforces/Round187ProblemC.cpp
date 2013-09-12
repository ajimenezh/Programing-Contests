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

int n;
int a[100010];
long long sum[100010];
int last[1000010];
long long v[100010];
long long s[1000010];
bool vis[1000010];

void update(int u, int x) {
    for (int i=u; i<=1000010; i += i & -i) s[i] = (s[i] + x)%mod;
}
long long get(int u) {
    if (u==0) return 0;
    long long x = 0;
    for (int i=u; i>0; i -= i & -i) x = (x + s[i])%mod;
    return x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    sum[0] = 0;
    long long res = 0;

    for (int i=0; i<n; i++) {

        long long tmp = ((get(a[i])-v[last[a[i]]] + mod)*a[i] + a[i]*(1-vis[a[i]]))%mod;

        vis[a[i]] = 1;
        res = (res + tmp)%mod;

        update(a[i], tmp);
        last[a[i]] = i+1;
        v[i+1] = (get(a[i]) - tmp + mod)%mod;
    }

    cout<<res<<endl;

    return 0;

}
