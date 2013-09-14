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
int dist[2000];
vector<pair<int,int> > e[2000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int tot = 0;
    for (int i=0; i<n; i++) {
        int t;
        cin>>t;
        for (int j=0; j<t; j++) {
            int dest = (i+1)*50 + j + 1;
            int to, x;
            while (cin>>to && to!=0) {
                cin>>x;
                to = (i)*50 + to;
                e[to].push_back(make_pair(dest,x));
            }
        }
        tot = t;
        char c;
        if (i!=n-1) cin>>c;
    }

    priority_queue<pair<int,int> > q;
    q.push(make_pair(0,1));
    for (int i=0; i<2000; i++) dist[i] = 100000000;
    dist[1] = 0;
    while (!q.empty()) {
        int p = q.top().second;
        q.pop();
        for (int i=0; i<e[p].size(); i++) {
            if (dist[e[p][i].first]>dist[p]+e[p][i].second) {
                dist[e[p][i].first]=dist[p]+e[p][i].second;
                q.push(make_pair(-dist[e[p][i].first], e[p][i].first));
            }
        }
    }
    int ans = 100000000;
    for (int i=0; i<tot; i++) ans = min(ans, dist[n*50+i+1]);
    cout<<ans;

    return 0;

}
