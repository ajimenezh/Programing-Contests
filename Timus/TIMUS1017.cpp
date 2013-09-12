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
unsigned long long dp[505][505];
unsigned long long sum[505][505];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    dp[0][0] = 1;
    sum[0][0] = 1;
    for (int i=1; i<=n; i++) sum[0][i] = sum[0][0];

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            dp[i][j] = sum[i-j][j-1];
        }
        sum[i][0] = 0;
        for (int j=1; j<=n; j++) sum[i][j] = sum[i][j-1] + dp[i][j];
    }

    unsigned long long res = 0;
    for (int i=1; i<=n; i++) res += dp[n][i];

    cout<<res-1<<endl;

    return 0;

}
