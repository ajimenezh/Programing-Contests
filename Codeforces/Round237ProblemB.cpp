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

double a,d;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%lf %lf", &a, &d);
    cin>>n;

    int x = 0, y = 0;

    int t = (int)round(a*10000.0);
    int p = (int)round(d*10000.0);

    p = p%((int)(4.0*t));

    int dir = 0;

    for (int i=0; i<n; i++) {
        int tmp = p;
        while (tmp>0) {
            if (dir==0) {
                int k = min(t-x, tmp);
                x += k;
                tmp -= k;
                if (x==t) dir = 1;
            }
            else if (dir==1) {
                int k = min(t-y, tmp);
                y += k;
                tmp -= k;
                if (y==t) dir = 2;
            }
            else if (dir==2) {
                int k = min(x-0, tmp);
                x -= k;
                tmp -= k;
                if (x==0) dir = 3;
            }
            else if (dir==3) {
                int k = min(y-0, tmp);
                y -= k;
                tmp -= k;
                if (y==0) dir = 0;
            }
        }
        printf("%.8f %.8f\n",(double)x/10000.0,(double)y/10000.0);
    }

    return 0;

}
