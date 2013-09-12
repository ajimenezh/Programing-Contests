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

int l,n,v1,v2;
int p[200010];
double d[400010];
double dist;
double prob[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>l>>v1>>v2;
    for (int i=0; i<n; i++) scanf("%d",&p[i]);
    for (int i=0; i<n; i++) p[i+n] = 2*l + p[i];

    dist = 1.0*l*v2/(1.0*v1+1.0*v2);

    int k = 0;
    d[k++] = 0;
    d[k++] = 2*l;

    for (int i=0; i<n; i++) {
        d[k++] = p[i];
        d[k++] = p[i] - dist;
        if (d[k-1]<0) d[k-1] += 2*l;
    }

    sort(d,d+k);

    for (int i=0; i<=n; i++) prob[i] = 0;

    for (int i=0; i<k-1; i++) {
        double m = (d[i] + d[i+1]) / 2.0;
        int r = lower_bound(p,p+2*n,m+dist) - lower_bound(p,p+2*n,m);
        prob[r] += d[i+1] - d[i];
    }

    for (int i=0; i<=n; i++) printf("%.15f\n",prob[i]/(2.0*l));

    return 0;

}
