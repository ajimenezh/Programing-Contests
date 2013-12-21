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
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,-1,1};

int calc(int x, int y, int xx, int yy) {
    return min(abs(x-xx), abs(y-yy));
}

pair<pair<int,int>, int> next(int x, int y, int d) {
    int xx,yy;
    xx += dx[d]*n;
    yy += dy[d]*n;
    if (xx>=0 && xx<n && yy>=0 && yy<m) {
        if (xx>x) {
            if (yy>y) {
                return make_pair(make_pair(xx,yy),3);
            }
            else {
                return make_pair(make_pair(xx,yy),2);
            }
        }
        else {
            if (yy>y) {
                return make_pair(make_pair(xx,yy),0);
            }
            else {
                return make_pair(make_pair(xx,yy),1);
            }
        }
    }

    xx += dx[d]*m;
    yy += dy[d]*m;
    if (xx>=0 && xx<n && yy>=0 && yy<m) {
        if (xx>x) {
            if (yy>y) {
                return make_pair(make_pair(xx,yy),1);
            }
            else {
                return make_pair(make_pair(xx,yy),0);
            }
        }
        else {
            if (yy>y) {
                return make_pair(make_pair(xx,yy),2);
            }
            else {
                return make_pair(make_pair(xx,yy),3);
            }
        }
    }
    cout<<"hola"<<endl;
}

bool vis[4][100010][4];

int dfs(int x, int y, int d) {
    if (x==0) {
        if (vis[0][y][d]) return 0;
        vis[0][y][d] = 1;
    }
    if (x==m-1) {
        if (vis[1][y][d]) return 0;
        vis[1][y][d] = 1;
    }
    if (y==0) {
        if (vis[2][x][d]) return 0;
        vis[2][x][d] = 1;
    }
    if (y==n-1) {
        if (vis[3][x][d]) return 0;
        vis[3][x][d] = 1;
    }

    pair<pair<int,int>, int> p = next(x,y,d);
    return calc(x,y,p.first.first,p.first.second) + dfs(p.first.first,p.first.second,p.second);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m>>n;
    int x,y;
    cin>>x>>y;
    int d;
    string s;
    cin>>s;
    if (s=="DR") d = 0;
    if (s=="UR") d = 1;
    if (s=="DL") d = 3;
    if (s=="UL") d = 2;

    int ans = dfs(x,y,d);

    return 0;

}
