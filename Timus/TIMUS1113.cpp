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

int n,m;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    double lo = 0;
    double hi = 1000000;

    double d;

    for (int i=0; i<100; i++) {
        double mi = (lo+hi)/2;

        d = 0/(2.0*m+1.0);
        for (int j=1; j<=m; j++) {
            d += 1.0/(2.0*j-1.0);
        }

        if (d>n) {
            hi = mi;
        }
        else {
            lo = mi;
        }
    }

    cout<<int(floor(lo))<<endl;

    return 0;

}
