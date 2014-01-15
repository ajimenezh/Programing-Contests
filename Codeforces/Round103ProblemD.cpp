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

int n,m,s, l;
vector<int> e[100010];
vector<int> c[100010];
int dist[100010];
int pre[100010];
priority_queue<pair<int,int> > q;
set<pair<pair<int,int>,int> > all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>s;
    s--;
    for (int i=0; i<m; i++) {
        int a,b,t;
        scanf("%d%d%d",&a,&b,&t);
        a--; b--;
        e[a].push_back(b);
        c[a].push_back(t);
        e[b].push_back(a);
        c[b].push_back(t);
    }
    cin>>l;
    for (int i=0; i<n; i++) dist[i] = 1000000000;
    for (int i=0; i<n; i++) pre[i] = -1;
    int res = 0;
    dist[s] = 0;
    q.push(make_pair(0,s));

    int t1 = 0, t2 = 0;
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        for (int i=0; i<e[p].size(); i++) {
            int u = e[p][i];
            if (dist[u]>dist[p]+c[p][i]) {
                dist[u] = dist[p]+c[p][i];
                pre[u] = p;
                q.push(make_pair(-dist[u], u));
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (dist[i]==l) res++;
        //cout<<i<<" "<<dist[i]<<endl;
        if (dist[i]>=l) continue;
        for (int j=0; j<e[i].size(); j++) {
            int k = c[i][j];
            int u = e[i][j];
            if (pre[i]==u) continue;
            if (dist[i]+k>l && dist[i]+dist[u]+k>=2*l) {
                if (all.find(make_pair(make_pair(i,u),l-dist[i]))==all.end()) {
                    //cout<<i<<" "<<u<<" "<<k<<" "<<l-dist[i]<<endl;
                    all.insert(make_pair(make_pair(i,u),l-dist[i]));
                    all.insert(make_pair(make_pair(u,i),k+dist[i]-l));
                    res++;
                }
            }
        }
    }

    cout<<res<<endl;

    return 0;

}
