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
vector<int> e[49];
bool vis[49];
vector<int> sol1[49];
vector<int> sol2[49];
vector<int> sol3[49];
bool bad;
vector<int> now;

void dfs(int i,int pre) {
    now.push_back(i);
    vis[i] = 1;
    rep(it,e[i]) if (!vis[*it]) {
        if (*it!=pre) dfs(*it,i);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    int k1=0,k2=0,k3=0;
    for (int i=0; i<n; i++) if (!vis[i]) {
        dfs(i,-1);
        if (now.size()>3) {
            cout<<-1;
            return 0;
        }
        if (now.size()==3) {
            sol3[k3++] = now;
        }
        else if (now.size()==2) {
            sol2[k2++] = now;
        }
        else if (now.size()==1) {
            sol1[k1++] = now;
        }
        now.clear();
    }

    //cout<<k1<<" "<<k2<<" "<<k3<<endl;
    int c = 0;
    for (int i=0; i<k2; i++) {
        if (c<k1) {
            sol2[i].push_back(sol1[c++][0]);
        }
        else {
            cout<<-1;
            return 0;
        }
    }
    for (int i=0; i<k3; i++) {
        for (int j=0; j<3; j++) cout<<sol3[i][j]+1<<" ";
        cout<<endl;
    }
    for (int i=0; i<k2; i++) {
        for (int j=0; j<3; j++) cout<<sol2[i][j]+1<<" ";
        cout<<endl;
    }
    for (int i=c; i<k1; i+=3) {
        for (int j=0; j<3; j++) cout<<sol1[i+j][0]+1<<" ";
        cout<<endl;
    }

    return 0;

}
