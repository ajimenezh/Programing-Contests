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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

vector<pii> e[3001];
map<pii,pii> dir;
bool vis[3001];
int depth[3001][3001];
int n;
int dp[3001][3001];
int now;
pii edges[3001];

void dfs(int p, int d)
{
    vis[p] = 1;
    depth[now][p] = d;

    for (int i=0; i<e[p].size(); i++)
    {
        int v = e[p][i].first;
        if (!vis[v])
        {
            dfs(v,d+1);
            dp[now][v]+=e[p][i].second;
            dp[now][p] += dp[now][v];
        }
    }
    return;
}

int main() {

    cin>>n;
    for (int i=0; i<n-1; i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].pb(mp(b,0));
        e[b].pb(mp(a,1));
        edges[i] = mp(a,b);
    }

    for (int i=0; i<n; i++)
    {
        fo(j,n) vis[j] = 0;
        fo(j,n) depth[i][j] = 0;
        fo(j,n) dp[i][j] = 0;
        now = i;
        dfs(i,1);
    }

    int ans = 1000000;
    for (int i=0; i<n-1; i++)
    {
        int a = edges[i].first;
        int b = edges[i].second;

        int v1 = 100000, v2 = 100000;
        for (int j=0; j<n; j++) if (depth[j][b]>depth[j][a])
        {
            v1 = min(dp[j][j]-dp[j][b],v1);
        }

        for (int j=0; j<n; j++) if (depth[j][b]<depth[j][a])
        {
            v2 = min(dp[j][j]-dp[j][a],v2);
        }

        ans = min(ans,v1+v2);
    }

    if (ans<10000) cout<<ans;
    else cout<<0<<endl;

	return 0;

}
