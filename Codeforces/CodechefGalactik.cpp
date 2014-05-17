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
vector<int> e[100010];
int c[100010];
int sum;
bool vis[100010];

int dfs(int p) {
    vis[p] = 1;
    int t = c[p];
    for (int i=0; i<e[p].size(); i++) if (!vis[e[p][i]]) {
        int tmp = dfs(e[p][i]);
        if (tmp>=0) {
            if (t<0) t = tmp;
            else t = min(t,tmp);
        }
    }
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    for (int i=0; i<n; i++) scanf("%d",c+i);

    sum = 0;
    int mi = 1000000;
    int cnt = 0;
    bool bad = 0;
    for (int i=0; i<n; i++) if (!vis[i]) {
        int t = dfs(i);
        if (t<0) {
            bad = 1;
        }
        sum += t;
        mi = min(t,mi);
        cnt++;
    }

    if (bad) {
        if (cnt==1) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    else {
        sum = mi*(cnt-1) + (sum-mi);

        cout<<sum<<endl;
    }

    return 0;

}
