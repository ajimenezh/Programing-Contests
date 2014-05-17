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

int hex_bitcount ( const string &S ) {
    val[16] = {0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};

    int res = 0;

    for (int i=0; i<S.length(); i++) {
        if (S[i]>='0' && S[]<='9') res += val[S[i]-'0'];
        else res += val[10 + S[i]-'A'];
    }

    return res;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
