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

int n;
int a[101];
int r1,c1,r2,c2;
vector<int> dist[110];
queue<int> q;

void bfs(int x, int y) {
    dist[x][y] = 0;
    q.push(y*n+x);
    while(!q.empty()) {
        int p = q.front();
        q.pop();
        x = p%n;
        y = p/n;
        if (y!=0 && dist[x][y-1]==-1) {
            dist[x][y-1] = dist[x][y]+1;
            q.push((y-1)*n+x);
        }
        if (y!=dist[x].size()-1 && dist[x][y+1]==-1) {
            dist[x][y+1] = dist[x][y]+1;
            q.push((y+1)*n+x);
        }
        if (x!=0) {
            int ty = min((int)dist[x-1].size()-1, y);
            if (dist[x-1][ty]==-1) {
                dist[x-1][ty] = dist[x][y]+1;
                q.push((ty)*n+x-1);
            }
        }
        if (x!=n-1) {
            int ty = min((int)dist[x+1].size()-1, y);
            if (dist[x+1][ty]==-1) {
                dist[x+1][ty] = dist[x][y]+1;
                q.push((ty)*n+x+1);
            }
        }
    }
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) dist[i] = vector<int> (a[i]+1,-1);
    cin>>r1>>c1>>r2>>c2;

    bfs(r1-1,c1-1);

    cout<<dist[r2-1][c2-1]<<endl;

    return 0;

}
