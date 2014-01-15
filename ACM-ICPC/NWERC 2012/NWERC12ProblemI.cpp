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

vector<int> e[2010];
int n,m;

bool vis1[2010];
bool vis2[2010];

void dfs1(int p) {
    vis1[p] = 1;
    rep(it,e[p]) if (!vis1[*it]) {
        dfs1(*it);
    }
}
void dfs2(int p) {
    vis2[p] = 1;
    rep(it,e[p]) if (!vis2[*it]) {
        dfs2(*it);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for (int i=0; i<m; i++) {
        int a,b;
        cin>>a>>b;
        if (a<0) {
            if (b<0) {
                a = -a;
                b = -b;
                e[2*a].push_back(2*b+1);
                e[2*b].push_back(2*a+1);
            }
            else {
                a = -a;
                e[2*a].push_back(2*b);
                e[2*b+1].push_back(2*a+1);
            }
        }
        else {
            if (b<0) {
                b = -b;
                e[2*a+1].push_back(2*b+1);
                e[2*b].push_back(2*a);
            }
            else {
                e[2*a+1].push_back(2*b);
                e[2*b+1].push_back(2*a);
            }
        }
    }

    bool good = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<2*n; j++) vis1[j] = 0;
        for (int j=0; j<2*n; j++) vis2[j] = 0;

        dfs1(2*i);
        dfs2(2*i+1);

        if (vis1[2*i+1] && vis2[2*i]) {
            good = 0;
            break;
        }
    }

    if (good) cout<<"yes"<<endl;
    else cout<<"no";

    return 0;

}
