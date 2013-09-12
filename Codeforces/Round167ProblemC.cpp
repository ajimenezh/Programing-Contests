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
vector<int> e[300010];
int c[300010];

bool dfs(int p, int v) {
    c[p] = v;
    bool done = 0;
    bool good = true;
    int c1 = 0 ,c2=0;
    rep(it,e[p]) {
        c[*it]==v ? c1++ : c2++;
    }
    done = c1>0;
    if (c1>1) return false;

    for (int i=0; i<e[p].size(); i++) {
        good = true;
        int k = 0;
        bool vis[3];
        for (int j=0; j<3; j++) vis[j] = false;
        rep(it,e[p]) {
            if (!done && c[*it]==-1 && k==i) {
                good = good && dfs(*it,v);
                done = false;
                vis[k] = 1;
            }
            else if (c[*it] == -1) {
                good = good && dfs(*it,1-v);
                vis[k] = 1;
            }
            k++;
        }
        if (good) return good;
        k = 0;
        rep(it,e[p]) if (vis[k++]) c[*it] = -1;
    }


    return good;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for (int i=0; i<n; i++) {
        c[i] = -1;
    }

    bool good = true;
    for (int i=0; i<n; i++) {
        if (c[i]==-1) good = good && dfs(i,0);
        if (!good) {
            cout<<-1;
            return 0;
        }

    if (!good) cout<<-1;
    else {
        for (int i=0; i<n; i++) printf("%d",c[i]);
    }

    return 0;

}
