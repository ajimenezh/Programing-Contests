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

int t;
long long a,b;

bool solve(long long x, long long y) {
    if (x==0 || y==0) return 1;
    if (y>x) return  solve(y,x);
    bool f = 0;
    f |= solve(x%y,y);
    f |= ((x/y - 1) % (y+1) ) % 2;
    return 1-f;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%I64d%I64d",&a,&b);
        bool f = solve(a,b);
        if (f) printf("Second\n");
        else printf("First\n");
    }

    return 0;

}
