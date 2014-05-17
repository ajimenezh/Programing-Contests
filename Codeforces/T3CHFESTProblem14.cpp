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


int whole_cubes_count ( int A,int B ) {
    int c = 0;
    for (long long i=1; i*(i*i)<=B; i++) {
        if ((i*i)*i>=A) c++;
    }
    return c;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);



    return 0;

}
