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

#define next NEXT

int n;
pair<pair<long long, long long>, int> v[100010];
int next[100010];
int par[100010][20];
int depth[100010];

bool check(int a, int b, int c) {
    long long x1 = v[a].first.first - v[b].first.first;
    long long x2 = v[a].first.first - v[c].first.first;
    long long y1 = v[a].first.second - v[b].first.second;
    long long y2 = v[a].first.second - v[c].first.second;

    return (x1*y2 - x2*y1)<0;
}

int lca(int a, int b) {
    int aa = a, bb = b;
    if (depth[a] < depth[b]) swap(a,b);
    int d = depth[a]-depth[b];
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

    return tmp;
}

int calc(int p) {
    if (depth[p]!=-1) return depth[p];
    if (par[p][0]==p) {
        depth[p] = 0;
        return 0;
    }
    depth[p] = 1 + calc(par[p][0]);
    return depth[p];
}

bool vis[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        long long x,y;
        scanf("%I64d %I64d", &x, &y);
        v[i] = make_pair(make_pair(x,y), i);
    }
    sort(v, v+n);

    //for (int i=0; i<n; i++) {
    //    cout<<v[i].first.first<<" "<<v[i].first.second<<endl;
    //}

    next[n-2] = n-1;
    next[n-1] = n-1;
    vector<int> w;
    for (int i=0; i<n-2; i++) if (!vis[i]) {
        int j = i+1;
        w.clear();
        w.push_back(i);
        for (int k=i+2; k<n; k++) {
            if (check(i,j,k)) {
                w.push_back(j);
                j = k;
            }
        }
        for (int k=0; k<w.size(); k++) {
            vis[w[k]] = 1;
            next[w[k]] = j;
        }
        //for (int k=i; k<j-1; k++) next[k] = j-1;
        //i = j-1;
        next[i] = j-1;
    }

    cout<<"--------"<<endl;
    for (int i=0; i<n; i++) cout<<i<<" "<<next[i]<<endl;
    cout<<"------"<<endl;

    for (int i=0; i<n; i++) {
        par[v[i].second][0] = v[next[i]].second;
    }
    for (int i=1; i<20; i++) {
        for (int j=0; j<n; j++) {
            par[j][i] = par[par[j][i-1]][i-1];
        }
    }

    for (int i=0; i<n; i++) depth[i] = -1;
    for (int i=0; i<n; i++) calc(i);

    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--; b--;
        int t = lca(a,b);
        printf("%d ", t+1);
    }

    return 0;

}
