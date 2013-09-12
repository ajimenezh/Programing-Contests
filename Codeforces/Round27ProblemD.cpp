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

int n,m;
pair<int,int> v[101];
vector<int> p;
set<int> e[201];
int vis[201];
bool flag[101];
int parent[201];

bool dfs(int u, int v, int f) {
    //cout<<u<<" "<<v<<endl;
    vis[u] = 1;
    flag[u] = f;
    parent[u] = v;
    bool good = true;
    rep(it,e[u]) if (*it!=v) {
        if (vis[*it]) {
            if (flag[*it]==1-f) continue;
            return false;
        }
        else good = good && dfs(*it,u,1-f);
    }
    return good;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        scanf("%d%d",&v[i].first,&v[i].second);
        v[i].first--; v[i].second--;
        if (v[i].second < v[i].first) {
            int tmp = v[i].first;
            v[i].first = v[i].second;
            v[i].second = tmp;
        }
    }
    for (int i=0; i<m; i++) {
        for (int j=0; j<m; j++) {
            if (v[i].first>v[j].first && v[i].first<v[j].second && v[i].second>v[j].second) {
                e[i].insert(j);
                e[j].insert(i);
            }
        }
    }

    for (int i=0; i<m; i++) {
        if (!vis[i] && !dfs(i,i,0)) {
            cout<<"Impossible";
            return 0;
        }
    }
    for (int i=0; i<m; i++) {
        if (flag[i]) cout<<'o';
        else cout<<'i';
    }

    return 0;

}
