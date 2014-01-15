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
set<int> e[501];
set<int> r[501];
int a[501];
int q[1000];
bool vis[501];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) {
            cin>>a[i];
            a[i]--;
        }
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) r[i].clear();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                e[a[i]].insert(a[j]);
                r[a[j]].insert(a[i]);
            }
        }
        cin>>m;
        for (int i=0; i<m; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            x--; y--;
            if (e[x].find(y)!=e[x].end()) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            e[y].erase(x);
            r[x].erase(y);
            e[x].insert(y);
            r[y].insert(x);
        }

        int in = 0;
        int fn = 0;

        vector<int> v;

        for (int i=0; i<n; i++) vis[i] = 0;
        for (int i=0; i<n; i++) if (r[i].size()==0) {
            q[fn++] = i;
            vis[i] = 1;
        }

        while (in<fn) {
            if (fn>in+1) {
                for (int i=in; i<fn; i++) v.push_back(-1);
                while (in<fn) {
                    int p = q[in++];
                    rep(it,e[p]) r[*it].erase(p);
                    e[p].clear();
                    vis[p] = 1;
                }
                for (int i=0; i<n; i++) if (!vis[i] && r[i].size()==0) q[fn++] = i;
            }
            else {
                v.push_back(q[in]);
                while (in<fn) {
                    int p = q[in++];
                    rep(it,e[p]) r[*it].erase(p);
                    e[p].clear();
                    vis[p] = 1;
                }
                for (int i=0; i<n; i++) if (!vis[i] && r[i].size()==0) q[fn++] = i;
            }
        }

        if (v.size()!=n) cout<<"IMPOSSIBLE"<<endl;
        else {
            for (int i=0; i<v.size(); i++) {
                if (v[i]==-1) cout<<"? ";
                else cout<<v[i]+1<<" ";
            }
            cout<<endl;
        }
    }

    return 0;

}
