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

int n;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    long long lo = 1;
    long long hi = 10000000000000LL;
    for (int i=0; i<n; i++) lo = max(lo,(long long)a[i]);

    while (lo<hi) {
        long long mi = (lo+hi)>>1LL;
        long long sum = 0;
        for (int i=0; i<n; i++) {
            sum += mi - a[i];
        }

        if (sum<mi) lo = mi+1;
        else hi = mi;
    }

    cout<<lo<<endl;

    return 0;

}
