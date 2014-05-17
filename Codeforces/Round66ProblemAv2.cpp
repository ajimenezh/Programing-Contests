#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int x,y,z,k;
    cin>>x>>y>>z>>k;

    long long res = 1;

    if (x>y) swap(x,y);
    if (x>z) swap(x,z);
    if (y>z) swap(y,z);

    int a = min(x-1, k/3);
    res *= a+1;
    k -= a;
    a = min(y-1, k/2);
    res *= a+1;
    k -= a;
    a = min(z-1, k);
    res *= a+1;

    cout<<res<<endl;

    return 0;

}
