#line 2 "BigO.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

int n,m,k,w;
vector<pair<int,pair<int,int> > > v;
string vs[2010];
bool vis[2010];
vector<int> e[2010];
vector<int> c[2010];
int par[2010];
int sz[2010];

int find(int p) {
    if (par[p]==p) return p;
    par[p] = find(par[p]);
    return par[p];
}

void merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a==b) return;
    if (sz[a]>sz[b]) {
        par[b] = a;
    }
    else if (sz[b]>sz[a]) {
        par[a] = b;
    }
    else {
        par[b] = a;
        sz[a]++;
    }
}

void dfs(int p) {
    vis[p] = 1;
    for (int i=0; i<e[p].size(); i++) {
        if (!vis[e[p][i]]) {
            if (c[p][i]==n*m) cout<<e[p][i]+1<<" "<<0<<"\n";
            else cout<<e[p][i]+1<<" "<<p+1<<"\n";
            dfs(e[p][i]);
        }
    }
}

int main() {

	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k>>w;
    for (int i=0; i<k; i++) {
        string s = "", str;
        for (int j=0; j<n; j++) {
            cin>>str;
            s += str;
        }
        vs[i] = s;
        int tmp = n*m;
        for (int j=0; j<i; j++) {
            int tot = n*m;
            for (int p=0; p<n*m; p++) if (vs[i][p]==vs[j][p]) tot--;
            v.push_back(make_pair(min(tmp, w*tot), make_pair(i,j)));
        }
    }

    sort(v.begin(), v.end());

    int res = 0;
    for (int i=0; i<k; i++) par[i] = i;
    for (int i=0; i<v.size(); i++) {
        if (find(v[i].second.first)!=find(v[i].second.second)) {
            merge(v[i].second.first, v[i].second.second);
            e[v[i].second.first].push_back(v[i].second.second);
            e[v[i].second.second].push_back(v[i].second.first);
            c[v[i].second.first].push_back(v[i].first);
            c[v[i].second.second].push_back(v[i].first);

            res += v[i].first;
        }
    }

    res += n*m;

    cout<<res<<"\n";
    cout<<"1 0\n";
    dfs(0);

	return 0;
}
