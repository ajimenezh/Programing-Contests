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

long long dp[45][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,k;
    cin>>n>>k;

    dp[1][1] = 1;
    dp[1][0] = 1;

    for (int i=2; i<=n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1];
        dp[i][1] = dp[i-1][0];
    }

    string s;

    if (k>dp[n][1]+dp[n][0]) {
        cout<<-1;
        return 0;
    }

    for (int i=n; i>=1; i--) {
        if (k>dp[i][0]) {
            s += "1";
            k -= dp[i][0];
        }
        else s += "0";
    }

    cout<<s<<endl;


    return 0;

}
