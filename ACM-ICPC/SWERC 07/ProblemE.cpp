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

int n;
int s,t;
int m;
pair<int,pair<int,int> > edges[300*300];
int dist[301];

int bellmanFord(int f) {
    for (int i=0; i<n; i++) dist[i] = 100000000;
    dist[s] = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            int u = edges[j].second.first;
            int v = edges[j].second.second;
            int c = f*edges[j].first;
            if (dist[v]>dist[u]+c) {
                dist[v] = dist[u]+c;
            }
        }
    }

    if (dist[t]==100000000) return -1;
    for (int j=0; j<m; j++) {
        int u = edges[j].second.first;
        int v = edges[j].second.second;
        int c = f*edges[j].first;
        if (dist[v]>dist[u]+c) {
            return -1;
        }
    }
    return dist[t];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int cas;
    cin>>cas;
    while (cas--) {
        scanf("%d",&n);
        scanf("%d%d",&s,&t);
        scanf("%d",&m);
        for (int i=0; i<m; i++) {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            edges[i] = make_pair(w,make_pair(a,b));
        }

        int ans = bellmanFord(1);
        //int tmp = bellmanFord(-1);

        if (ans==-1) printf("infinity\n");
        else printf("%d\n",ans);

        if (cas!=0) printf("\n");
    }

    return 0;

}
