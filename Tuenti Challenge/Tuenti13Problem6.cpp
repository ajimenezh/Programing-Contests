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

#define MAXN 2000

int t;
int n,m;
int s;
int w;
char buf[MAXN][MAXN];
int x,y;
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
pair<int,int> next[MAXN][MAXN][4];
int dist[MAXN][MAXN];

int distance(int a, int b, int i) {
    return (abs(a-next[a][b][i].first)+abs(b-next[a][b][i].second));
}

int solve(int a, int b) {

    priority_queue<pair<int,pair<int,int> > > q;

    q.push(make_pair(0,make_pair(a,b)));
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) dist[i][j] = 1<<30;
    dist[a][b] = 0;

    while (!q.empty()) {
        int c = q.top().first;
        pair<int,int> p = q.top().second;
        a = p.first;
        b = p.second;
        //cout<<a<<" "<<b<<endl;
        if (buf[a][b]=='O') break;
        q.pop();
        for (int i=0; i<4; i++) {
            if (next[a][b][i].first==a && next[a][b][i].second==b) continue;
            if (dist[next[a][b][i].first][next[a][b][i].second]>dist[a][b]+w*s+distance(a,b,i)) {
                dist[next[a][b][i].first][next[a][b][i].second]=dist[a][b]+w*s+distance(a,b,i);
                q.push(make_pair(-dist[next[a][b][i].first][next[a][b][i].second],make_pair(next[a][b][i].first,next[a][b][i].second)));
            }
        }
    }

    return (dist[a][b]%s>=(s-1)/2+1)?dist[a][b]/s+1:dist[a][b]/s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>m>>n>>s>>w;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
            cin>>buf[i][j];
            if (int(buf[i][j])==-62) {
                cin>>buf[i][j];
                buf[i][j] = '.';
            }
        }
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (buf[i][j]=='X') {
            x = i; y = j;
            break;
        }

        for (int i=0; i<n; i++) for (int j=0; j<m; j++) for (int k=0; k<4; k++) next[i][j][k] = make_pair(-1,-1);

        for (int b=0; b<m; b++) {
            for (int a=0; a<n; a++) if (buf[a][b]!='#') {

                    if (buf[a+dx[3]][b+dy[3]]=='#'|| ((a+dx[3]>=n || a+dx[3]<0) || (b+dy[3]>=m || b+dy[3]<0))) next[a][b][3] = make_pair(a,b);
                    else {
                        next[a][b][3] = next[a+dx[3]][b+dy[3]][3];
                    }
            }
        }

        for (int a=0; a<n; a++) {
            for (int b=0; b<m; b++) if (buf[a][b]!='#') {


                    if (buf[a+dx[2]][b+dy[2]]=='#'|| ((a+dx[2]>=n || a+dx[2]<0) || (b+dy[2]>=m || b+dy[2]<0))) next[a][b][2] = make_pair(a,b);
                    else {
                        next[a][b][2] = next[a+dx[2]][b+dy[2]][2];
                    }
            }
        }

        for (int b=m-1; b>=0; b--) {
            for (int a=n-1; a>=0; a--) if (buf[a][b]!='#') {

                    if (buf[a+dx[0]][b+dy[0]]=='#'|| ((a+dx[0]>=n || a+dx[0]<0) || (b+dy[0]>=m || b+dy[0]<0))) next[a][b][0] = make_pair(a,b);
                    else {
                        next[a][b][0] = next[a+dx[0]][b+dy[0]][0];
                    }
            }
        }

        for (int a=n-1; a>=0; a--) {
            for (int b=m-1; b>=0; b--) if (buf[a][b]!='#') {


                if (buf[a+dx[1]][b+dy[1]]=='#' || ((a+dx[1]>=n || a+dx[1]<0) || (b+dy[1]>=m || b+dy[1]<0))) next[a][b][1] = make_pair(a,b);
                else {
                    next[a][b][1] = next[a+dx[1]][b+dy[1]][1];
                }
            }
        }

        //for (int i=0; i<n; i++) { for (int j=0; j<m; j++) cout<<int(buf[i][j])<<" "; cout<<endl;}
        //for (int i=0; i<n; i++) { for (int j=0; j<m; j++) cout<<next[i][j][3].first<<" "; cout<<endl;}
        //for (int i=0; i<n; i++) { for (int j=0; j<m; j++) cout<<next[i][j][3].second<<" "; cout<<endl;}

        int res = solve(x,y);
        printf("%d\n",res);
    }

    return 0;

}
