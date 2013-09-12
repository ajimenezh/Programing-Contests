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

int N,M;
int a[85][85];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int vert[46000], head[46000], cap[46000], cost[46000], next [46000];
int tot;
int src, sink;
int d[46000];
bool vis[46000];
int q[250000];
int in,fn;
int pre[46000];

void add_edge(int x, int y, int c, int w) {
    vert[++tot] = y; cap[tot] = c; cost[tot] = w; next[tot] = head[x]; head[x] = tot;
    vert[++tot] = x; cap[tot] = 0; cost[tot] = -w; next[tot] = head[y]; head[y] = tot;
}

bool spfa() {
    for (int i=0; i<=sink; i++) d[i] = 1000000;
    for (int j=0; j<=sink; j++) vis[j] = 0;

    q[in = fn = 1] = src;
    d[src] = 0;
    vis[src] = 1;

    while (in<=fn) {
        int p = q[in++];
        vis[p] = 0;

        for (int i=head[p]; i; i=next[i]) {
            int x = vert[i];

            if (cap[i] && d[x] > d[p] + cost[i]) {
                d[x] = d[p] + cost[i];
                pre[x] = i;

                if (!vis[x]) {
                    q[++fn] = x;
                    vis[x] = 1;
                }
            }
        }
    }

    //cout<<d[sink]<<endl;

    return d[sink] < 100000;
}

int solve() {

    int f = 10000;

    for (int i=sink; i!= src; i=vert[pre[i]^1]) {
        f = min(f,cap[pre[i]]);
    }

    for (int i=sink; i!= src; i=vert[pre[i]^1]) {
        cap[pre[i]]-=f;
        cap[pre[i]^1]+=f;
    }

    return d[sink]*f;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>N>>M;

    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        scanf("%d",&a[i][j]);
    }

    src = 0; sink = N*M + 2;

    tot = 1;

    for (int i=0; i<N; i++) for (int j=0; j<M; j++) {
        if (i+j&1) {
            add_edge(src, i*M+j+1,1,0);

            for (int k=0; k<4; k++) {
                int x = i + dx[k];
                int y = j + dy[k];

                if (x>=0 && x<N && y>=0 && y<M) {
                    add_edge(i*M+j+1,x*M+y+1,1,a[i][j]!=a[x][y]);
                }
            }
        }
        else {
            add_edge(i*M+j+1,sink,1,0);
        }
    }

    int res = 0;
    while (spfa()) {
        res += solve();
    }

    cout<<res<<endl;

    return 0;

}
