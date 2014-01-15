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

const double eps = 1.0e-6;
double p;
double e;

void dfs(int a, int b, double q,int r) {
    if (q*r<eps && q<eps) return;
    if (a<b) {
        e += q*r*0.5;
        dfs(2*a, b-a, q*0.5,r+1);
    }
    else if (a>b) {
        p += q*0.5;
        e += q*r*0.5;
        dfs(a-b,2*b,q*0.5,r+1);
    }
    else {
        e += q*r;
        p += q*0.5;
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        int a,b;
        cin>>a>>b;
        p = 0;
        e = 0;
        dfs(a,b,1,1);
        printf("Case %d: %.6lf %.6lf\n",t,e,p);
    }

    return 0;

}
