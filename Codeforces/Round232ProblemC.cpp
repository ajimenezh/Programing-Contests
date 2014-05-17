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

#define left LEFT
#define right RIGHT

const int mod = 1000000007;

int depth[300010];
int id[300010];
int cnt;
int par[300010];
int left[300010];
int st1[1100010];
int st2[1100010];
vector<int> e[300010];
int n;

void dfs(int p, int q) {
    par[p] = q;

    if (q==-1) depth[p] = 1;
    else depth[p] = depth[q] + 1;

    left[p] = cnt+1;

    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=q) dfs(e[p][i],p);

    id[p] = ++cnt;

}

void update (int cur, int l, int r, int lt, int rt, int val, int k) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        st1[cur] = (st1[cur] + val)%mod;
        st2[cur] = (st2[cur] + k)%mod;
        return;
    }
    int h = (r+l)>>1;
    update(2*cur, l, h, lt, rt, val, k);
    update(2*cur+1,h+1, r, lt, rt, val, k);
}

int get1(int cur, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) {
        return st1[cur];
    }
    int h = (r+l)>>1;
    int tmp = st1[cur];
    tmp += get1(2*cur, l, h, lt, rt);
    if (tmp>=mod) tmp -= mod;
    tmp += get1(2*cur+1,h+1, r, lt, rt);
    return tmp%mod;
}

int get2(int cur, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) {
        return st2[cur];
    }
    int h = (r+l)>>1;
    int tmp = st2[cur];
    tmp += get2(2*cur, l, h, lt, rt);
    if (tmp>=mod) tmp -= mod;
    tmp += get2(2*cur+1,h+1, r, lt, rt);
    return tmp%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a;
        scanf("%d",&a);
        a--;
        e[i+1].push_back(a);
        e[a].push_back(i+1);
    }
    dfs(0,-1);

    int q;
    cin>>q;
    while (q--) {
        int t;
        scanf("%d",&t);
        if (t==1) {
            int x,kk,v;
            scanf("%d%d%d",&v,&x,&kk);
            v--;
            int tot = (x + ((long long)depth[v]*kk)%mod)%mod;
            update(1, 1, cnt, left[v], id[v], tot, kk);
        }
        else {
            int v;
            scanf("%d",&v);
            v--;
            int res = (get1(1,1,cnt,id[v],id[v]) - ((long long)get2(1,1,cnt,id[v],id[v])*depth[v])%mod)%mod;
            if (res<0) res += mod;
            printf("%d\n", res);
        }
    }

    return 0;

}
