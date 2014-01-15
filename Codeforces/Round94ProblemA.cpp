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

char m[8][8][9];
bool vis[8][8][9];
int dx[] = {1,1,1,0,0,-1,-1,-1};
int dy[] = {1,0,-1,1,-1,1,0,-1};

bool dfs(int i, int j, int t) {
    if (vis[i][j][t]) return false;
    if (m[i][j][t]=='S') return false;
    if (m[i][j][t]=='A') return true;
    vis[i][j][t] = 1;
    bool res = false;
    for (int k=0; k<8; k++) {
        int x = i+dx[k];
        int y = j+dy[k];
        if (x<0 || x>=8) continue;
        if (y<0 || y>=8) continue;
        if (m[x][y][t]=='S') continue;
        res |= dfs(x,y,min(t+1,8));
    }
    if (t<8) res |= dfs(i,j,min(t+1,8));
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<8; i++) {
        string s;
        cin>>s;
        for (int j=0; j<8; j++)
            m[i][j][0] = s[j];
    }

    for (int i=1; i<=8; i++) {
        for (int x=0; x<8; x++) {
            for (int y=0; y<8; y++) {
                m[x][y][i] = '.';
                if (m[x][y][i-1]=='A') m[x][y][i] = 'A';
                if (x>0 && m[x-1][y][i-1]=='S') {
                    m[x][y][i] = 'S';
                }
            }
        }
    }

    bool ans;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) if (m[i][j][0]=='M') {
            ans = dfs(i,j,0);
        }
    }
    if (ans) cout<<"WIN";
    else cout<<"LOSE";

    return 0;

}
