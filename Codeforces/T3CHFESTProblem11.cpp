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

int cycle_length ( const vector<int> &A ) {
    int n = A.size();

    int a = A[0];
    int b = A[b];
    while (a!=b) {
        a = A[a];
        b = A[A[b]];
    }

    int m = 0;
    a = 0;
    while (a!=b) {
        a = A[a];
        b = A[b];
        m++;
    }

    int res = 0;
    b = A[a];
    while (a!=b) {
        b = A[b];
        res++;
    }

    return res;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int v[] = {2,3,1,1,3}

    vector<int> a = v;

    cout<<cycle_length(a)<<endl;

    return 0;

}
