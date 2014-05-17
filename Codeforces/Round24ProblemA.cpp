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

int n;
vector<pair<int,int> > e[101];
int mas,menos;
bool vis[101];
int fin;

void dfs(int p)
{
    vis[p] = 1;
    for (int i=0; i<e[p].size(); i++) if (!vis[e[p][i].first])
    {
        if (e[p][i].second<0) menos += e[p][i].second;
        else mas += e[p][i].second;

        if (!vis[e[p][i].first]) dfs(e[p][i].first);


    } else fin = e[p][i].first;
    return;
}

int main() {

    cin>>n;
    fo(i,n)
    {
        int a,b,c;
        cin>>a>>b>>c;
        a--; b--;
        e[a].pb(mp(b,c));
        e[b].pb(mp(a,-c));
    }
    mas = 0;
    menos = 0;

    fo(i,n) vis[i] = 0;
    dfs(0);

    for (int i=0; i<e[fin].size(); i++) if (e[fin][i].first==0)
    {
        if (e[fin][i].second<0) menos += e[fin][i].second;
        else mas += e[fin][i].second;
        break;
    }

    cout<<min(-menos,mas);

	return 0;

}
