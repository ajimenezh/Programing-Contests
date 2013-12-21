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

int m[210][210];
int q[200];
int in,fn;
int dist[210][210];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int path(int x, int y) {
    int k = 105;
    for (int i=0; i<210; i++) {
        for (int j=0; j<210; j++) {
            dist[i][j] = -1;
        }
    }
    dist[k][k] = 0;
    q[fn++] = k*500 + k;

    while (in<fn) {
        int xx = q[in]/500;
        int yy = q[in++]%500;
        for (int i=0; i<4; i++) {
            int xxx = xx+dx[i];
            int yyy = yy+dy[i];
            if (!m[xxx][yyy]) continue;
            if (dist[xxx][yyy]==-1) {
                dist[xxx][yyy] = 1+dist[xx][yy];
                q[fn++] = 500*xxx + yyy;
            }
        }
    }
    return dist[x+k][y+k];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    int x = 0;
    int y = 0;
    bool bad = 0;
    int k = 105;
    m[0+k][0+k] = 1;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='U') x--;
        if (s[i]=='D') x++;
        if (s[i]=='R') y++;
        if (s[i]=='L') y--;
        m[x+k][y+k] = 1;
    }
    if (path(x,y)!=s.length()) cout<<"BUG";
    else cout<<"OK";

    return 0;

}
