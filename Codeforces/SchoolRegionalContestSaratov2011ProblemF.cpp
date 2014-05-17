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
vector<int> e[110];

int dfs(int p, int q) {
    int c = 0;
    for (int i=0; i<e[p].size(); i++) {
        int u = e[p][i];
        if (u==q) continue;
        c = max(c, dfs(u,p));
    }
    return c+1;
}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    int res = 0;
    for (int i=0; i<t; i++) {
        cin>>n;
        for (int j=0; j<n; j++) e[j].clear();
        for (int j=0; j<n-1; j++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        int k = 0;
        for (int j=0; j<n; j++) {
            k = max(k, dfs(j,-1));
        }
        res += k-1;
    }
    cout<<res<<endl;

    return 0;

}
