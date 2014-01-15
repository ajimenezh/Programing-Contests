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
char buf[510][510];
int h[510][510], v[510][510];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
bool vis[510][510];
bool bad;
int b,w;

int q[100000];
int in,fn;

void bfs(int x, int y) {
    in = 0;
    fn = 0;
    b = 0;
    w = 0;
    q[fn++] = x*m + y + 1;
    vis[x][y] = 1;
    while (in<fn) {
        int p = q[in++];
        if (p>0) {
            p--;
            x = p/m;
            y = p%m;
            b++;
            for (int k=0; k<4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if (buf[xx][yy]!='W') continue;
                if (dy[k]==0) h[x][y]++;
                else v[x][y]++;
                if (vis[xx][yy]) continue;
                q[fn++] = -xx*m - yy - 1;
                vis[xx][yy] = 1;
            }
        }
        else {
            p = -p;
            p--;
            x = p/m;
            y = p%m;
            w++;
            for (int k=0; k<4; k++) {
                int xx = x + dx[k];
                int yy = y + dy[k];
                if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if (buf[xx][yy]!='B') continue;
                if (vis[xx][yy]) continue;

                vis[xx][yy] = 1;
                q[fn++] = xx*m + yy + 1;
            }
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>buf[i];
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                vis[i][j] = 0;
                v[i][j] = 0;
                h[i][j] = 0;
                if (buf[i][j]=='B') b++;
                else if (buf[i][j]=='W') w++;
            }
        }
        bad = 0;
        if (2*b!=w) bad = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (!vis[i][j] && buf[i][j]=='B') {
                    bfs(i,j);
                    if (2*b!=w) bad = 1;
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                if (buf[i][j]=='B') {
                    if (v[i][j]==0 || h[i][j]==0) {
                        bad = 1;
                    }
                }
            }
        }

        if (bad) cout<<"NO\n";
        else cout<<"YES\n";
    }

    return 0;

}
