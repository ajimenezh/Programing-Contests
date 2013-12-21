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
string s[1010];
bool vis[1010][1010];
bool cur[1010][1010];
int depth[1010][1010];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
const string str = "DIMA";
bool cycle;

void dfs(int i, int j, int l) {
    if (cur[i][j]) {
        cycle = 1;
        return;
    }
    if (vis[i][j]) return;
    cur[i][j] = 1;
    for (int k=0; k<4; k++) {
        int px = i+dx[k];
        int py = j+dy[k];
        if (px<0 || px>=n) continue;
        if (py<0 || py>=m) continue;
        if (s[px][py]!=str[(l+1)%4]) continue;
        dfs(px,py,(l+1)%4);
        depth[i][j] = max(depth[i][j], depth[px][py]);
    }
    depth[i][j]++;
    cur[i][j] = 0;
    vis[i][j] = 1;
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (!vis[i][j] && s[i][j]=='D') dfs(i,j,0);
    }
    if (cycle) cout<<"Poor Inna!"<<endl;
    else {
        bool exist = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) if (s[i][j]=='A' && vis[i][j]) exist = 1;
        }
        if (!exist) cout<<"Poor Dima!"<<endl;
        else {
            int best = 0;
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) if (s[i][j]=='D') {
                    best = max(best, depth[i][j]-depth[i][j]%4);
                }
            }
            cout<<best/4<<endl;
        }
    }

    return 0;

}
