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

struct point{
    int x, y, z;
    point(int x, int y, int z): x(x), y(y), z(z) {};
    point(){};
};

int sqr(int x) {
    return x*x;
}

point p[5010];
int ans[11];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n = 0;

    int x,y,z;
    while (scanf("%d%d%d",&x,&y,&z) && (x!=0 || y!=0 || z!=0)) {
        p[n++] = point(x,y,z);
    }

    for (int i=0; i<n; i++) {
        int d = 100;
        for (int j=0; j<n; j++) if(i!=j) {
            d = min(d, sqr(p[i].x-p[j].x) + sqr(p[i].y-p[j].y) + sqr(p[i].z-p[j].z));
        }
        for (int i=0; i<10; i++) {
            if (d<sqr(i+1)) {
                ans[i]++;
                break;
            }
        }
    }

    for (int i = 0; i < 10; i++) printf("%4d", ans[i]);
    cout<<endl;

    return 0;

}
