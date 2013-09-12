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
int t[100010];
vector<int> e1[100010];
vector<int> e2[100010];
int q1[100010];
int q2[100010];
int c1,c2;
queue<int> q;
bool vis[100010];
bool r1[100010];
bool r2[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) scanf("%d",&t[i]);

    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e1[a].push_back(b);
        e2[b].push_back(a);
    }

    c1 = 0, c2=0;
    for ( int i=0; i<n; i++) if (t[i]==1) q1[c1++] = i;
    for ( int i=0; i<n; i++) if (t[i]==2) q2[c2++] = i;

    for (int i=0; i<n; i++) vis[i] = 0;

    for (int i=0; i<n; i++) r1[i] = 0;
    for (int i=0; i<n; i++) r2[i] = 0;

    for (int i=0; i<c1; i++) {
        q.push(q1[i]);

        r1[q1[i]] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            rep(it,e1[u]) {
                int v = *it;

                if (vis[v]) continue;
                vis[v] = 1;
                r1[v] = 1;

                q.push(v);
            }
        }
    }


    for (int i=0; i<n; i++) vis[i] = 0;

    for (int i=0; i<c2; i++) {
        q.push(q2[i]);

        r2[q2[i]] = 1;

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            rep(it,e2[u]) {
                int v = *it;

                if (vis[v]) continue;

                vis[v] = 1;
                r2[v] = 1;

                if (t[v]==1) continue;

                q.push(v);
            }
        }
    }

    for (int i=0; i<n; i++) printf("%d\n",r1[i]&r2[i]);

    return 0;

}
