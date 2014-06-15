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

int n,m;
int a[100010];
int b[100010];

long long f(long long t) {
    long long tot = 0;
    for (int i=0; i<n; i++) {
        if (a[i]<t) tot += t-a[i];
    }
    for (int i=0; i<m; i++) {
        if (b[i]>t) tot += b[i]-t;
    }
    return tot;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d", &a[i]);
    for (int i=0; i<m; i++) scanf("%d", &b[i]);

    sort(a,a+n);
    sort(b,b+m);
    reverse(b,b+m);

    if (a[0]>=b[0]) cout<<0<<endl;
    else {
        int lo = 1;
        int hi = 1000000000;
        while (lo<hi-3) {
            long long lt = (2LL*lo+hi)/3;
            long long ht = (lo+2LL*hi)/3;

            long long fl = f(lt);
            long long fh = f(ht);

            if (fl<fh) {
                hi = ht;
            }
            else {
                lo = lt;
            }
        }

        long long res = f(1);
        for (int i=max(1,lo-5); i<=lo+5; i++) {
            res = min(res, f(i));
        }

        cout<<res<<endl;
    }


    return 0;

}
