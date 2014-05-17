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

int fpow(int a, int b){
    if (b==0) return 1;
    if (b%2==0) return fpow(a,b/2)*fpow(a,b/2);
    return fpow(a,b/2)*fpow(a,b/2)*a;
}

bool check(int a, int k) {
    int sum = 0;
    int t = a;
    while (a>0) {sum += fpow(a%10,k); a/= 10;}
    return sum == t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int sum = 0;
    int k = 5;
    for (int i=2; i<300000; i++) {
        if (check(i,k)) sum += i;
    }

    cout<<sum<<endl;

    return 0;

}
