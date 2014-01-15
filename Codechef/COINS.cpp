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

map<int ,long long> dp;

long long solve(int a) {
    if (a<2) return a;
    if (dp[a]) return dp[a];
    long long x = solve(a/2);
    long long y = solve(a/3);
    long long z = solve(a/4);

    long long tmp = max((long long)a, x+y+z);
    dp[a] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    while (cin>>n) {
        long long ans = solve(n);
        cout<<ans<<"\n";
    }

    return 0;

}
