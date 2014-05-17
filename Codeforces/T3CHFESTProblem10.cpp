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

#define MAX 100000000

int poly_coefs_sum ( const vector<int> &A ) {
    long long sum = A[0];
    int n = A.size();

    for (int i=1; i<n; i++) {
        sum = sum + sum*((long long)A[i]);
        if (sum>MAX) return -1;
    }

    return (int)sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
