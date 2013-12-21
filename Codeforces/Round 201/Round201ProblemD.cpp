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

bool vis[1000010];
int best[1000010];
int n,m;
int s,t;
vector<int> e[1000010];

int dfs(int p) {
    if (p==t) return 0;
    vis[p] = 1;

    bool back = 0;
    int ma = 0;
    int mi = 10000000;
    for (int i=0; i<e[p].size(); i++) {
        if (vis[e[p][i]]) {
            back = 1;
            continue;
        }
        int tmp = dfs(e[p][i]);
        ma = max(ma,tmp);
        mi = min(mi,tmp);
    }
    if (back) {
        best[p] = 1 + mi;
    }
    else {
        best[p] = min(ma, mi + 1);
    }
    return best[p];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
    }
    cin>>s>>t;
    s--; t--;

    cout<<dfs(s)<<endl;

    return 0;

}
