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

long long dp[10][90];
int solve(int d, int sum) {
    if (sum==0) return 1;
    if (d==0) return 0;
    if (sum<0) return 0;
    if (dp[d][sum]>=0) return dp[d][sum];

    int tmp = 0;
    for (int i=0; i<10; i++) tmp += solve(d-1,sum-i);
    dp[d][sum] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int s;
    for (int i=0; i<10; i++) for (int j=0; j<82; j++) dp[i][j] = -1;
    cin>>s;
    if (s==1) cout<<10<<endl;
    else cout<<solve(9,s);

    return 0;

}
