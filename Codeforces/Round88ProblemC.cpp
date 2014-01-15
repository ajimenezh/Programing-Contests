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

char s[5005][5005];
int n;
bool vis[5005];
int par[5005];
int next[5005];
int depth[5005];
int qq[5005];
int in, fn;
bool done;

void dfs(int p, int q, int d) {
    if (vis[p]) return;
    qq[fn++] = p;
    depth[p] = d;
    par[p] = q;
    vis[p] = 1;
    for (int i=0; i<n; i++) if (s[p][i]=='1') {
        if (vis[i] && s[i][q]=='1') {
            next[i] = p;
            done = 1;
        }
        else dfs(i,p,d+1);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%s", s+i);

    for (int i=0; i<n; i++) next[i] = -1;
    for (int i=0; i<n; i++) depth[i] = -100000;
    for (int i=0; i<n; i++) if (!vis[i]) {
        in  = fn = 0;
        done = 0;
        dfs(i,-1,0);
        if (done) break;
        while (in<fn) {
            next[qq[in]] = -1;
            depth[qq[in++]] = -100000;
        }
    }

    for (int i=0; i<n; i++) if (next[i]!=-1) {
        int t1 = next[i];
        int t2 = par[t1];
        int t3 = par[t2];
        cout<<i+1<<" "<<t2+1<<" "<<t1+1<<endl;
        return 0;
    }

    cout<<-1;


    return 0;

}
