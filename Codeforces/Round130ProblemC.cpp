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

#define MAXN 10000000

int n,m;
int ady[101][101];
int q[MAXN];
int dist[101];
int si;
int distl[101];
int prel[101],prer[101];
double cntl[101],cntr[101];

int count_right(int p)
{
    if (p==n-1) return 1;
    if (cntr[p]>-0.5) return cntr[p];

    int tmp = 0;

    for (int i=0; i<n; i++)
    {
        if (dist[i]+distl[i]==dist[n-1] && dist[i]==1+dist[p] && ady[i][p]==1)
            tmp += count_right(i);
    }

    cntr[p] = tmp;
    return tmp;
}

int count_left(int p)
{
    if (p==0) return 1;
    if (cntl[p]>-0.5) return cntl[p];

    int tmp = 0;

    for (int i=0; i<n; i++)
    {
        if (dist[i]+distl[i]==dist[n-1] && dist[i]==-1+dist[p] && ady[i][p]==1)
            tmp += count_left(i);
    }

    cntl[p] = tmp;
    return tmp;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n>>m;
    for(int i=0;i<n; i++) for (int j=0; j<m; j++) ady[i][j] = 0;
    for (int i=0; i<m; i++)
    {

        int a,b;
        cin>>a>>b;
        a--; b--;
        ady[a][b] = 1;
        ady[b][a] = 1;
    }

    si = 0;
    int in = 0;
    int fn = 0;
    for (int i=0; i<n; i++) dist[i] = 10000000;
    dist[0] = 0;
    q[fn++] = 0;

    while (in!=fn)
    {
        if (dist[q[in]]>dist[n-1]) break;
        int p = q[in++];
        for (int i=0; i<n; i++) if (p!=i)
        {
            if (ady[p][i]==0) continue;
            if (dist[i]<=dist[p]+1) continue;
            if (dist[p]+1>dist[n-1]) continue;
            dist[i] = dist[p]+1;
            q[fn++] = i;
            prer[i] = p;
        }
        if (in==9000000) {cout<<in; return 0;}
    }

    in = 0;
    fn = 0;
    for (int i=0; i<n; i++) distl[i] = 10000000;
    distl[n-1] = 0;
    q[fn++] = n-1;

    while (in!=fn)
    {
        int p = q[in++];
        if (distl[p]>distl[0]) break;
        for (int i=0; i<n; i++) if (p!=i)
        {
            if (ady[p][i]==0) continue;
            if (distl[i]<=distl[p]+1) continue;
            if (distl[p]+1>distl[0]) continue;
            distl[i] = distl[p]+1;
            q[fn++] = i;
            prel[i] = p;
        }
        if (in==9000000) {cout<<in; return 0;}
    }

    for (int i=0; i<n; i++) cntl[i] = -1;
    for (int j=0; j<n; j++) cntr[j] = -1;

    for (int i=0; i<n; i++) cntr[i] = count_right(i);
    for (int i=0; i<n; i++) cntl[i] = count_left(i);


    double res = 0;
    for(int i=0; i<n; i++)
    {
        if (distl[i]+dist[i] == dist[n-1]) {
            int f = 2.;
            if (i==0 || i==n-1) f = 1.;
            res = max(res,f*cntr[i]*cntl[i]);
            //cout<<i<<" "<<cntr[i]<<" "<<cntl[i]<<endl;
        }
    }

    //cout<<res<<" "<<si<<endl;
    printf("%.8f",1.0*res/(1.0*cntl[n-1]));

	return 0;

}
