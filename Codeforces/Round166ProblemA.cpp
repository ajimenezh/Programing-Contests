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

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
bool d[10];

bool distinct(int a) {
    for (int i=0; i<10; i++) d[i] = 0;

    while (a>0) {
        if (d[a%10]==0) d[a%10] = 1;
        else return false;
        a /= 10;
    }

    return true;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=n+1; i<100000; i++) {
        if (distinct(i)) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;

}
