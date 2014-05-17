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

int amplitude ( const vector<int> &A ) {
    int lo = 6000000;
    int hi = -1;
    int n = A.size();
    for (int i=0; i<n; i++) {
        lo = min(lo,A[i]);
        hi = max(hi,A[i]);
    }

    return hi-lo;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
