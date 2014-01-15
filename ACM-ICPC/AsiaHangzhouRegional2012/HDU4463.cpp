#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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
int par[51];
int rk[51];
int x[51], y[51];
vector<pair<double,pair<int,int> > > e;

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

bool connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (rk[a]>rk[b]) {
        rk[b]++;
        par[a] = b;
    }
    else {
        rk[a]++;
        par[b] = a;
    }
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        int a,b;
        cin>>a>>b;
        a--; b--;
        for (int i=0; i<n; i++) par[i] = i;
        for (int i=0; i<n; i++) rk[i] = 0;
        for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);

        double dist = 0.0;
        connect(a,b);
        dist += sqrt((x[a]-x[b])*(x[a]-x[b]) + (y[a]-y[b])*(y[a]-y[b]));

        e.clear();
        for (int i=0; i<n; i++) {
            for (int j=i+1; j<n; j++) {
                double d = sqrt((x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]));
                e.push_back(make_pair(d,make_pair(i,j)));
            }
        }
        sort(e.begin(),e.end());
        for (int i=0; i<e.size(); i++) {
            if (connect(e[i].second.first,e[i].second.second))
                dist += e[i].first;
        }
        printf("%.2lf\n",1.0*((int)round(dist*100))/100);
    }

    return 0;

}
