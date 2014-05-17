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

int n,d;
vector<int> edges[30000];
int bad[30000];
int depth[30000];
int root[30000];
int rama[30000];
bool vis[30000];
int res;

void dfs(int p, int prof, int r) {
    vis[p] = 1;
    depth[p] = prof;

    bad[p] = 0;

    root[p] = r;
    int k = 0;

    rep(it,edges[p]) {
        int q = *it;
        if (vis[q]) continue;
        if (p==0) k++;
        else k = r;
        dfs(q,prof + 1,k);
        bad[p] = max(bad[p],bad[q]+1);
    }

    pair<int,int> worst1 = make_pair(0,-1);
    pair<int,int> worst2 = make_pair(0,-1);
    if (p==0) {
        rep(it,edges[p]) {
            int q = *it;
            if (bad[q]>worst1.first) {
                worst2 = worst1;
                worst1 = make_pair(bad[q],q);
            }
            else {
                if (bad[q]>worst2.first) {
                    worst2 = make_pair(bad[q],q);
                }
            }
        }
        int k=0;
        rep(it,edges[p]) {
            int q = *it;
            if (q!=worst1.second) {
                rama[++k] = worst1.first;
            }
            else rama[++k] = worst2.first;
        }
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for (int k=0; k<t; k++) {
        scanf("%d%d",&n,&d);
        for (int i=0; i<n-1; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            edges[a].push_back(b);
            edges[b].push_back(a);
        }

        for (int i=0; i<n; i++) vis[i] = 0;
        res = n+1;
        dfs(0,1,-1);

        for (int i=0; i<n; i++) {
            if (edges[i].size()<=d) {
                res = min(res,max(bad[i]+1,depth[i]+rama[root[i]]+1));
            }
        }

        printf("Case #%d: %d\n",k+1,res);

        for (int i=0; i<n; i++) edges[i].clear();
    }

    return 0;

}
