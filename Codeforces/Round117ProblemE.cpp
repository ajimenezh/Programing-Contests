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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define mod 1000000007

int n,l;
int a[101], b[101];
long long dp[3001][101][2];

long long solve(int len, int pre, int rot)
{
    if (len==0) return 1;
    if (len<0) return 0;
    if (dp[len][pre][rot]!=-1) return dp[len][pre][rot];

    long long tmp = 0;

    for (int i=0; i<n; i++) if (i!=pre) {
        if (rot==0 && b[pre]==a[i]) {
            tmp += solve(len-a[i],i,0);
            tmp %= mod;
        }
        if (rot==0 && b[pre]==b[i] && a[i]!=b[i]) {
            tmp += solve(len-b[i],i,1);
            tmp %= mod;
        }
        if (rot==1 && a[pre]==a[i]) {
            tmp += solve(len-a[i],i,0);
            tmp %= mod;
        }
        if (rot==1 && a[pre]==b[i] && a[i]!=b[i]) {
            tmp += solve(len-b[i],i,1);
            tmp %= mod;
        }
    }

    dp[len][pre][rot] = tmp;
    return tmp;
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n>>l;
    for (int i=0; i<n; i++) cin>>a[i]>>b[i];

    for (int i=0; i<=l; i++) for (int j=0; j<=n; j++) for (int k=0; k<2; k++) dp[i][j][k] = -1;

    long long res = 0;
    for (int i=0; i<n; i++) {
        res += solve(l-a[i],i,0)%mod;
        res %= mod;
        if (a[i]!=b[i]) res += solve(l-b[i],i,1)%mod;
        res %= mod;
    }

    cout<<res;


	return 0;

}
