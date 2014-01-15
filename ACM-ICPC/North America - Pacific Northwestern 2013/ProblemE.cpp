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

const long long INF = 10000000000000LL;

priority_queue<pair<long long, long long> > q;
long long dist[1005][1005];
long long pre[1005][1005];
int k,n,m;
long long c[26];
string s[1005];

int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int main(){

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        scanf("%d%d%d",&k,&m,&n);
        for (int i=0; i<k; i++) {
            char cc;
            int cost;
            cin>>cc>>cost;
            c[cc-'A'] = cost;
        }
        c['E'-'A'] = INF;
        for (int i=0; i<n; i++) cin>>s[i];

        int x,y;
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) if (s[i][j]=='E') {
            x = i;
            y = j;
            break;
        }
        for (int i=0; i<n; i++) for (int j=0; j<m; j++) dist[i][j] = INF;
        dist[x][y] = 0;
        while (!q.empty()) q.pop();
        q.push(make_pair(0,x*m+y));
        long long ans = 0;
        while (!q.empty()) {
            long long p = q.top().second;
            x = p/m;
            y = p%m;
            if (x==0 || x==n-1 || y==0 || y==m-1) {
                ans = -q.top().first;
                break;
            }
            q.pop();
            for (int k=0; k<4; k++) {
                int u = x+dx[k];
                int v = y+dy[k];
                if (dist[u][v] > c[s[u][v]-'A'] + dist[x][y]) {
                    dist[u][v] = c[s[u][v]-'A'] + dist[x][y];
                    q.push(make_pair(-dist[u][v], (long long)u*m+v));
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}
