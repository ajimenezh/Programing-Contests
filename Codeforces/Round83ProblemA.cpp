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

pair<int,int> next[1010];
pair<int,int> last[1010];
vector<pair<pair<int,int>, int> > v;
int n;
int m;
bool vis[1010];

void dfs(int i, int last, int c) {
    if (vis[i]) return;
    vis[i] = 1;
    if (next[i]==make_pair(0,0)) {
        if (i!=last) v.push_back(make_pair(make_pair(last,i),c));
    }
    else {
        dfs(next[i].first, last, min(c, next[i].second));
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b,d;
        scanf("%d%d%d",&a,&b,&d);
        a--; b--;
        next[a] = make_pair(b,d);
        last[b] = make_pair(a,d);
    }
    for (int i=0; i<n; i++) if (last[i]==make_pair(0,0) && !vis[i]) dfs(i, i, 10000000);
    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++) {
        cout<<v[i].first.first+1<<" "<<v[i].first.second+1<<" "<<v[i].second<<"\n";
    }

    return 0;

}
