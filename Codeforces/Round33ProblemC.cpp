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

int n;
int a[100010];
int dp[100010][2];
int dp2[100010][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    for (int i=0; i<n; i++) {
        dp[i+1][0] = max(dp[i][0],dp[i][1]) + a[i];
        dp[i+1][1] = dp[i][1] - a[i];
    }

    for (int i=n-1; i>=0; i--) {
        dp2[i][0] = max(dp2[i+1][0],dp2[i+1][1]) + a[i];
        dp2[i][1] = dp2[i+1][1] - a[i];
    }

    int res = max(max(dp[n][1],dp[n][0]), max(dp2[0][0],dp2[0][1]));
    for (int i=0; i<=n; i++) {
        res = max(dp[i][0] + dp2[i][0], res);
        res = max(dp[i][1] + dp2[i][0], res);
        res = max(dp[i][0] + dp2[i][1], res);
        res = max(dp[i][1] + dp2[i][1], res);
    }

    cout<<res<<endl;

    return 0;

}
