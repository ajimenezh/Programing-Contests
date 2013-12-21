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
vector<int> e[200010];
int v[200010];
int par[200010];
int revpar[200010];

int dfs(int p, int q, int t) {
    int tmp = 0;
    for (int i=0; i<e[p].size(); i++) {
        if (abs(e[p][i])==q) continue;

        bool rev = (e[p][i]<0);

        if (rev) tmp++;

        tmp += dfs(abs(e[p][i]),p,rev);

    }

    v[p] = tmp;

    return tmp;
}

void dfs2(int p, int q, int t) {
    if (q!=-1) {
        v[p] = v[q];
        if (t) v[p]--;
        else v[p]++;
    }
    for (int i=0; i<e[p].size(); i++) {
        if (abs(e[p][i])==q) continue;
        bool rev = (e[p][i]<0);
        dfs2(abs(e[p][i]),p,rev);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(-a);
    }

    dfs(0,-1,0);
    dfs2(0,-1,0);

    int m = 1000000;
    for (int i=0; i<n; i++) {
        if (v[i]<m) m = v[i];
        //cout<<i+1<<" "<<v[i]<<endl;
    }
    cout<<m<<endl;
    for (int i=0; i<n; i++) if (v[i]==m) cout<<i+1<<" ";

    return 0;

}
