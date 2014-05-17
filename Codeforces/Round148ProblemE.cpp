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

vector<int> g[101];
int n,m;
int s,t;
int k;
pii buses[101];
int c[101];
int q[100001];
int dist[101];
int pre[101];
vector<int> ng[101];

int main() {

    scanf("%d%d%d%d",&n,&m,&s,&t);
    fo(i,m)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--;
        b--;
        g[a].pb(b);
    }

    scanf("%d",&k);
    fo(i,k)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        buses[i] = mp(a,b);
    }

    for (int i=0; i<k; i++)
    {
        fo(j,n) c[j] = 0;
        fo(j,n) dist[j] = 100000;
        fo(j,n) pre[j] = -1;
        int in = 0;
        int fn = 0;
        int src = buses[i].first;
        int sink = buses[i].second;

        q[fn++] = src;
        dist[src] = 0;
        c[src]++;
        while (in!=fn)
        {
            int p = q[in];
            cout<<p<<endl;
            in++;
            for (int j=0; j<g[p].size(); j++)
            {
                if (dist[g[p][j]]>dist[p]+1)
                {
                    dist[g[p][j]]=dist[p]+1;
                    q[fn++]=g[p][j];
                    c[g[p][j]]++;
                    pre[g[p][j]] = p;
                }
                else if (dist[g[p][j]]==dist[p]+1)
                {
                    c[g[p][j]]++;
                }
            }
        }

        int tot = c[sink];
        int q = sink;
        cout<<src<<" "<<sink<<" ";
        for (int p = sink; p!=-1; p = pre[p])
        {
            cout<<p<<" "<<c[p]<<" ";
            if (pre[p]!=-1 && c[pre[p]]!=tot)
            {
                ng[p].pb(q);
                q = p;
            }
            else if (pre[p]==-1)
            {
                ng[p].pb(q);
            }
        }
    }
    cout<<endl;

    for (int i=0; i<n; i++)
    {
        cout<<i+1<<" ";
        for (int j=0; j<ng[i].size(); j++) cout<<ng[i][j]+1<<" ";
        cout<<endl;
    }


	return 0;

}
