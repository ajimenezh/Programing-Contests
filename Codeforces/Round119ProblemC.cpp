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

#define INF 1<<30

int n,m,k;
bool p[100010];
int c[100010];
vector<int> e[100010];
int vis[100010];
int s,t;
int q[1000100];
int pre[100010];
bool done[100010];
int res;

void solve(int h) {
    int in = 0, fn = 0;
    for (int i=0; i<k; i++) {
        q[fn++] = c[i];
        vis[c[i]] = 0;
    }

    while (fn>in) {
        int p1 = q[in++];
        if (vis[p1]>=h) {
            res = 1<<30;
            rep(it,e[p1]) if (*it!=pre[p1]) {
                res = min(res,vis[*it]);
                if (res==-1) res++;
            }
            if (p1!=t) res += vis[p1]+1;
            else res++;
            break;
        }
        rep(it,e[p1]) {
            if (vis[*it]==-1) {
                pre[*it] = p1;
                vis[*it] = 1 + vis[p1];
                q[fn++] = (*it);
            }
        }
    }
}

void dfs(int p) {
    done[p] = 1;
    rep(it,e[p]) {
        if (!done[*it] && vis[*it]!=-1) {
            dfs(*it);
        }
    }
    return;
}

bool connected() {
    for (int i=0; i<n; i++) done[i] = 0;
    dfs(s);
    for (int i=0; i<n; i++) cout<<vis[i]<<" "; cout<<endl;
    if (done[t]) return true;
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) p[i] = 0;
    for (int i=0; i<k; i++) {
        int a;
        scanf("%d",&a);
        a--;
        p[a] = 1;
        c[i] = a;
    }
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    cin>>s>>t;
    t--;
    s--;
    p[t] = 1;
    c[k++] = t;

    for (int i=0; i<n; i++) vis[i] = 1;
    if (!connected()) {
        cout<<-1;
        return 0;
    }

   int l = 0;
   int r = 100100;

    while (l<r) {
        int h = (l+r)/2;

        for (int i=0; i<n; i++) vis[i] = -1;
        solve(h);

        //cout<<l<<" "<<r<<" "<<connected()<<endl;

        if (!connected()) {
            l = h+1;
        }
        else {
            r = h;
        }
    }

    for (int i=max(0,l-3); i<=r+3; i++) {
        for (int i=0; i<n; i++) vis[i] = -1;
        solve(i);
        if (connected()) {
            cout<<res<<endl;
            return 0;
        }
    }


    return 0;

}
