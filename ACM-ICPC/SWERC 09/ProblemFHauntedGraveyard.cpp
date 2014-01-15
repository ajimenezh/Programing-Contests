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

#define INF 1<<30

int w,h;
bool gs[31][31];
bool ish[31][31];
pair<pair<int,int>,int> hh[31][31];
int dist[31][31];

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>w>>h && w!=0) {
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                gs[i][j] = 0;
                ish[i][j] = 0;
                dist[i][j] = INF;
            }
        }
        dist[0][0] = 0;
        int g;
        cin>>g;
        for (int i=0; i<g; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            gs[x][y] = 1;
        }
        int m;
        cin>>m;
        for (int i=0; i<m; i++) {
            int x1,y1,x2,y2,t;
            scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&t);
            ish[x1][y1] = 1;
            hh[x1][y1] = make_pair(make_pair(x2,y2),t);
        }

        for (int k=0; k<w*h; k++) {
            for (int i=0; i<w; i++) {
                for (int j=0; j<h; j++) {
                    if (dist[i][j]!=INF) {
                        for (int d=0; d<4; d++) {
                            int x = i + dx[d];
                            int y = j + dy[d];

                            if (x<0 || x>=w) continue;
                            if (y<0 || y>=h) continue;
                            if (gs[x][y]) continue;

                            int cost = 1;

                            if (ish[x][y]) {
                                int xx,yy;
                                xx = hh[x][y].first.first;
                                yy = hh[x][y].first.second;
                                cost += hh[x][y].second;
                                x = xx;
                                y = yy;
                            }

                            if (dist[x][y] > dist[i][j] + cost) {
                                dist[x][y] = dist[i][j] + cost;
                            }
                        }
                    }
                }
            }
        }

        bool never = 0;
        for (int i=0; i<w; i++) {
            for (int j=0; j<h; j++) {
                if (dist[i][j]!=INF) {
                    for (int d=0; d<4; d++) {
                        int x = i + dx[d];
                        int y = j + dy[d];

                        if (x<0 || x>=w) continue;
                        if (y<0 || y>=h) continue;
                        if (gs[x][y]) continue;

                        int cost = 1;

                        if (ish[x][y]) {
                            int xx,yy;
                            xx = hh[x][y].first.first;
                            yy = hh[x][y].first.second;
                            cost += hh[x][y].second;
                            x = xx;
                            y = yy;
                        }

                        if (dist[x][y] > dist[i][j] + cost) {
                            never = 1;
                        }
                    }
                }
            }
        }

        if (never) {
            cout<<"Never"<<endl;
        }
        else if (dist[w-1][h-1]==INF) {
            cout<<"Impossible"<<endl;
        }
        else cout<<dist[w-1][h-1]<<endl;
    }

    return 0;

}
