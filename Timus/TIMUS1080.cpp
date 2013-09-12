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

int n;
vector<int> e[100];
int c[100];
bool vis[100];

bool dfs(int p,int t) {
    vis[p] = 1;
    c[p] = t;
    bool flag = 1;
    for (int i=0; i<e[p].size(); i++) {
        if (!vis[e[p][i]]) flag = flag && dfs(e[p][i],1-t);
        else if (c[e[p][i]]==t) return false;
    }
    return flag;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        while (cin>>a && a!=0) {
            e[i].push_back(a-1);
            e[a-1].push_back(i);
        }
    }

    if (dfs(0,0)) {
        for (int i=0; i<n; i++) cout<<c[i];
    }
    else cout<<-1<<endl;

    return 0;

}
