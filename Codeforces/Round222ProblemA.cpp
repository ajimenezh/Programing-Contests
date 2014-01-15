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

int n,m,k;
string s[505];
int vis[505][505];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int i, int j) {
    if (vis[i][j]) return;
    vis[i][j] = 1;

    for (int p=0; p<4; p++) {
        int x = i+dx[p];
        int y = j+dy[p];
        if (x<0 || x>=n || y<0 || y>=m) continue;
        if (s[x][y]=='#') continue;
        dfs(x,y);
        if (!k) {
            break;
        }
    }

    if (k) {
        s[i][j] = 'X';
        k--;
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) cin>>s[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (s[i][j]=='.') {
            dfs(i,j);
            i = n+1;
            break;
        }
    }

    for (int i=0; i<n; i++) cout<<s[i]<<"\n";

    return 0;

}
