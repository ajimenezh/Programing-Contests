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
pair<double,int> w[10010];
int x[10010];
int y[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        x[i] = a;
        y[i] = b;
    }
    int p;
    int m = 1000000005;
    for (int i = 0; i<n; i++) {
        if (y[i]<m) {
            m = y[i];
            p = i;
        }
    }
    m = 1000000005;
    int s;
    for (int i = 0; i<n; i++) if (i!=p) {
        if (y[i]<m) {
            m = y[i];
            s = i;
        }
    }

    if (x[s]<x[p]) swap(p,s);

    for (int i=0; i<n; i++) if (i!=p) {
        double alp = 0.0;
        double vx = (double)x[i]-(double)x[p];
        double vy = (double)y[i]-(double)y[p];
        double ux = (double)x[s]-(double)x[p];
        double uy = (double)y[s]-(double)y[p];
        alp = (ux*vx + uy*vy);
        alp = alp/sqrt(ux*ux+uy*uy)/sqrt(vx*vx+vy*vy);
        alp = acos(alp);
        alp = abs(alp);
        w[i] = make_pair(alp,i);
    }
    swap(w[p],w[n-1]);
    sort(w,w+n-1);
    cout<<p+1<<" "<<w[(n-1)/2].second+1<<endl;

    return 0;

}
