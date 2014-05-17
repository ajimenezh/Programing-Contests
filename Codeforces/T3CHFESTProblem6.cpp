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

int equalization_steps ( const vector<int> &A ) {
    int lo = 250000000;
    int hi = -250000000;
    int n = A.size();
    for (int i=0; i<n; i++) {
        lo = min(lo,A[i]);
        hi = max(hi,A[i]);
    }

    int mi = (hi+lo)/2;
    int res = max(hi-mi,mi-lo);

    for (int i=0; i<n; i++) {
        if ((abs(A[i]-mi)-res)%2!=0) return -1;
    }

    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
