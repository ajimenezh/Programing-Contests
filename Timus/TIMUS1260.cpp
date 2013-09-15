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
long long dp[60][60];

long long solve(int k, int last) {
    if (k==n) return 1;
    if (k>n) return 0;
    if (dp[k][last]>=0) return dp[k][last];

    long long tmp = 1;
    if (k+1-last<=2) tmp += solve(k+1,k+1);
    if (k+2-last<=2) tmp += solve(k+3,k+1);

    dp[k][last] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = -1;
    cout<<solve(1,1)+(n>=5?1:0)<<endl;

    return 0;

}
