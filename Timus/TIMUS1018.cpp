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

#define INF 1000000000

int dp[101][101];
vector<int> e[101];
vector<int> t[101];
int c[101];
int n,q;
int s[101];
int tot[101];
int l[101];
int r[101];
pair<int,int> dfs(int p,int pre, int a) {
    c[p] = a;
    s[p] = 1;
    tot[p] = a;
    for (int i=0; i<e[p].size(); i++) if (e[p][i]!=pre) {
        pair<int,int> b = dfs(e[p][i],p,t[p][i]);
        s[p] += b.first;
        tot[p] += b.second;
        if (l[p]!=0) r[p] = e[p][i];
        else l[p] = e[p][i];
    }
    return make_pair(s[p],tot[p]);
}

int solve(int p, int u) {
    if (u==0) return 0;
    if (u==s[p]) return tot[p];
    if (u>s[p]) return INF;
    if (dp[p][u]) return dp[p][u];

    int tmp = INF;

    for (int i=0; i<=u; i++) {
        tmp = min(tmp, solve(l[p],i) + (r[p]!=0?solve(r[p],u-i):(u-i==0?0:INF)));
    }
    dp[p][u] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>q;
    for (int i=0; i<n-1; i++) {
        int a,b,d;
        cin>>a>>b>>d;
        a--; b--;
        e[a].push_back(b);
        t[a].push_back(d);
        e[b].push_back(a);
        t[b].push_back(d);
    }

    dfs(0,-1, 0);

    int res = solve(0,n-1-q);

    cout<<tot[0]-res<<endl;

    return 0;

}
