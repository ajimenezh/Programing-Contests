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

pair<int,int> v[10][10];
int n,m,k,s;
int a[2010][2010];
int ss[100010];
pair<int,int> p[10][4];
bool done[10][4];
int q[4000010];
bool vis[2010][2010];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int dist(pair<int,int> x, pair<int,int> y) {
    return abs(x.first-y.first) + abs(x.second-y.second);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k>>s;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) scanf("%d",&a[i][j]);
    }
    for (int i=0; i<s; i++) scanf("%d",ss+i);
    int in,fn;
    int x,y,z;
    in = 0; fn = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) vis[i][j] = 0;
    }
    for (int i=0; i<k; i++) for (int j=0; j<4; j++) done[i][j] = 0;
    x = 0; y = 0;
    z = 0;
    vis[x][y] = 1;
    q[fn++] = x*m+y;

    while (in<fn) {
        int tmp = q[in++];
        x = tmp/m;
        y = tmp%m;
        if (!done[a[x][y]][z]) {
            p[a[x][y]][z] = make_pair(x,y);
            done[a[x][y]][z] = 1;
        }
        for (int t=0; t<4; t++) {
            int xx = x+dx[t];
            int yy = y+dy[t];
            if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            q[fn++] = xx*m+yy;
        }
    }

    in = 0; fn = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) vis[i][j] = 0;
    }
    for (int i=0; i<k; i++) for (int j=0; j<4; j++) done[i][j] = 0;
    x = n-1; y = 0;
    z = 1;
    vis[x][y] = 1;
    q[fn++] = x*m+y;

    while (in<fn) {
        int tmp = q[in++];
        x = tmp/m;
        y = tmp%m;
        if (!done[a[x][y]][z]) {
            p[a[x][y]][z] = make_pair(x,y);
            done[a[x][y]][z] = 1;
        }
        for (int t=0; t<4; t++) {
            int xx = x+dx[t];
            int yy = y+dy[t];
            if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            q[fn++] = xx*m+yy;
        }
    }

    in = 0; fn = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) vis[i][j] = 0;
    }
    for (int i=0; i<k; i++) for (int j=0; j<4; j++) done[i][j] = 0;
    x = n-1; y = m-1;
    z = 2;
    vis[x][y] = 1;
    q[fn++] = x*m+y;

    while (in<fn) {
        int tmp = q[in++];
        x = tmp/m;
        y = tmp%m;
        if (!done[a[x][y]][z]) {
            p[a[x][y]][z] = make_pair(x,y);
            done[a[x][y]][z] = 1;
        }
        for (int t=0; t<4; t++) {
            int xx = x+dx[t];
            int yy = y+dy[t];
            if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            q[fn++] = xx*m+yy;
        }
    }

    in = 0; fn = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) vis[i][j] = 0;
    }
    for (int i=0; i<k; i++) for (int j=0; j<4; j++) done[i][j] = 0;
    x = 0; y = m-1;
    z = 3;
    vis[x][y] = 1;
    q[fn++] = x*m+y;

    while (in<fn) {
        int tmp = q[in++];
        x = tmp/m;
        y = tmp%m;
        if (!done[a[x][y]][z]) {
            p[a[x][y]][z] = make_pair(x,y);
            done[a[x][y]][z] = 1;
        }
        for (int t=0; t<4; t++) {
            int xx = x+dx[t];
            int yy = y+dy[t];
            if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if (vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            q[fn++] = xx*m+yy;
        }
    }

    int best = 0;
    for (int i=1; i<s; i++) {
        for (int j=0; j<4; j++) {
            for (int k=0; k<4; k++) {
                best = max(best, dist(p[ss[i-1]][j],p[ss[i]][k]));
            }
        }
    }


    cout<<best<<endl;

    return 0;

}
