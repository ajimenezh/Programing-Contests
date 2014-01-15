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

int euclide(int a, int b, int &x, int &y) {
    if (a<0) {
        int d = euclide(-a,b,x,y);
        x = -x;
        return d;
    }
    if (b<0) {
        int d = euclide(a,-b,x,y);
        y = -y;
        return d;
    }
    if (b==0) {
        x = 1;
        y = 0;
        return a;
    }
    else {
        int d = euclide(b,a%b,x,y);
        int t = x;
        x = y;
        y = t - (a/b)*y;
        return d;
    }
}

int solve(int a, int b, int c, int x1, int x2, int  y1, int y2) {
    int n,m;

    int g = euclide(a,b,n,m);

    c = -c;

    int t = 0;

    if (abs(c)<g) return 0;
    else {
        n *= c/g;
        m *= c/g;

        int k = 0;

        while (n<x1 || m<y1) {
            n += b;
            m += a;
        }
        while (n<=x2 && m<=y2) {
            t++;
            n += b;
            m += a;
        }
    }

    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b,c,x1,x2,y1,y2;
    cin>>a>>b>>c>>x1>>x2>>y1>>y2;

    int res = solve(a,b,c,x1,x2,y1,y2);
    if (a==b) res += solve(b,a,c,x1,x2,y1,y2);

    cout<<res<<endl;


    return 0;

}
