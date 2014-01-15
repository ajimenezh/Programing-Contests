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

int n, m;
vector<int> e[1001];
int q[1010];
int in, fn;
int dist[1010][1010];
bool used[1010];
map<string,int> id;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        id.clear();
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            id[s] = i;
        }
        for (int i=0; i<n; i++) e[i].clear();
        cin>>m;
        for (int i=0; i<m; i++) {
            string a,b;
            cin>>a>>b;
            int x = id[a];
            int y = id[b];
            e[x].push_back(y);
            e[y].push_back(x);
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) dist[i][j] = -1;
            dist[i][i] = 0;
        }

        int d = -1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) used[j] = 0;
            used[i] = false;
            in = fn = 0;
            q[fn++] = i;
            while (in<fn) {
                int p = q[in++];
                for (int j=0; j<e[p].size(); j++) {
                    int a = e[p][j];
                    if (!used[a]) {
                        dist[i][a] = dist[i][p] + 1;
                        q[fn++] = a;
                        used[a] = true;
                    }
                }
            }
        }
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                if (dist[i][j]!=-1) d = max(d, dist[i][j]);
                else d = 100000000;
            }
        }
        if (d==100000000) printf("-1\n");
        else printf("%d\n",d);
    }

    return 0;

}
