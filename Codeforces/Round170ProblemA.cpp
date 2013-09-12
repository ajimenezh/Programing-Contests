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
vector<int> e[101];
int t[101];
const int c = 150;
bool vis[101];

void dfs(int p) {
    vis[p] = 1;
    rep(it,e[p]) if (!vis[*it]) {
        dfs(*it);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int k;
    cin>>n>>m;
    for (int i=0; i<n; i++) {
        cin>>k;
        for (int j=0; j<k; j++) {
            int a;
            scanf("%d",&a);
            e[i].push_back(c+a);
            e[c+a].push_back(i);
        }
    }
    k = 0;
    for (int i=0; i<101; i++) vis[i] = 0;
    for (int i=0; i<n; i++) if (!vis[i]) {
        dfs(i);
        k++;
    }
    int s = 0;
    for (int i=0; i<n; i++) if (e[i].size()==0) s++;
    if (s!=k) cout<<k-1;
    else cout<<k;

    return 0;

}
