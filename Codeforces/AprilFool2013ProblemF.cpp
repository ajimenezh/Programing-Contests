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
vector<int> e[21];
map<pair<int,int>,int > vis;

pair<int,int> edge(int a, int b) {
    if (a>b) return make_pair(a,b);
    else return make_pair(b,a);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    if (m==0 && n>1) {
        cout<<"No";
        return 0;
    }
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
        vis[edge(a,b)]++;
    }

    int p = 0;
    while (true) {
        bool done = 0;
        //cout<<p+1<<endl;
        rep(it,e[p]) {
            if (vis[edge(*it,p)]>0) {
                vis[edge(*it,p)]--;
                p = *it;
                done = 1;
                break;
            }
        }
        if (!done) break;
    }

    rep(it,vis) {
        if ((*it).second) {
            cout<<"No";
            return 0;
        }
    }

    cout<<"Yes";

    return 0;

}
