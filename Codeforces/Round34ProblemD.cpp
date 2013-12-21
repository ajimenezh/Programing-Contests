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

int n,r1,r2;
vector<int> e[50010];
int par[50010];

void dfs(int p, int q) {
    par[p] = q;
    for (int i=0; i<e[p].size(); i++) {
        int u = e[p][i];
        if (u==q) continue;
        dfs(u,p);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>r1>>r2;
    r1--; r2--;
    int k = 0;
    if (k==r1) k++;
    for (int i=0; i<n-1; i++) {
        int p;
        scanf("%d",&p);
        p--;
        e[k].push_back(p);
        e[p].push_back(k);
        k++;
        if (k==r1) k++;
    }
    dfs(r2,-1);
    for (int i=0; i<n; i++) if (par[i]!=-1) cout<<par[i]+1<<" ";

    return 0;

}
