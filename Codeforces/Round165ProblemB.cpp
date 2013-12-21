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
int dp[5010][5010];
int c[5010];

int solve(int i, int k) {
    if (i==n) return 0;
    if (dp[i][k]>=0) return dp[i][k];

    int res = 0;
    if (c[i]==k) res = solve(i+1,k);
    else {
        if (c[i]<k) res = solve(i+1,k) + 1;
        else res = min(solve(i+1,k)+1, solve(i+1,c[i]));
    }

    dp[i][k] = res;
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        double tmp;
        scanf("%d%lf", c+i, &tmp);
    }
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) dp[i][j] = -1;

    cout<<solve(0,1);

    return 0;

}
