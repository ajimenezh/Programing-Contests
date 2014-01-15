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

int n,m;
long long dp[5010][2];

long long solve(int a, int b) {
    if (a==m && b==0) return 1;
    if (a==m) return 0;
    if (dp[a][b]>=0) return dp[a][b];

    long long tmp = 0;
    if (b==0) {
        tmp = n*solve(a+1,1);
    }
    else {
        tmp = 2*solve(a+1,1);
        tmp += solve(a+1,0);
    }

    dp[a][b] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        dp[i][1] = -1;
        dp[i][0] = -1;
    }
    cout<<solve(0,0);

    return 0;

}
