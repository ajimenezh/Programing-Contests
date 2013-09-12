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

#define MAXN 100010

int m;
int n;
vector<pair<int,int> > edges[MAXN];
priority_queue<pair<long long,int> > q;
long long dist[MAXN];
int pre[MAXN];
bool vis[MAXN];

void dfs(int p) {
    vis[p] = 1;
    rep(it,edges[p]) if (!vis[(*it).first]) {
        dfs((*it).first);
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for (int i=0; i<m; i++ ) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        edges[a].push_back(make_pair(b,c));
        edges[b].push_back(make_pair(a,c));
    }

    for (int i=0; i<n; i++) vis[i] = 0;
    dfs(0);

    if (!vis[n-1]) {
        cout<<-1;
    }
    else {
        for (int i=0; i<n; i++) dist[i] = 1LL<<62;
        for (int i=0; i<n; i++) pre[i] = -1;

        dist[0] = 0;
        pre[0] = 0;

        q.push(make_pair(0,0));

        while (!q.empty()) {
            int p = q.top().second;
            q.pop();
            if (p==n-1) break;

            long long d = dist[p];

            rep(it,edges[p]) {
                if (dist[(*it).first] > d + (*it).second) {
                    dist[(*it).first] = d + (*it).second;
                    pre[(*it).first] = p;
                    q.push(make_pair(-dist[(*it).first],(*it).first));
                }
            }
        }

        int p = n-1;
        vector<int> path;
        while (p!=pre[p]) {
            path.push_back(p+1);
            p = pre[p];
        }

        path.push_back(1);

        reverse(path.begin(),path.end());
        for (int i=0; i<path.size(); i++) cout<<path[i]<<" ";
    }

    return 0;

}
