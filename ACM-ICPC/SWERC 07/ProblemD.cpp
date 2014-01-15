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

int xs,ys,xt,yt;
int n,m;
int a[310][310];
int dist[300][300][6][6];
priority_queue<pair<int,int> > q;
int in,fn;

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int cas;
    cin>>cas;
    while (cas--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) {
            for (int j=0; j<m; j++) {
                scanf("%d",&a[i][j]);
            }
        }
        cin>>xs>>ys;
        cin>>xt>>yt;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            for (int k=0; k<6; k++) {
                for (int t=0; t<6; t++) dist[i][j][k][t] = 100000000;
            }
        }
        dist[xs][ys][0][0] = 0;
        int tmp = (xs*m + ys)*100;
        if (a[xs][ys]>1) tmp += (a[xs][ys]/10)*8 + a[xs][ys]%10-1;
        while (!q.empty()) q.pop();
        q.push(make_pair(0,tmp));

        while (!q.empty()) {
            int qq = q.top().second;
            q.pop();
            int tmp = qq/100;
            int tmp2 = qq%100;
            int x = tmp/m;
            int y = tmp%m;
            int r = tmp2/8;
            int s = tmp2%8;
            //cout<<x<<" "<<y<<" "<<" "<<r<<" "<<s<<" "<<dist[x][y][r][s]<<endl;

            if (x==xt && y==yt) break;

            for (int k=0; k<4; k++) {
                int u = x + (s+1)*dx[k];
                int v = y + (s+1)*dy[k];

                if (u<0 || u>=n || v<0 || v>=m) continue;
                if (a[u][v]==0) continue;

                if (a[u][v]>1) {

                    bool good = 0;

                    for (int kk=0; kk<4; kk++) {
                        int ss = a[u][v]%10;
                        int uu = u + ss*dx[kk];
                        int vv = v + ss*dy[kk];

                        if (uu<0 || uu>=n || vv<0 || vv>=m) continue;
                        if (a[uu][vv]==0) continue;

                        good = 1;
                        break;
                    }

                    if (good) {
                        if (dist[u][v][a[u][v]/10][(a[u][v]%10)-1]<1 + dist[x][y][r][s]) continue;
                        dist[u][v][a[u][v]/10][(a[u][v]%10)-1] = 1 + dist[x][y][r][s];
                        q.push(make_pair(-dist[u][v][a[u][v]/10][(a[u][v]%10)-1],(u*m+v)*100 + 8*(a[u][v]/10) + (a[u][v]%10) - 1));
                    }
                    else {
                        if (dist[x][y][0][0]<1 + dist[x][y][r][s]) continue;
                        dist[x][y][0][0] = 1 + dist[x][y][r][s];
                        q.push(make_pair(-dist[x][y][0][0] ,(x*m+y)*100));
                    }
                }
                else {
                    int nr = r-1;
                    if (nr<=0) {
                        nr = 0;
                        int ns = s;
                        if (nr==0) ns = 0;
                        if (dist[u][v][nr][ns]>dist[x][y][r][s] + 1) {
                            dist[u][v][nr][ns] = dist[x][y][r][s] + 1;
                            q.push(make_pair(-dist[u][v][nr][ns],(u*m+v)*100 + 8*nr + ns ));
                        }
                    }
                    else {
                        bool good = 0;

                        for (int kk=0; kk<4; kk++) {
                            int uu = u + (s+1)*dx[kk];
                            int vv = v + (s+1)*dy[kk];

                            if (uu==x && vv==y) continue;
                            if (uu<0 || uu>=n || vv<0 || vv>=m) continue;
                            if (a[uu][vv]==0) continue;

                            good = 1;
                            break;
                        }

                        if (good) {
                            if (dist[u][v][r-1][s]<1 + dist[x][y][r][s]) continue;
                            dist[u][v][r-1][s] = 1 + dist[x][y][r][s];
                            q.push(make_pair(-dist[u][v][r-1][s] ,(u*m+v)*100 + 8*(r-1) + s));
                        }
                        else {
                            if (dist[x][y][0][0]<1 + dist[x][y][r][s]) continue;
                            dist[x][y][0][0] = 1 + dist[x][y][r][s];
                            q.push(make_pair(-dist[x][y][0][0] ,(x*m+y)*100));
                        }
                    }
                }

            }

        }

        tmp = -1;
        for (int i=0; i<6; i++) for (int j=0; j<6; j++) {
            if (dist[xt][yt][i][j]!=-1) {
                if (tmp==-1) tmp = dist[xt][yt][i][j];
                else tmp = min(tmp, dist[xt][yt][i][j]);
            }
        }

        if (tmp==-1) printf("IMPOSSIBLE\n");
        else printf("%d\n",tmp);
        if (cas!=0) printf("\n");
    }

    return 0;

}
