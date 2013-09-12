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

int n;
vector<int> e[1501];
vector<int> v[1501];
int x[1501],y[1501];
int depth[1501];
int par[1501];
int q[1600];
int vis[1501];
pair<int,int> P[1501];
map<pair<int,int>, int> mp;
int sol[1501];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i=0; i<n; i++) {
        scanf("%d%d",x+i,y+i);
        mp[make_pair(x[i],y[i])] = i+1;
    }

    for (int i=0; i<n; i++) vis[i] = 0;
    depth[0] = 0;
    vis[0] = 1;
    int in = 0, fn = 0;
    q[fn++] = 0;
    par[0] = -1;
    int m = 0;
    v[0].push_back(0);

    while (in!=fn) {
        int p = q[in++];
        vis[p] = 1;
        rep(it,e[p]) if (!vis[*it]) {
            q[fn++] = *it;
            par[*it] = p;
            depth[*it] = depth[p]+1;
            v[depth[*it]].push_back(*it);
            m = max(m,depth[*it]);
        }
    }

    for (int i=0; i<n; i++) P[i] = make_pair(y[i],x[i]);
    sort(P,P+n);
    reverse(P,P+n);

    int k = 0;
    for (int i=0; i<=m; i++) {
        vector<pair<int,int> > v2;
        for (int j=0; j<v[i].size(); j++) v2.push_back(P[k++]);
        for (int j=0; j<v2.size(); j++) {
            int tmp = v2[j].first;
            v2[j].first = v2[j].second;
            v2[j].second = tmp;
        }
        sort(v2.begin(),v2.end());
        for (int j=0; j<v[i].size(); j++) {
            sol[v[i][j]] = mp[v2[j]];
            //cout<<i<<" "<<v[i][j]<<" "<<mp[v2[j]]<<endl;
        }
    }

    for (int i=0; i<n; i++) printf("%d ",sol[i]);

    return 0;

}
