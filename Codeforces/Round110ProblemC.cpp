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

#define mod 1000000007LL

int n,t;
long long dp[105][2630];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    dp[0][0] = 1;
    for (int i=0; i<101; i++) {
        for (int k=0; k<2600; k++) {
            for (int j=0; j<26; j++) {
                dp[i+1][j+k] = (dp[i+1][j+k] + dp[i][k])%mod;
            }
        }
    }

    cin>>t;
    for (int i=0; i<t; i++) {
        string s;
        cin>>s;
        int sum = 0;
        for (int j=0; j<s.length(); j++) sum += s[j]-'a';
        printf("%d\n",dp[s.length()][sum]-1);
    }

    return 0;

}
