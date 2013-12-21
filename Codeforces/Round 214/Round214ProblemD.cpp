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
;
int n,m;
vector<int> e[1010];
vector<int> ll[1010];
vector<int> rr[1010];
map<pair<int,int>,int> dist;
pair<int,pair<int,int> > q[10000000];
int in,fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    int k = 0;
    for (int i=0; i<m; i++) {
        int a,b,l,r;
        if (a==b) continue;
        scanf("%d%d%d%d",&a,&b,&l,&r);
        e[a-1].push_back(b-1);
        e[b-1].push_back(a-1);
        ll[a-1].push_back(l);
        rr[a-1].push_back(r);
        ll[b-1].push_back(l);
        rr[b-1].push_back(r);
    }

    in = 0;
    fn = 0;
    q[fn++] = (make_pair(1000000,make_pair(0,1)));
    dist[make_pair(0,1)] = 1000000;

    while (in<fn) {
        int p = q[in].second.first;
        int l = q[in].second.second;
        int r = q[in++].first;


        for (int i=0; i<e[p].size(); i++) {
            int u = e[p][i];
            int l1 = ll[p][i];
            int r1 = rr[p][i];

            if (l1>r || r1<l) continue;

            int l2 = max(l1,l);
            int r2 = min(r1,r);

            if (dist.find(make_pair(u,l2))==dist.end()) {
                dist[make_pair(u,l2)] = r2;
                q[fn++] = make_pair(r2,make_pair(u,l2));
            }
            else if (dist[make_pair(u,l2)]<r2) {
                dist[make_pair(u,l2)] = r2;
                q[fn++] = make_pair(r2,make_pair(u,l2));
            }
        }
    }

    int x = 0;
    rep(it, dist) {
        if ((*it).first.first==n-1) {
            x = max((*it).second-(*it).first.second+1,x);
        }
    }

    if (!x) cout<<"Nice work, Dima!";
    else cout<<x<<endl;

    return 0;

}
