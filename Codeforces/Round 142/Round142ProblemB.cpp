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

#define INF 100000000000LL

int n,m;
vector<int> e[100010];
vector<int> c[100010];
vector<int> t[100010];
vector<int> next[100010];

long long tim[100010];

priority_queue<pair<long long,int> > q;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++) {
        int a,b, w;
        scanf("%d%d%d",&a,&b,&w);
        a--; b--;
        e[a].push_back(b);
        c[a].push_back(w);
        e[b].push_back(a);
        c[b].push_back(w);
    }
    for (int i=0; i<n; i++) {
        int z;
        scanf("%d",&z);
        for (int j=0; j<z; j++) {
            int a;
            scanf("%d",&a);
            t[i].push_back(a);
        }
        next[i] = vector<int> (z,0);
    }
    for (int x=0; x<n; x++) {
        for (int i=0; i<t[x].size(); i++) {
            int j;
            next[x][i] = t[x][i] + 1;
            for (j=i+1; j<t[x].size()&&t[x][j]==t[x][j-1]+1; j++);
            for (int k=i; k<j; k++) next[x][k] = t[x][j-1] + 1;
            i = j-1;
        }
    }

    for (int i=0; i<n; i++) tim[i] = INF;

    if (t[0].size()>0 && t[0][0]==0) tim[0] = next[0][0];
    else tim[0] = 0;
    q.push(make_pair(-tim[0],0));

    int ans = -1;
    while (!q.empty()) {
        int p = (q.top()).second;
        if (p==n-1) {
            ans = -q.top().first;
            break;
        }
        q.pop();
        for (int i=0; i<e[p].size(); i++) {
            if (e[p][i]==n-1) {
                q.push(make_pair(-tim[p]-c[p][i], e[p][i]));
            }

            int tmp = tim[p] + c[p][i];
            if (tim[e[p][i]]>tmp) {
                vector<int>::iterator it = lower_bound(t[e[p][i]].begin(),t[e[p][i]].end(),tmp);
                if (it!=t[e[p][i]].end() && *it==tmp) {
                    tmp = next[e[p][i]][it-t[e[p][i]].begin()];
                }

                if (tim[e[p][i]]>tmp) {
                    tim[e[p][i]]=tmp;
                    q.push(make_pair(-tmp, e[p][i]));
                }
            }
        }
    }

    cout<<ans;

    return 0;

}
