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


int maxRS ( const vector<int> &A ) {
    int n = A;
    int l = 0;
    int b = 0;

    for (int i=0; i<n; i++) {
        int now = 1;
        int j = i;
        i++;
        while (i<n && A[i]) {now++; i++;}
        i--;
        if (now>l) {
            b = j;
        }
    }

    return j;
}



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
