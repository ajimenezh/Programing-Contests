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
bool vis[110];
bool done[110];
vector<int> e[110];
vector<int> v1,v2;

void dfs(int p, int c) {
    vis[p] = 1;
    if (c) v1.push_back(p+1);
    for (int i=0; i<e[p].size(); i++) {
        if (vis[e[p][i]]) continue;
        dfs(e[p][i],1-c);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        while (cin>>a && a!=0) e[i].push_back(a-1);
    }
    for (int i=0; i<n; i++) if (!vis[i]) dfs(i,1);
    cout<<v1.size()<<endl;
    for (int i=0; i<v1.size(); i++) cout<<v1[i]<<" "; cout<<endl;

    return 0;

}
