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

int par[100010];
int sz[100010];
inline int root(int a) {
    while (par[a]!=a) {
        par[a] = par[par[a]];
        a = par[a];
    }
    return a;
}
inline void connect(int a, int b) {
    if (root(a)==root(b)) return;
    if (sz[root(a)]>sz[root(b)]) {
        par[root(b)] = root(a);
        par[a] = root(a);
        sz[root(a)] += sz[root(b)];
        return;
    }
    par[root(a)] = root(b);
    sz[root(b)] += sz[root(a)];
    par[b] = root(b);
}
int n,m;
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    long long res = 1;
    for (int i=0; i<n; i++) {par[i] = i; sz[i] = 1;}
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        if (root(a)==root(b)) res = 2LL*res;
        connect(a,b);
        res = res%1000000009LL;
        printf("%I64d\n",res-1);
    }


    return 0;

}
