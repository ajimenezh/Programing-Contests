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

int n,m,k;
vector<int> e[100010];
int path[100010];
int id[100010];
int t;

void dfs(int p) {
    path[++t] = p;
    id[p] = t;
    rep(it,e[p]) {
        if (!id[*it]) {
            dfs(*it);
            break;
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    dfs(0);
    int ma = 1000000;
    rep(it,e[path[t]]) {
        if (id[*it]<ma) {
            ma = id[*it];
        }
    }

    cout<<(t-ma+1)<<endl;
    for (int i=ma; i<=t; i++) {
        cout<<path[i]+1<<" ";
    }

    return 0;

}
