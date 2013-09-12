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

int t;
int n;
vector<int> e[51000];
vector<int> c[51000];
int p[51000];
int k[51000];
int par[51000];
bool vis[51000];
int best[51000];
int m;
int w[51000];

pair<int,int> dfs(int u, int v) {
    par[u] = v;
    vis[u] = 1;

    int tmp = 0;
    int cnt = 0;

    for (int i=0; i<e[u].size(); i++) if (e[u][i]!=v) {
        pair<int,int> a = dfs(e[u][i],u);

        cnt += a.first;

        tmp += a.second + c[u][i]*a.first;

    }

    p[u] = tmp;
    k[u] = cnt + w[u];

    return make_pair(k[u],tmp);
}

void solve(int u, int val, int tot) {

    for (int i=0; i<e[u].size(); i++) if (e[u][i]!=par[u]) {

        int v = e[u][i];

        int tmp = val - p[v] - k[v]*c[u][i];

        //cout<<tmp<<" "<<(tot-k[v])*c[u][i]<<endl;

        best[v] = tmp + (tot - k[v])*c[u][i] + p[v];

        solve(v, best[v], tot);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) c[i].clear();
        for (int i=0; i<n; i++) w[i] = 0;
        for (int i=0; i<n; i++) p[i] = 0;
        for (int i=0; i<n-1; i++) {
            int a,b,d;
            scanf("%d%d%d",&a,&b,&d);
            a--; b--;
            e[a].push_back(b);
            c[a].push_back(d);
            e[b].push_back(a);
            c[b].push_back(d);
        }
        cin>>m;
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            w[a-1] = b;
        }

        for (int i=0; i<n; i++) vis[i] = 0;
        dfs(0,-1);

        for (int i=0; i<n; i++) cout<<p[i]<<" "; cout<<endl;
        for (int i=0; i<n; i++) cout<<k[i]<<" "; cout<<endl;

        solve(0,p[0],k[0]);

        best[0] = p[0];

        for (int i=0; i<n; i++) cout<<best[i]<<" "; cout<<endl;

        int res = 100000;

        vector<int> v;
        for (int i=0; i<n; i++) {
            if (best[i]==res) {
                v.push_back(i+1);
            }
            else {
                if (best[i]<res) {
                    v.clear();
                    res = best[i];
                    v.push_back(i+1);
                }
            }
        }

        cout<<res*2<<endl;
        for (int i=0; i<v.size(); i++) cout<<v[i]<<" ";
        cout<<endl;
    }


    return 0;

}
