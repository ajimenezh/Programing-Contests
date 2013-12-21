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
int c[3010][3];
int dp[3010][2];

int solve(int i, int last) {
    if (i==n-1) {
        return c[i][last];
    }
    if (dp[i][last]>=0) return dp[i][last];

    dp[i][last] = max( c[i][last] + solve(i+1,1), c[i][last+1] + solve(i+1,0));

    return dp[i][last];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int j=0; j<3; j++) for (int i=0; i<n; i++) scanf("%d",&c[i][j]);
    for (int i=0; i<n; i++) for (int j=0; j<2; j++) dp[i][j] = -1;

    int ans = solve(0,0);

    cout<<ans<<endl;

    return 0;

}
