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

int i,j, n;
long long fi,fj;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%I64d%d%I64d%d",&i,&fi,&j,&fj,&n);

    if (j<i) {
        swap(i,j);
        swap(fi,fj);
    }

    long long lo = -2000000000LL;
    long long hi = 2000000000LL;

    while (lo+1<hi) {
        long long mi = (lo+hi)/2;
        long long f0 = fi;
        long long f1 = mi;
        bool pos = 0, neg = 0;
        for (int k=i+2; k<=j; k++) {
            if (f0 > 2000000000LL - f1) {
                pos = true;
                break;
            }
            if (f0 < -2000000000LL - f1) {
                neg = true;
                break;
            }

            long long tmp = f1+f0;
            f0 = f1;
            f1 = tmp;
        }
        if (!neg && !pos) {
            if (f1>=fj) hi = mi;
            else lo = mi + 1;
        }
        else {
            if (neg) lo = mi+1;
            else hi = mi;
        }
    }

    long long f0 = fi;
    long long f1 = lo;
    if (n>=i+1) {
        for (int k=i+2; k<=n; k++) {
            long long tmp = f1+f0;
            f0 = f1;
            f1 = tmp;
        }
        cout<<f1<<endl;
    }
    else {
        for (int k=i-1; k>=n; k--) {
            long long tmp = f1-f0;
            f1 = f0;
            f0 = tmp;
        }
        cout<<f0<<endl;
    }

    return 0;

}
