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
vector<int> e[300010];
bool vis[300010];
bool used[300010];
bool done[300010];
int bad[300010];
set<pair<int,int> > s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for (int i=0; i<n; i++) used[i] = 0;
    for (int i=0; i<n; i++) bad[i] = e[i].size();
    for (int i=0; i<n; i++) s.insert(make_pair(-bad[i],i));

    while (true) {
        int q = (*(s.begin())).second;
        s.erase(make_pair(-bad[q],q));
        if (bad[q]<=1) break;
        used[q] ^= 1;
        bad[q] = 0;
        rep(it,e[q]) if (used[*it]==used[q]) bad[q]++;
        s.insert(make_pair(-bad[q],q));
        rep(it,e[q]) {
            s.erase(make_pair(-bad[*it],*it));
            bad[*it]=0;
            rep(it2,e[*it]) if (used[*it]==used[*it2]) bad[*it]++;
            s.insert(make_pair(-bad[*it],*it));
        }
    }

    for (int i=0; i<n; i++) {
        if (used[i]) {
            printf("1");
        }
        else printf("0");
    }


    return 0;

}
