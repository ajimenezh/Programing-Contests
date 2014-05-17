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

string s[101];
int n,m,k;
int dist[101][101];
int wand[101][101];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
int q[100010];
int in, fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>s[i];
        int sx, sy;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            dist[i][j] = -1;
            wand[i][j] = 0;
            if (s[i][j] == 'M') sx = i, sy = j;
        }
        cin>>k;
        in = fn = 0;
        dist[sx][sy] = 0;
        q[fn++] = m*sx + sy;
        while (in<fn) {
            int p = q[in++];
            int x = p/m;
            int y = p%m;
            int cnt = 0;
            if (s[x][y]=='*') {
                if (wand[x][y]==k) cout<<"Impressed\n";
                else cout<<"Oops!\n";
                break;
            }
            for (int i=0; i<4; i++) {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if (s[xx][yy]=='X') continue;
                if (dist[xx][yy]!=-1) continue;
                cnt++;
            }
            for (int i=0; i<4; i++) {
                int xx = x+dx[i];
                int yy = y+dy[i];
                if (xx<0 || xx>=n || yy<0 || yy>=m) continue;
                if (s[xx][yy]=='X') continue;
                if (dist[xx][yy]!=-1) continue;
                dist[xx][yy] = dist[x][y] + 1;
                q[fn++] = xx*m+yy;
                wand[xx][yy] = wand[x][y] + (cnt>1);
            }
        }
    }

    return 0;

}
