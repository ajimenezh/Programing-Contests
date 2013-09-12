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

int n,D;
int d[130][130];
int x[130], y[130];
bool vis[130];

bool bfs(int x) {
    int q[130];
    int in, fn;
    in = fn = 0;
    q[fn++] = 0;
    bool vis2[130];
    memset(vis2,0,sizeof(vis2));
    vis2[0] = 1;
    int cnt = 1;

    while (in<fn) {
        int cur = q[in++];

        for (int i=0; i<n; i++) {
            if (i==cur || vis2[i]) continue;
            if ((i<x || vis[i]) && d[cur][i]<=D) {
                vis2[i] = 1;
                q[fn++] = i;
                cnt++;
            }
            else if (d[cur][i]<=D/2) {
                vis2[i] = 1;
                cnt++;
            }
        }
        if (cnt>=n) return 1;
    }
    if (x==n) {
        for (int i=0; i<n; i++) if (!vis2[i]) return 0;
        return 1;
    }
    return 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d%d",&n,&D)!=EOF) {
        for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) {
            double dist = 0;
            dist = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
            dist = (int)ceil(sqrt(1.0*dist));
            d[i][j] = d[j][i] = dist;
        }

        if (!bfs(n)) {
            cout<<-1<<endl;
        }
        else {
            memset(vis,0,sizeof(vis));
            for (int i=n-1; i>0; i--) {
                if (!bfs(i)) {
                    vis[i] = 1;
                }
            }
            bool flag = 0;
            for (int i=n-1; i>0; i--) {
                if (flag||vis[i]) {
                    flag = 1;
                    cout<<vis[i];
                }
            }
            cout<<1<<endl;
        }
    }

    return 0;

}
