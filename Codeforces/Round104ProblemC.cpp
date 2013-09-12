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

#define mod 1000000007

int n,k;
long long a[100010];
long long c[100010];
int l[1100];
long long dp[1100][1100];
map<long long,int> ind;
int m;

long long next(long long t) {
    vector<int> v;
    while (t>0) {v.push_back(t%10); t/=10;}

    int r = 1;
    for (int i=0; i<v.size(); i++) {
        if (r==1) {
            if (v[i]==4) {
                v[i]=7;
                r = 0;
            }
            else {
                v[i]=4;
            }
        }
        else break;
    }
    if (r==1) v.push_back(4);
    long long f = 1;
    t = 0;
    for (int i=0; i<v.size(); i++) {t+=f*v[i]; f*=10;}
    return t;
}

long long solve(int p, int q) {
    if (p==0 && q==0) return 1;
    if (q<0) return 0;
    if (p==0) return 0;
    if (dp[p][q]!=-1) return dp[p][q];

    long long res = ((solve(p-1,q-1)*l[p-1])%mod + solve(p-1,q))%mod;

    dp[p][q] = res;

    return res;
}

long long fast_pow(long long a, long long  b) {
    if (b==0) return 1LL;
    if (b==1) return a;
    long long tmp = fast_pow(a,b/2)%mod;
    if (b%2==0) return tmp*tmp%mod;
    return (a*((tmp*tmp)%mod))%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) {
        scanf("%I64d",&a[i]);
    }

    long long t = 4;
    m = 0;
    while (t<=1000000000LL) {
        ind[t] = m++;
        t = next(t);
    }

    for (int i=0; i<m; i++) l[i] = 0;
    for (int i=0; i<n; i++) if (ind.find(a[i])!=ind.end()) l[ind[a[i]]]++;

    for (int i=0; i<=m; i++) for (int j=0; j<=m; j++) dp[i][j] = -1;
    for (int i=0; i<=m; i++) solve(m,i);

    long long tmp = 0;
    for (int i=0; i<n; i++) if (ind.find(a[i])==ind.end()) tmp++;
    c[0] = 1;
    for (int i=0; i<=k; i++) {
        c[i+1] = ((c[i]*(tmp-i)%mod)*fast_pow(i+1,mod-2)%mod)%mod;
        if (i>=tmp) c[i]=1;
        //cout<<i<<" "<<c[i+1]<<endl;
    }

    long long res = 0;
    for (int i=0; i<=m; i++) {
        //cout<<i<<" "<<k<<" "<<(k-i)<<" "<<tmp<<" "<<dp[m][i]<<endl;
        if (i<=k && (k-i)<=tmp)
            res = (res + (c[k-i]*dp[m][i]%mod))%mod;
    }

    cout<<res<<endl;

    return 0;

}
