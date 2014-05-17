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

#define MAXN 100010


int a[MAXN];
vector<int> sol;
vector<int> e[MAXN];
int c[MAXN];
bool push[MAXN];

void dfs(int p)
{
    c[p]++;
    push[p] = 1;
    for (int i=0; i<e[p].size(); i++)
    {
        c[e[p][i]]++;
    }
    for (int i=0; i<e[p].size(); i++)
    {
        if (a[e[p][i]]==c[e[p][i]] && !push[e[p][i]]) dfs(e[p][i]);
    }
    return;
}

int main() {

    int n,m;
    cin>>n>>m;

    fo(i,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].pb(b);
        e[b].pb(a);
    }
    fo(i,n) scanf("%d",&a[i]);

    fo(i,n) c[i] = 0;
    fo(i,n) push[i] = 0;
    for (int i=0; i<n; i++)
    {
        if (a[i]==c[i] && !push[i]) dfs(i);
    }

    int k = 0;
    for (int i=0; i<n; i++)
    {
        k += push[i];
        if (c[i]==a[i])
        {
            cout<<-1;
            return 0;
        }
    }

    cout<<k<<endl;
    fo(i,n) if (push[i]) cout<<i+1<<" ";

	return 0;

}
