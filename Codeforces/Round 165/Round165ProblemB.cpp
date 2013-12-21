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
int c[5010];
int dp[5010][5010];

int solve(int i, int j) {
    if (i==n) return 0;
    if (dp[i][j]>=0) return dp[i][j];

    if (c[i]==j) {
        dp[i][j] = solve(i+1,j);
    }
    else if (c[i]<j) {
        dp[i][j] = 1 + solve(i+1,j);
    }
    else {
        dp[i][j] = min(1+solve(i+1,j), solve(i+1,c[i]));
    }
    return dp[i][j];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        int t;
        double f;
        cin>>t>>f;
        c[i] = t;
        c[i]--;
    }
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) dp[i][j] = -1;
    cout<<solve(0,0);

    return 0;

}
