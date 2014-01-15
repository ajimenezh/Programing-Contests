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

int n1,p1;
int n2,p2;
map<string,int> id;
vector<pair<int,int> > e1[1100], e2[1100];

int dist[1100][1100];
priority_queue<pair<int,pair<int,int> > > q;

int solve() {
    for (int i=0; i<n1; i++) for (int j=0; j<n2; j++) dist[i][j] = 100000000;
    dist[0][0] = 0;
    while (!q.empty()) q.pop();
    q.push(make_pair(0,make_pair(0,0)));
    while (!q.empty()) {
        pair<int,int> p = q.top().second;
        q.pop();
        int a = p.first;
        int b = p.second;
        if (a==p1 && b==p2) break;

        int i = 0, j = 0;
       for (int i=0; i<e1[a].size(); i++) for (int j=0; j<e2[b].size(); j++) {
            if (e1[a][i].first==e2[b][j].first) {
                int u = e1[a][i].second;
                int v = e2[b][j].second;

                if (dist[u][v]>dist[a][b]+1) {
                    dist[u][v] = dist[a][b]+1;
                    q.push(make_pair(-dist[u][v],make_pair(u,v)));
                }
            }
        }
    }
    if (dist[p1][p2]==100000000) return -1;
    return dist[p1][p2];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::ios_base::sync_with_stdio (false);

    int cas;
    cin>>cas;
    while (cas--) {
        id.clear();
        int cnt = 0;
        cin>>n1>>p1;
        for (int i=0; i<n1; i++) e1[i].clear();
        int t;
        cin>>t;
        for (int i=0; i<t; i++) {
            int a,b;
            string s;
            int c;
            cin>>a>>s>>b;
            if (id.find(s)==id.end()) id[s] = cnt++;
            c = id[s];
            e1[a].push_back(make_pair(c,b));
            e1[b].push_back(make_pair(c,a));
        }
        for (int i=0; i<n1; i++) sort(e1[i].begin(),e1[i].end());

        cin>>n2>>p2;
        for (int i=0; i<n2; i++) e2[i].clear();
        cin>>t;
        for (int i=0; i<t; i++) {
            int a,b;
            string s;
            int c;
            cin>>a>>s>>b;
            if (id.find(s)==id.end()) continue;
            c = id[s];
            e2[a].push_back(make_pair(c,b));
            e2[b].push_back(make_pair(c,a));
        }
        for (int i=0; i<n2; i++) sort(e2[i].begin(),e2[i].end());

        int ans = solve();

        printf("%d\n",ans);
        if (cas!=0) printf("\n");

    }

    return 0;

}
