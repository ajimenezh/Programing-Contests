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

#define div DIV

int k,n;
int dp[2010][2010];
const int mod = 1000000007;
vector<int> div[2010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=i; j++) {
            if (i%j==0) {
                div[i].push_back(j);
            }
        }
    }

    for (int i=0; i<k; i++) {
        for (int j=1; j<=n; j++) {
            if (i==0) dp[i][j] = 1;
            else {
                for (int t=0; t<div[j].size(); t++) {
                    dp[i][j] = (dp[i][j] + dp[i-1][div[j][t]])%mod;
                }
            }
        }
    }

    int res = 0;
    for (int i=1; i<=n; i++) res = (res + dp[k-1][i])%mod;

    cout<<res<<endl;

    return 0;

}
