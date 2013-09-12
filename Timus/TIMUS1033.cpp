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

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int n;
string m[34];
bool vis[34][34];

int dfs(int x, int y) {
    int t = 0;
    if (vis[x][y]) return 0;
    vis[x][y] = 1;
    for (int i=0; i<4; i++) {
        int u = x + dx[i];
        int v = y + dy[i];
        if (u<0 || u>=n || v<0 || v>=n) {t++; continue;}
        if (m[u][v]=='#') {t++; continue;}
        if (!vis[u][v]) t += dfs(u,v);
    }
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>m[i];
    int res = dfs(0,0) + dfs(n-1,n-1);
    res -= 4;
    res *= 9;

    cout<<res;


    return 0;

}
