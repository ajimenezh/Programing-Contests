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

int n, m;
long long c[10010];
vector<pair<int,int> > tr[10010];
bool vis[10010];

int main() {

    freopen("dwarf.in","r",stdin);
    freopen("dwarf.out","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",c+i);
    for (int i=0; i<m; i++) {
        int a,x,y;
        scanf("%d%d%d",&a,&x,&y);
        a--; x--; y--;
        tr[x].push_back(make_pair(y,a));
        tr[y].push_back(make_pair(x,a));
    }

    for (int i=0; i<n; i++) {
        int best = 2000000010;
        int p = -1;
        for (int j=0; j<n; j++) {
            if (!vis[j] && c[j]<best) {
                best = c[j];
                p = j;
            }
        }
        vis[p] = 1;
        for (int k=0; k<tr[p].size(); k++) {
            int a = tr[p][k].second;
            int y = tr[p][k].first;
            if (c[a] > c[y] + c[p]) {
                c[a] = c[y] + c[p];
            }
        }
    }

    cout<<c[0]<<endl;

    return 0;

}
