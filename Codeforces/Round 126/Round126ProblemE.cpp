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

int c3,c4,c5;
int n;
int s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>s;
    for (int i=0; i<n; i++) {
        int t;
        scanf("%d",&t);
        if (t==3) c3++;
        else if (t==4) c4++;
        else c5++;
    }

    for (int k4=0; k4*c4<=s; k4++) {
        int m = s-c4*k4;

        int x,y;
        int _c3 = c3, _c5 = c5;

        int x,y;
        int g = euclide(_c3, _c5, x, y);

        if (m%g!=0) continue;

        m /= g;
        _c3 /= g;
        _c5 /= g;

        euclide(_c3, _c5, x, y);

        x *= m;
        y *= m;

        int x3 = x*c3, delx3 = c5/g, delx5 = -c3/g;



    }

    return 0;

}
