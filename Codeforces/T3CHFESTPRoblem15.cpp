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

#define eps 10e-8


int lattice_points_on_disk ( int N ) {
    long long c = 0;
    long long n = (long long)N;
    long long x = n;

    for (long long i=1; i<N; i++) {
        long long y = n*n - i*i;
        while (x*x>y) x--;
        c += x;

    }

    //cout<<c<<endl;

    long long res = c*4LL + 4LL*N + 1LL;

    if (res>1000000000LL) return -1;
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cout<<lattice_points_on_disk(1000000)<<endl;

    return 0;

}
