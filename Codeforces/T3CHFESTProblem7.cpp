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

int distinct ( const vector<int> &A ) {
    vector<in> a = A;
    sort(a.begin(),a.end());
    int n = A.size();
    int res = 0;
    for (int i=1; i<n; i++) {
        if (a[i]!=a[i-1]) res++;
    }
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
