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

#define INF 1<<30

int n,m,k;
set<pair<int,pair<int,int> > > p;
int pre[3001][3001];
vector<int> e[3001];
int dist[3001][3001];
priority_queue<pair<int,pair<int,int> > > q;
int v[3001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<m; i++) {
        int x,y;
        scanf("%d%d",&x,&y);
        x--; y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i=0; i<k; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--; c--;
        p.insert(make_pair(a,make_pair(b,c)));
    }
    for (int i=0; i<n; i++) for (int j=0; j<3001; j++) dist[i][j] = INF;
    q.push(make_pair(-0,make_pair(-1,0)));

    int last = 0;
    while (!q.empty()) {
        int u = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        if (v==n-1) {
            last = u;
            break;
        }
        rep(it,e[v]) {
            if (u!=-1 && p.find(make_pair(u,make_pair(v,*it)))!=p.end()) continue;
            if (u!=-1 && dist[v][*it]>dist[u][v]+1) {
                dist[v][*it] = 1 + dist[u][v];
                q.push(make_pair(-dist[v][*it],make_pair(v,*it)));
                pre[v][*it] = u;
            }
            if (u==-1) {
                if (dist[v][*it]>1) {
                    dist[v][*it] = 1;
                    q.push(make_pair(-dist[v][*it],make_pair(v,*it)));
                    pre[v][*it] = u;
                }
            }
        }
    }

    if (dist[last][n-1]==INF) cout<<-1;
    else {
        printf("%d\n",dist[last][n-1]);
        int u = n-1;
        int k = 0;
        while (last!=-1) {
            v[k++] = u+1;
            int tmp = last;
            last = pre[last][u];
            u = tmp;
        }
        v[k++] = u+1;
        for (int i=k-1; i>=0; i--) {
            printf("%d ",v[i]);
        }
    }

    return 0;

}
