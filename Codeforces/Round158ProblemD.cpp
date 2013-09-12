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

#define MAXN 100010

int n;
int nw;
int nb;

set<pair<int,int> > wp;
vector<pair<int,int> > bp;
vector<pair<int,int> > edges[MAXN];

bool vis[MAXN];

struct UF {
    int si;

    int par[MAXN];
    int rank[MAXN];

    UF(int s = 0) {
        si = s;
        for (int i=0; i<s; i++) par[i] = i;
        for (int i=0; i<s; i++) rank[i] = 1;
    }

    int find(int i) {
        par[i] = par[par[i]];
        return par[i];
    }

    void connect(int a, int b) {
        int c1 = rank[a];
        int c2 = rank[b];

        if (c1>c2) {
            par[b] = par[par[a]];
            rank[a] = c1+c2;
        }
        else {
            par[a] = par[par[b]];
            rank[b] = c1+c2;
        }
    }
};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    UF uf = UF(n);

    for (int i=0; i<n; i++) vis[i] = 0;

    nw = 0;
    nb = 0;

    for (int i=0; i<n; i++) {

        int c,w;
        scanf("%d%d",&c,&w);

        if (c==1) {
            bp.push_back(make_pair(i,w));
            nb++;
        }
        else {
            wp.insert(make_pair(-w,i));
            nw++;
        }
    }

    for (int i=0; i<nb; i++) {
        int w = bp[i].second;
        int ind = bp[i].first;
        bool done = false;
        while (w>0 || !done) {

            set<pair<int,int> >::iterator it = wp.begin();
            while (it != wp.end() && uf.find((*it).second==uf.find(ind))) {
                it++;
            }

            if (it==wp.end()) {
                cout<<"Error"<<endl;
                return 0;
            }

            cout<<ind<<" "<<w<<endl;

            pair<int,int> p = *it;


            wp.erase(wp.begin());

            int tmp = min(-p.first,w);

            //cout<<tmp<<" "<<w<<" "<<p.first<<endl;

            w -= tmp;
            p.first += tmp;

            //cout<<tmp<<" "<<w<<" "<<p.first<<endl;
            //int df; cin>>df;

            edges[ind].push_back(make_pair(p.second,tmp));

            wp.insert(p);

            uf.connect(p.second,ind);

            done = true;

            vis[p.second] = true;
            vis[ind] = true;
        }
    }

    for (int i=0; i<n; i++) {

        if (edges[i].size()!=0) {
            for (int j=0; j<edges[i].size(); j++) {
                cout<<i+1<<" "<<edges[i][j].first+1<<" "<<edges[i][j].second<<endl;
            }
        }
    }

    for (int i=0; i<n; i++) if (!vis[i]) {
        cout<<i+1<<" "<<bp[0].first+1<<" "<<0<<endl;
    }

    return 0;

}
