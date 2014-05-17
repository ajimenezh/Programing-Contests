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

int n,m,x,y,z,p;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>x>>y>>z>>p;

    x %= 4;
    y %= 2;
    z %= 4;

    for (int i=0; i<p; i++) {
        int u,v;
        scanf("%d%d",&u,&v);
        if (x==1) {
            int tmp = u;
            u = v;
            v = n-tmp+1;
        }
        if (x==2) {
            int tmp = u;
            u = v;
            v = n-tmp+1;
            tmp = u;
            u = v;
            v = m-tmp+1;
        }
        if (x==3) {
            int tmp = u;
            u = v;
            v = n-tmp+1;
            tmp = u;
            u = v;
            v = m-tmp+1;
            tmp = u;
            u = v;
            v = n-tmp+1;
        }
        if (y==1) {
            if (x==1 || x==3) {
                v = n-v+1;
            }
            else {
                v = m-v+1;
            }
        }
        if (z==1) {
            if (x==1 || x==3) {
                int tmp = u;
                u = n - v + 1;
                v = tmp;
            }
            else {
                int tmp = u;
                u = m - v + 1;
                v = tmp;
            }
        }
        if (z==2) {
            if (x==1 || x==3) {
                int tmp = u;
                u = n - v + 1;
                v = tmp;
                tmp = u;
                u = m - v + 1;
                v = tmp;
            }
            else {
                int tmp = u;
                u = m - v + 1;
                v = tmp;
                tmp = u;
                u = n - v + 1;
                v = tmp;
            }
        }
        if (z==3) {
            if (x==1 || x==3) {
                int tmp = u;
                u = n - v + 1;
                v = tmp;
                tmp = u;
                u = m - v + 1;
                v = tmp;
                tmp = u;
                u = n - v + 1;
                v = tmp;
            }
            else {
                int tmp = u;
                u = m - v + 1;
                v = tmp;
                tmp = u;
                u = n - v + 1;
                v = tmp;
                tmp = u;
                u = m - v + 1;
                v = tmp;
            }
        }

        printf("%d %d\n", u, v);
    }

    return 0;

}
