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
int p[1010];
int m;
vector<int> e[1010];
vector<int> c[1010];
int dist[1010];
int pre[1010];
priority_queue<pair<int,int> > q;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>p[i];
    cin>>m;
    for (int i=0; i<m; i++) {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        a--; b--;
        e[a].push_back(b);
        c[a].push_back(t);
    }
    int res = 1200000000;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) dist[j] = -1;
        for (int j=0; j<n; j++) pre[j] = -1;
        while (!q.empty()) q.pop();
        dist[i] = 0;
        q.push(make_pair(0,i));
        while (!q.empty()) {
            int p = q.top().second;
            q.pop();
            for (int j=0; j<e[p].size(); j++) {
                int u = e[p][j];
                if (dist[u]==-1 || dist[u]>c[p][j]) {
                    pre[u] = p;
                    dist[u] = c[p][j];
                    q.push(make_pair(-dist[u], u));
                }
            }
        }
        bool good = 1;
        for (int j=0; j<n; j++) if (j!=i && pre[j]==-1) {
            good = 0;
            break;
        }
        if (!good) continue;
        int tot = 0;
        for (int j=0; j<n; j++) if (pre[j]!=-1) tot += dist[j];
        res = min(res, tot);
        //cout<<i+1<<" "<<tot<<endl;
        //for (int i=0; i<n; i++) cout<<i+1<<" "<<dist[i]<<endl;
    }

    if (res==1200000000) cout<<-1;
    else cout<<res<<endl;

    return 0;

}
