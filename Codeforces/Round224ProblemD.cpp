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
string s[2010];
bool done[2010][2010], vis[2010][2010];
pair<int,int> last[2010][2010];
int depth[2010][2010];

void dfs(int x, int y) {
    if (done[x][y]) return;
    if (vis[x][y]) {
        depth[x][y] = -1;
        done[x][y] = 1;
        return;
    }
    vis[x][y] = 1;
    if (s[x][y]=='#') {
        last[x][y] = make_pair(x,y);
        depth[x][y] = 0;
    }
    else {
        if (s[x][y]=='^') {
            dfs(x-1,y);
            if (depth[x-1][y]==-1) depth[x][y] = -1;
            else depth[x][y] = 1 + depth[x-1][y];
            if (depth[x-1][y]==0) last[x][y] = make_pair(x,y);
            else last[x][y] = last[x-1][y];
        }
        if (s[x][y]=='>') {
            dfs(x,y+1);
            if (depth[x][y+1]==-1) depth[x][y] = -1;
            else depth[x][y] = 1 + depth[x][y+1];
            if (depth[x][y+1]==0) last[x][y] = make_pair(x,y);
            else last[x][y] = last[x][y+1];
        }
        if (s[x][y]=='<') {
            dfs(x,y-1);
            if (depth[x][y-1]==-1) depth[x][y] = -1;
            else depth[x][y] = 1 + depth[x][y-1];
            if (depth[x][y-1]==0) last[x][y] = make_pair(x,y);
            else last[x][y] = last[x][y-1];
        }
        if (s[x][y]=='v') {
            dfs(x+1,y);
            if (depth[x+1][y]==-1) depth[x][y] = -1;
            else depth[x][y] = 1 + depth[x+1][y];
            if (depth[x+1][y]==0) last[x][y] = make_pair(x,y);
            else last[x][y] = last[x+1][y];
        }
    }
    vis[x][y] = 0;
    done[x][y] = 1;

    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (!done[i][j]) dfs(i,j);
    }

    int p1 = 0, p2 = 0;
    pair<int,int> des1, des2;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (depth[i][j]==-1) {
                cout<<-1<<endl;
                return 0;
            }
            if (depth[i][j]>p1) {
                p2 = p1;
                des2 = des1;
                p1 = depth[i][j];
                des1 = last[i][j];
            }
            else if (depth[i][j]==p1) {
                if (last[i][j]==des1) {
                    if (p2<depth[i][j]-1) {
                        p2 = depth[i][j]-1;
                        des2 = last[i][j];
                    }
                }
                else {
                    p2 = depth[i][j];
                    des2 = last[i][j];
                }
            }
            else if (depth[i][j]>p2) {
                p2 = depth[i][j];
                des2 = last[i][j];
            }
        }
    }


    cout<<p1+p2<<endl;

    return 0;

}
