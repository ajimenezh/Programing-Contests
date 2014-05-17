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

int n;
int m;
set<int> e[100010];
set<pair<int,int> > q;
vector<int> x, y, z;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a, &b);
        a--; b--;
        e[a].insert(b);
        e[b].insert(a);
    }

    for (int i=0; i<n; i++) q.insert(make_pair(e[i].size(), i));

    while (!q.empty()) {
        int p = (*q.begin()).second;
        q.erase(q.begin());
        if (e[p].size()>1) {
            int k = *e[p].begin();
            x.push_back(k);
            e[p].erase(e[p].begin());
            e[k].erase(p);

            q.erase(make_pair(e[k].size()+1, k));
            if (e[k].size()!=0) q.insert(make_pair(e[k].size(), k));

            y.push_back(p);
            k = *e[p].begin();
            z.push_back(k);
            e[p].erase(e[p].begin());
            e[k].erase(p);

            q.erase(make_pair(e[k].size()+1, k));
            if (e[k].size()!=0) q.insert(make_pair(e[k].size(), k));
        }
        else {
            int k = *e[p].begin();
            e[k].erase(p);
            e[p].erase(k);
            if (e[k].size()==0) {
                cout<<"No solution";
                return 0;
            }
            x.push_back(p);
            y.push_back(k);
            int k2 = *e[k].begin();
            e[k].erase(k2);
            e[k2].erase(k);
            z.push_back(k2);

            q.erase(make_pair(e[k].size()+2, k));
            if (e[k].size()!=0) q.insert(make_pair(e[k].size(), k));

            q.erase(make_pair(e[k2].size()+1, k2));
            if (e[k2].size()!=0) q.insert(make_pair(e[k2].size(), k2));
        }
    }

    for (int i=0; i<x.size(); i++) {
        printf("%d %d %d\n", x[i]+1, y[i]+1, z[i]+1);
    }

    return 0;

}
