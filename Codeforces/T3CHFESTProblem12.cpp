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

#define MAX 1LL<<60

int extreme ( const vector<int> &A ) {
    long long k;
    int n = A.size();
    long long hi = -MAX;
    long long lo = MAX;
    int h,l;

    for (int i=0; i<n; i++) {
        k += (long long)A[i];
        if (hi<(long long)A[i]) {
            hi = (long long)A[i];
            h = i;
        }
        if (lo>(long long)A[i]) {
            lo = (long long)A[i];
            l = i;
        }
    }

    hi = (long long)n*hi - k;
    lo = k - (long long)n*lo;

    if (hi>lo) return h;
    return l;

}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
