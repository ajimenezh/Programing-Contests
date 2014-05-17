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

#define mod 1000000007

int n,m;
long long dp[1000100];
int c[22];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<=n; i++)  dp[i] = 0;
    for (int i=0; i<22; i++) c[i] = -1;
    c[0] = 1;
    int j = 1;
    for (long long i=m; i<=n; i=(i*(long long)m)) c[j++] = i;
    //for (int i=0; i<22; i++) cout<<c[i]<<endl;

    dp[0] = 1;
    for (int j=0; j<22; j++) if (c[j]>0) {
        for (int i=0; i<=n; i++) if (i-c[j]>=0) {
            dp[i] = (dp[i-c[j]] + dp[i])%mod;
        }
    }

    cout<<dp[n];

    return 0;

}
