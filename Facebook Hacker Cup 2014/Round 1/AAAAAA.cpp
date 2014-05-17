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

int n,m;
string mapa[510];
int dist[510][510][2];
int pre[510][510][2];
priority_queue<pair<int,int> > q;
int dx[] = {1,0};
int dy[] = {0,1};

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int cc;
    cin>>cc;
    for (int cas=1; cas<=cc; cas++) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>mapa[i];
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<2; k++) dist[i][j][k] = -1;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<2; k++) pre[i][j][k] = -1;
        dist[0][0][1] = 1;
        while (!q.empty()) q.pop();
        q.push(make_pair(1,0));
        int ans = 0;
        while (!q.empty()) {
            int c = q.top().first;
            ans = max(ans, c);
            int f = q.top().second/(n*m);
            int p = q.top().second%(n*m);
            int x = p/m;
            int y = p%m;
            q.pop();

            for (int i=0; i<2; i++) {
                int u = x + dx[i];
                int v = y + dy[i];
                if (u<0 || u>=n || v<0 || v>=m) continue;
                if (mapa[u][v]=='#') continue;
                if (pre[x][y][f]==u*m+v) continue;
                if (dist[u][v][f]<c+1) {
                    dist[u][v][f] = c+1;
                    pre[u][v][f] = x*m+y;
                    q.push(make_pair(c+1, u*m + v + f*m*n));
                }
            }

            if (f==0) {
                for (int i=0; i<2; i++) {
                    int j = 1;
                    while (true) {
                        int u = x - j*dx[i];
                        int v = y - j*dy[i];
                        if (u<0 || u>=n || v<0 || v>=m) break;
                        if (mapa[u][v]=='#') break;
                        if (pre[x][y][f]==u*m+v) break;
                        if (dist[u][v][1]<c+j) {
                            dist[u][v][1]=c+j;
                            pre[u][v][1] = (u+dx[i])*m+(v+dy[i]);
                            q.push(make_pair(c+j, u*m + v + m*n));
                        }
                        j++;
                    }
                }
            }
        }

        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;

}
