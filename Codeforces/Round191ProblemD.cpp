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
string a[501];
bool vis[510][510];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};
vector<string> all;

void dfs(int x, int y, int t) {
    string s;
    char buf[20];
    sprintf(buf,"B %d %d\n",x+1,y+1);
    s = buf;
    all.push_back(s);
    vis[x][y] = 1;
    for (int k=0; k<4; k++) {
        int xx=x+dx[k];
        int yy=y+dy[k];
        if (xx<0 || xx>=n) continue;
        if (yy<0 || yy>=m) continue;
        if (a[xx][yy]=='#') continue;
        if (vis[xx][yy]) continue;
        dfs(xx,yy,1);
    }
    if (t) {
        sprintf(buf,"D %d %d\n",x+1,y+1);
        s = buf;
        all.push_back(s);
        sprintf(buf,"R %d %d\n",x+1,y+1);
        s = buf;
        all.push_back(s);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (!vis[i][j] && a[i][j]=='.') dfs(i,j,0);
    cout<<all.size()<<endl;
    for (int i=0; i<all.size(); i++) cout<<all[i];

    return 0;

}
