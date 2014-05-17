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

int n,m,q;
int a[50010];
int cnt[50010];
int px[150010], py[150010];
int tot[50010];
vector<int> e[50010];

void add_edge(int x, int y) {
    if (a[x]) tot[y]++;
    e[x].push_back(y);
}

void online(int x) {
    rep(it, e[x]) tot[*it]++;
    a[x] = 1;
}

void offline(int x) {
    rep(it, e[x]) tot[*it]--;
    a[x] = 0;
}

int count_online(int x) {
    int c = tot[x];
    rep(it, e[x]) c += a[*it];
    return c;
}

void del_edge(int x, int y) {
    if (a[x]) tot[y]--;
    rep(it, e[x]) if (*it==y) {
        e[x].erase(it);
        break;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>q;
    int o;
    cin>>o;
    for (int i=0; i<o; i++) {
        int x;
        scanf("%d",&x);
        a[x] = 1;
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d",px+i, py+i);
        cnt[px[i]]++; cnt[py[i]]++;
    }
    for (int i=0; i<m; i++) {
        if (cnt[px[i]]>cnt[py[i]]) {
            add_edge(py[i], px[i]);
        }
        else add_edge(px[i], py[i]);
    }
    for (int i=0; i<q; i++) {
        char c;
        scanf("%s", &c);
        if (c=='O') {
            int u;
            scanf("%d", &u);
            online(u);
        }
        else if (c=='F') {
            int u;
            scanf("%d", &u);
            offline(u);
        }
        else if (c=='A') {
            int u,v;
            scanf("%d%d",&u,&v);
            if (cnt[u]>cnt[v]) add_edge(v,u);
            else add_edge(u,v);
        }
        else if (c=='D') {
            int u,v;
            scanf("%d%d",&u,&v);
            if (cnt[u]>cnt[v]) del_edge(v,u);
            else del_edge(u,v);
        }
        else if (c=='C') {
            int u;
            scanf("%d", &u);
            printf("%d\n", count_online(u));
        }
    }

    return 0;

}
