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
int vv[100010];
vector<int> e[100010];
int mi[100010];
int ma[100010];
int res;

void dfs(int u, int v) {
    mi[u] = min(m, vv[u]);
    ma[u] = max(M, vv[u]);

    for (int i=0; i<e[u].size(); i++) {
        int p = e[u][i];
        if (p==v) continue;
        int tdfs(p, u);
        mi[u] = min(mi[u], mi[p]);
        ma[u] = max(ma[u], ma[p]);
    }
    if (vv[u]<=mi[u])
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i=0; i<n; i++) scanf("%d",vv+i);

    dfs(0,-1);

    cout<<res<<endl;

    return 0;

}
