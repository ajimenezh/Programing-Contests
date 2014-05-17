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

vector<int> e[MAXN];
long long k;
int n,m;
vector<int> comp;
bool vis[MAXN];

int dfs(int p)
{
    vis[p] = 1;
    int s = 1;
    forit(it,e[p]) if (!vis[*it])
    {
        s += dfs(*it);
    }
    return s;
}

long long sum[MAXN];

int main() {

    cin>>n>>m>>k;
    fo(i,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].pb(b);
        e[b].pb(a);
    }

    for (int i=0; i<n; i++) if (!vis[i])
    {
        comp.pb(dfs(i));
    }

    long long res = 0;

    sum[0] = comp[0];
    for (int i=1; i<comp.size(); i++) sum[i] = (sum[i-1] + comp[i])%k;

    for (int i=0; i<comp.size()-1; i++)
    {
        long long s = sum[i+1]%k;
        cout<<i<<" "<<s<<endl;
        long long tmp = 1;
        for (int j=0; j<i+1; j++) tmp *= comp[i+1]*comp[j]%k;
        cout<<i<<" "<<tmp<<endl;
        for (int j=i+2; j<comp.size(); j++)
        {
            tmp *= s*comp[j]%k;
            s += comp[j]%k;
        }
        cout<<i<<" "<<tmp<<endl;
        res += tmp%k;
    }

    cout<<res<<endl;

	return 0;

}
