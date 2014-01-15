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
int dx[] = {-1,0, 1, 1,1,0,-1,-1,0};
int dy[] = {-1,-1,-1,0,1,1, 1, 0,0};
string mapa[20];
bool vis[20][20];
int cnt[20][20];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>m && n!=0) {
        for (int i=0; i<n; i++) cin>>mapa[i];

        int ans = 0;

        while (true) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<m; j++) cnt[i][j] = 0;
                cout<<mapa[i]<<endl;
            }cout<<endl;
            int x = 0, y = 0;
            int best = -1;
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    if (mapa[i][j]!='*' && mapa[i][j]!='.' && mapa[i][j]!='0') {
                        for (int k=0; k<9; k++) {
                            int u = i+dx[k];
                            int v = j+dy[k];
                            if (u<0 || u>=n) continue;
                            if (v<0 || v>=m) continue;
                            if (vis[u][v] || mapa[u][v]=='.') continue;
                            cnt[u][v]++;
                            bool good = 1;
                            for (int t=0; t<9; t++) {
                                int uu = u+dx[t];
                                int vv = v+dy[t];
                                if (uu<0 || uu>=n) continue;
                                if (vv<0 || vv>=m) continue;
                                if (mapa[uu][vv]=='0') {
                                    good = 0;
                                    break;
                                }
                            }
                            if (good && cnt[u][v]>best) {
                                best = cnt[u][v];
                                x = u;
                                y = v;
                            }
                        }
                    }
                }
            }
            if (best==-1) break;
            vis[x][y] = 1;
            ans++;
            for (int k=0; k<9; k++) {
                int u = x+dx[k];
                int v = y+dy[k];
                if (u<0 || u>=n) continue;
                if (v<0 || v>=m) continue;
                if (mapa[u][v]!='.' && mapa[u][v]!='*') {
                    mapa[u][v] = char(mapa[u][v]-1);
                }
            }
        }
        printf("%d\n",ans);
    }


    return 0;

}
