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
long long dp[50][3];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    dp[1][0]=1;
    dp[1][1]=0;
    dp[1][2]=1;
    dp[2][0]=1;
    dp[2][1]=0;
    dp[2][2]=1;
    for(int i=3;i<=n;i++)
    {
        if( i<n)
        {
        dp[i][0]=dp[i-1][2]+dp[i-2][2];
        dp[i][1]=dp[i][1]+dp[i][2];
        dp[i][2]=dp[i-1][0]+dp[i-2][0];
        }
        else
        {
            dp[i][0]=dp[i-1][2]+dp[i-2][2];
            dp[i][2]=dp[i-1][0]+dp[i-2][0];
        }
    }
    cout<<dp[n][0]+dp[n][2]<<endl;
    return 0;

}
