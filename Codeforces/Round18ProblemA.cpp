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

#define y1 Y1
#define y2 Y2

int x1,x2,x3,y1,y2,y3;

bool check(int a, int b, int c, int d, int e, int f) {
    int d1 = (a-c)*(a-c) + (b-d)*(b-d);
    int d2 = (a-e)*(a-e) + (b-f)*(b-f);
    int d3 = (e-c)*(e-c) + (f-d)*(f-d);

    if (!d1 || !d2 || !d3) return false;

    if (a==c && c==e) return false;
    if (b==d && d==f) return false;

    if (d1>=d2 && d1>=d3) return d1 - d2 - d3 == 0;
    if (d2>=d1 && d2>=d3) return d2 - d1 - d3 == 0;
    if (d3>=d2 && d3>=d1) return d3 - d2 - d1 == 0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    if (check(x1,y1,x2,y2,x3,y3)) cout<<"RIGHT";
    else {
        bool good = 0;
        x1 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x1 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x1++;
        x2 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x2 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x2++;
        x3 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x3 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        x3++;
        y1 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y1 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y1++;
        y2 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y2 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y2++;
        y3 += 1;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y3 -= 2;
        if (check(x1,y1,x2,y2,x3,y3)) good = 1;
        y3++;

        if (good) cout<<"ALMOST";
        else cout<<"NEITHER";
    }

    return 0;

}
