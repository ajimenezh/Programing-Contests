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
int dp[1010];
string s;

int solve(int k) {
    if (k==n) return 0;
    if (dp[k]!=-1) return dp[k];

    int tmp = 1;
    for (int i=k+1; i<n; i++) {
        if (s[i]==s[k] && (i-k)%2==1) tmp = max(tmp, 1 + solve(i));
    }

    dp[k] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;

    n = s.length();

    int res = 0;
    for (int i=0; i<n; i++) dp[i] = -1;
    for (int i=0; i<n; i++) res = max(res, solve(i));

    cout<<res<<endl;

    return 0;

}
