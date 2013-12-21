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

#define y0 Y0
#define y1 Y1

int x0,y0,x1,y1;
int n;
int r[100010];
int a[100010];
int b[100010];
map<pair<int,int>,int> dist;
set<pair<int,int> > all;
pair<int,int> q[100010];
int in,fn;
int dx[] = {1,0,-1,0,1,1,-1,-1};
int dy[] = {0,1,0,-1,1,-1,1,-1};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x0>>y0>>x1>>y1>>n;

    for (int i=0; i<n; i++) scanf("%d%d%d", r+i,a+i,b+i);

    for (int i=0; i<n; i++) {
        for (int j=a[i]; j<=b[i]; j++) {
            all.insert(make_pair(r[i],j));
            dist[make_pair(r[i],j)] = -1;
        }
    }
    pair<int,int> p = make_pair(x0,y0);
    dist[p] = 0;
    q[fn++] = p;
    while (in<fn) {
        p = q[in++];
        if (p==make_pair(x1,y1)) break;
        for (int i=0; i<8; i++) {
            pair<int,int> u = p;
            u.first += dx[i];
            u.second += dy[i];
            if (all.find(u)!=all.end() && dist[u]==-1) {
                dist[u] = dist[p] + 1;
                q[fn++] = u;
            }
        }
    }

    cout<<dist[make_pair(x1,y1)];

    return 0;

}
