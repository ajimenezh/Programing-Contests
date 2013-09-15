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

long long h[100010];
long long p[100010];
int n,m;

bool can(long long cur, long long l, long long r, long long t) {
    l = max(cur-l,0LL);
    r = max(r-cur,0LL);

    return t>= l+r+min(l,r);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%I64d",h+i);
    for (int i=0; i<m; i++) scanf("%I64d",p+i);

    long long lo = 0;
    long long hi = 200000000000LL;

    while (lo<hi) {
        long long mi = (lo+hi)/2;

        int t;
        int i,j;
        for (i=0, j=0; i<n && j<m; j=t, i++) {
            for (t=j; t<m; t++) {
                if (!can(h[i],p[j],p[t],mi)) break;
            }
        }
        if (j<m) lo = mi+1;
        else hi = mi;
    }
    printf("%I64d\n",lo);

    return 0;

}
