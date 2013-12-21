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

int n,x,y,c;
long long area[1000000];

long long calc(int m) {
    if (m==1) return 1;

    long long sol = 0;

    if (m>x) {
        int t = m-x;
        if (t>=n-y) area += (x-1)*
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>x>>y>c;
    area[1] = 1;
    for (int i=2; i<1000000; i++) area[i] = area[i-1] + 2*i-1;

    int lo = 1;
    int hi = n;
    while (lo<hi) {
        int mi = (lo+hi)>>1;
        long long tmp = calc(mi);
        if (tmp<c) lo = mi+1;
        else hi = mi;
    }

    cout<<lo<<endl;

    return 0;

}
