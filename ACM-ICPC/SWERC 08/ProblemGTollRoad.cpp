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
pair<int,pair<int,int> > v[100100];
vector<int> e[200010];
vector<int> c[200010];
int best[200010][2];

int dfs(int p, int pre=-1) {
    int sum = 0;
    for (int i=0; i<e[p].size(); i++) {
        if (e[p][i]==pre) continue;
        int tmp = dfs(e[p][i],p);
        if (c[p][i]+tmp>0) {
            sum += c[p][i]+tmp;
        }
        best[p][1] = max(best[p][1], tmp);
    }

    best[p][0] = sum;
    best[p][1] = max(best[p][1], sum);

    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        int m = 0;
        for (int i=0; i<n; i++) {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            a--; b--;
            v[i] = make_pair(w, make_pair(a,b));
            e[a].clear();
            e[b].clear();
            c[a].clear();
            c[b].clear();
            best[a][0] = 0;
            best[a][1] = 0;
            best[b][0] = 0;
            best[b][1] = 0;
        }
        for (int i=0; i<n; i++) {
            e[v[i].second.first].push_back(v[i].second.second);
            e[v[i].second.second].push_back(v[i].second.first);
            c[v[i].second.first].push_back(v[i].first);
            c[v[i].second.second].push_back(v[i].first);
        }
        dfs(v[0].second.first);

        int ans = 0;
        for (int i=0; i<n; i++) {
            ans = max(ans, best[v[i].second.first][0]);
            ans = max(ans, best[v[i].second.first][1]);
            ans = max(ans, best[v[i].second.second][0]);
            ans = max(ans, best[v[i].second.second][1]);
        }
        printf("%d\n",ans);
    }

    return 0;

}

