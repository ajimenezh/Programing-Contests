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


int n,m;
pair<int,pair<int,int> > edges[50100];
int par[2010];
int rk[2010];
map<string,int> id;
int cnt;

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

bool connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (rk[a]>rk[b]) {
        par[a] = b;
        rk[b]++;
    }
    else {
        par[b] = a;
        rk[a]++;
    }
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    std::ios_base::sync_with_stdio (false);

    int cas;
    cin>>cas;
    while (cas--) {
        cin>>n>>m;
        for (int i=0; i<n; i++) par[i] = i;
        for (int i=0; i<n; i++) rk[i] = 0;
        id.clear();
        cnt = 0;
        for (int i=0; i<m; i++) {
            string a,b;
            int c;
            cin>>a>>b>>c;
            if (id.find(a)==id.end()) id[a] = cnt++;
            if (id.find(b)==id.end()) id[b] = cnt++;
            edges[i] = make_pair(c,make_pair(id[a],id[b]));
        }
        sort(edges,edges+m);
        int cost = 0;
        for (int i=0; i<m; i++) {
            if (connect(edges[i].second.first,edges[i].second.second)) {
                cost += edges[i].first;
            }
        }
        printf("%d\n",cost);
        if (cas!=0) printf("\n");
    }

    return 0;

}
