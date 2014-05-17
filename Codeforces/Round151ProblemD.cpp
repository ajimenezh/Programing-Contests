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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m;
int c[100010];
vector<int> e[100010];
int vis[100010];
int v[1000010];
int par[100010];
map<int,vector<int> > ma;

void dfs(int p)
{
    vis[p] = 1;
    if (ma.find(c[p])==ma.end()) {
        ma[c[p]] = vector<int> (0,0);
        ma[c[p]].push_back(p);
    }
    else ma[c[p]].push_back(p);
    for (int i=0; i<e[p].size(); i++)
    {
        if (!vis[e[p][i]]) dfs(e[p][i]);
    }
    return;
}

int main() {

    scanf("%d%d",&n,&m);
    for (int i=0; i<n; i++) scanf("%d",&c[i]);
    fo(i,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    fo(i,100010) vis[i] = 0;
    fo (i,n) if (!vis[i]) dfs(i);
    fo(i,100010) vis[i] = -1;
    fo(i,100010) v[i] = 0;
    fo(i,100010) par[i] = -1;
    fo(i,n) if (par[c[i]]==-1) par[c[i]] = i;
    int res = -1;
    int ans = -1;
    for (map<int,vector<int> >::iterator it = ma.begin(); it!=ma.end(); it++)
    {
        for (int k=0; k<(*it).second.size(); k++) {
            int i = ((*it).second)[k];
            int q = 0;
            int p = par[c[i]];

            for (int j=0; j<e[i].size(); j++) {
                if (vis[c[e[i][j]]]!=p && c[e[i][j]]!=c[i])
                {
                    q++;
                    vis[c[e[i][j]]] = p;
                }
            }
            v[c[i]] += q;

            if (v[c[i]]==res && c[i]<c[ans]) ans = i;
            if (v[c[i]]>res)
            {
                res = v[c[i]];
                ans = i;
            }
        }
    }

    cout<<c[ans]<<endl;


	return 0;

}
