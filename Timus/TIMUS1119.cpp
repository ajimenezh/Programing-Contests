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
bool diag[1010][1010];
double dist [1010][1010];
priority_queue<pair<double, int> > q;
int in,fn;
int k;
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    cin>>k;
    for (int i=0; i<k; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        diag[a-1][b-1] = 1;
    }
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) dist[i][j] = 20000000;
    dist[0][0] = 0;
    q.push(make_pair(0,0));

    while (!q.empty()) {
        int x = q.top().second/(m+1);
        int y = q.top().second%(m+1);
        q.pop();
        if (x==n && y==m) break;
        for (int k=0; k<4; k++) {
            if (x+dx[k]<0 || x+dx[k]>n) continue;
            if (y+dy[k]<0 || y+dy[k]>m) continue;
            if (dist[x+dx[k]][y+dy[k]]>dist[x][y]+1) {
                dist[x+dx[k]][y+dy[k]] = dist[x][y]+1;
                q.push(make_pair(-dist[x+dx[k]][y+dy[k]], (m+1)*(x+dx[k])+y+dy[k]));
            }
        }
        if (diag[x][y] && x+1<=n && y+1<=m && dist[x+1][y+1]>dist[x][y]+sqrt(2.0)) {
            dist[x+1][y+1] = dist[x][y]+sqrt(2.0);
            q.push(make_pair(-dist[x+1][y+1], (m+1)*(x+1)+y+1));
        }
    }

    printf("%d\n",(int)(round(dist[n][m]*100)+0.1));

    return 0;

}
