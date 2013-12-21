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
string s[55];
bool vis[55][55][4][2];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

void dfs(int x, int y, int k, int d) {
    if (k<0) return;
    if (x<0 || x>=n) return;
    if (y<0 || y>=m) return;
    if (vis[x][y][d][k]) return;
    if (s[x][y]=='W') return;
    vis[x][y][d][k] = 1;

    for (int i=0; i<4; i++) {
        if (i==d) {
            dfs(x+dx[i], y+dy[i], k, i);
        }
        else {
            dfs(x+dx[i], y+dy[i], k-1, i);
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];

    bool bad = 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (s[i][j]=='B') {
                for (int ii=0; ii<n; ii++) {
                    for (int jj=0; jj<m; jj++) {
                        for (int d=0; d<4; d++) {
                            for (int k=0; k<2; k++) {
                                vis[ii][jj][d][k] = 0;
                            }
                        }
                    }
                }
                dfs(i,j,1,0);
                dfs(i,j,1,1);
                dfs(i,j,1,2);
                dfs(i,j,1,3);
                for (int ii=0; ii<n; ii++) {
                    for (int jj=0; jj<m; jj++) {
                        bool done = 0;
                        for (int d=0; d<4; d++) {
                            for (int k=0; k<2; k++) {
                                if (vis[ii][jj][d][k]) done = 1;
                            }
                        }
                        if (!done && s[ii][jj]=='B') {
                            //cout<<i+1<<" "<<j+1<<" "<<ii+1<<" "<<jj+1<<endl;
                            bad = 1;
                        }
                    }
                }
            }
        }
    }

    if (bad) cout<<"NO";
    else cout<<"YES";

    return 0;

}
