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
int dist[210][210];
int longest[210];
priority_queue<pair<int,int> > q;
pair<int,int> edges[40000];
int w[40000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) dist[i][j] = 100000000;
    for (int i=0; i<n; i++) dist[i][i] = 0;
    for (int i=0; i<m; i++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        dist[a][b] = c;
        dist[b][a] = c;
        edges[i] = make_pair(a,b);
        w[i] = c;
    }
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) {
        dist[j][k] = min(dist[j][k], dist[j][i]+dist[i][k]);
    }

    int tmp = 0;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) tmp = max(tmp, dist[i][j]);


    if (tmp%2==0) printf("%d.0\n",tmp/2);
    else printf("%d.5\n",tmp/2);


    return 0;

}
