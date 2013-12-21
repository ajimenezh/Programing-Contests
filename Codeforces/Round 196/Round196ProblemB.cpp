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

int n,m,d;
int special[100010];
vector<int> e[100010];
int dist[4][100010];

void dfs(int p, int pre, int last, int ind) {
    dist[ind][p] = last;
    for (int i=0; i<e[p].size(); i++) {
        if (e[p][i]==pre) continue;
        dfs(e[p][i], p, last+1, ind);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>d;
    for (int i=0; i<m; i++) {
        int a;
        scanf("%d",&a);
        special[a-1] = 1;
    }
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int i;
    for (i=0; i<n; i++) if (special[i]) break;
    dfs(i,-1,0,0);
    int y = i;
    for (i=0; i<n; i++) if (special[i] && dist[0][i] > dist[0][y]) break;
    dfs(i,-1,0,1);
    y = i;
    for (i=0; i<n; i++) if (special[i] && dist[1][i] > dist[1][y]) break;
    dfs(i,-1,0,2);

    int cnt = 0;
    for (i=0; i<n; i++) if (dist[1][i] <= d && dist[2][i]<= d) cnt++;
    cout<<cnt<<endl;

    return 0;

}
