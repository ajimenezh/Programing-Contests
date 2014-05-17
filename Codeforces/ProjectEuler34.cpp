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

int fact(int a) {
    if (a==0) return 1;
    return (a==1?1:a*fact(a-1));
}

int check(int a) {
    int t = a;
    while (t>0) {a -= fact(t%10); t/=10;}
    return a==0;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int sum = 0;

    for (int i=3; i<3500000; i++) {
        if (check(i)) {
            sum += i;
            cout<<i<<endl;
        }
    }

    cout<<sum;

    return 0;

}
