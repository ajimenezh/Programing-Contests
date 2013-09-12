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
map<string,int> id;
string to[310];
int q[320];
int in,fn;
int dist[310];
vector<int> e[310];
int cnt;

void _insert(string s) {
    if (id.find(s)!=id.end()) return;
    id[s] = cnt;
    to[cnt++] = s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        string s1,s2,s3;
        cin>>s1>>s2>>s3;
        _insert(s1); _insert(s2); _insert(s3);
        int a = id[s1], b = id[s2], c = id[s3];
        e[a].push_back(b); e[a].push_back(c);
        e[b].push_back(a); e[b].push_back(c);
        e[c].push_back(b); e[c].push_back(a);
    }
    for (int i=0; i<cnt; i++) dist[i] = -1;

    in = fn = 0;

    if (id.find("Isenbaev")==id.end()) {
        rep(it,id) {
            int i = (*it).second;
            cout<<to[i]<<" ";
            if (dist[i]==-1) cout<<"undefined"<<endl;
            else cout<<dist[i]<<endl;
        }
        return 0;
    }

    int p = id["Isenbaev"];
    q[fn++] = p;
    dist[p] = 0;
    while (in<fn) {
        p = q[in++];
        for (int i=0; i<e[p].size(); i++) {
            if (dist[e[p][i]]!=-1) continue;
            dist[e[p][i]] = dist[p] + 1;
            q[fn++] = e[p][i];
        }
    }

    rep(it,id) {
        int i = (*it).second;
        cout<<to[i]<<" ";
        if (dist[i]==-1) cout<<"undefined"<<endl;
        else cout<<dist[i]<<endl;
    }

    return 0;

}
