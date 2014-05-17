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

struct event{
    int x, y, t;
    double p;
    event(int a=0, int b=0, int c=0,double q=0.0)
    {
        x = a;
        y = b;
        t = c;
        p = q;
    }
}target[1001];

struct Comparador {
  bool operator() (event i,event j) { return (i.t<j.t);}
} comp;

double dp[1001];
int n;

long long sqr(long long x)
{
    return x*x;
}


int dist(int a, int b)
{
    return sqr(target[a].x-target[b].x) + sqr(target[a].y-target[b].y);
}

int main() {

    cin>>n;
    fo(i,n)
    {
        int a,b,c;
        double q;
        cin>>a>>b>>c>>q;
        target[i] = event(a,b,c,q);
    }

    sort(target,target+n,comp);

    for (int i=0; i<n; i++)
    {
        dp[i] = target[i].p;
        for (int j=0; j<i; j++)
            if (dist(i,j)<=sqr(target[i].t-target[j].t))
                dp[i] = max(dp[i],dp[j]+target[i].p);
    }


    double ans = 0;
    fo(i,n) ans = max(ans,dp[i]);

    printf("%.8lf\n",ans);

	return 0;

}
