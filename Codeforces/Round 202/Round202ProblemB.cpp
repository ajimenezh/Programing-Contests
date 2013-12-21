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

int n;
int a[100010];
long long  sum, res;
bool bad;
long long s[100010];
long long tot[100010];
vector<int> e[100010];
long long f;
long long lc[100010];
long long factor[100010];

long long gcd(long long a, long long b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long lcm(long long a, long long b) {
    return (double)a/gcd(a,b)*b;
}

void dfs2(int p, int pre, long long c) {

    s[p] *= c*factor[p];

    if (tot[p]<c) bad = 1;
    else f = min(f, tot[p]/s[p]);

    for (int i=0; i<e[p].size(); i++) {
        if (e[p][i]!=pre) {
            dfs2(e[p][i],p, c*factor[p]);
        }
    }
    return;
}

void dfs(int p, int pre) {

    lc[p] = 1;
    tot[p] = a[p];

    factor[p] = 1;

    for (int i=0; i<e[p].size(); i++) {
        if (e[p][i]!=pre) {
            dfs(e[p][i],p);
            lc[p] = lcm(lc[p],s[e[p][i]]);
            tot[p] += tot[e[p][i]];
        }
    }

    for (int i=0; i<e[p].size(); i++) {
        if (e[p][i]!=pre) {
            s[p] += lc[p];
            factor[e[p][i]] = lc[p]/s[e[p][i]];
        }
    }

    if (e[p].size()==1 && pre!=-1) s[p] = 1;

    if (tot[p]<lc[p]) bad = 1;
    else f = min(f, tot[p]/s[p]);

    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n-1; i++) {
        int c,d;
        //scanf("%d%d",&c,&d);
        c--; d--;
        e[c].push_back(d);
        e[d].push_back(c);
    }
    for (int i=0; i<n; i++) sum += a[i];

    f = 100000000000000LL;

    dfs(0,-1);
    dfs2(0,-1,1);

    if (bad) {
        cout<<sum<<endl;
        return 0;
    }

    res = (sum - s[0]*f);

    cout<<res<<endl;

    return 0;

}

