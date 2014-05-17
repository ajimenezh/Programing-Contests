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

int q;
int par[1000100][20];
int cnt[1000100];
int k1,k2,k3;

int lca(int a, int b) {
    int aa = a, bb = b;
    if (cnt[a] < cnt[b]) swap(a,b);
    int d = cnt[a]-cnt[b];
    for (int i=0; d; i++, d >>= 1) {
        if (d&1) a = par[a][i];
    }

    for (int i=19; i>=0; i--) {
        if (par[a][i]!=par[b][i]) {
            a = par[a][i];
            b = par[b][i];
        }
    }
    int tmp = a;
    if (a!=b) tmp = par[tmp][0];

    return cnt[aa] + cnt[bb] - 2*cnt[tmp];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>q;
    for (int i=0; i<20; i++) {
        for (int j=0; j<4; j++) par[j][i] = 0;
    }

    cnt[1] = 1;
    cnt[2] = 1;
    cnt[3] = 1;

    k1 = 1; k2 = 2;

    int n = 4;
    int m = 2;

    for (int i=0; i<q; i++) {
        int v;
        scanf("%d",&v);
        v--;
        int tmp = lca(v,k1);
        int t = k1;
        int tmp2 = lca(v,k2);
        if (tmp2>tmp) {
            t = k2;
            tmp = tmp2;
        }
        par[n][0] = par[n+1][0] = v;
        for (int i=1; i<20; i++) {
            par[n][i] = par[n+1][i] = par[par[n][i-1]][i-1];
        }
        cnt[n] = cnt[n+1] = cnt[v] + 1;
        n += 2;
        if (tmp+1>m) {
            m = tmp+1;
            k1 = n-1;
            k2 = t;
        }

        cout<<m<<"\n";
    }

    return 0;

}
