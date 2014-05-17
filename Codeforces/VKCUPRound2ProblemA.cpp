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

const int mod = 1000000007;

string s,t;
int dp[5010][5010][2];
int n,m;

int sum(int a, int b) {
    int c = a+b;
    if (c>=mod) c -= mod;
    return c;
}

int solve(int i, int j, int k) {
    if (i==n || j==m) {
        return 0;
    }
    if (dp[i][j][k]>=0) return dp[i][j][k];

    int tmp = 0;
    if (k) {
        if (s[i]==t[j]) {
            tmp = sum(1+solve(i+1,j+1,1), solve(i,j+1,1));
        }
        else {
            tmp = solve(i,j+1,1);
        }
    }
    else {
        if (s[i]==t[j]) {
            tmp = sum(solve(i+1,j,0), solve(i,j+1,1));
            tmp = sum(1+solve(i+1,j+1,1),tmp);
        }
        else {
            tmp = sum(solve(i+1,j,0), solve(i,j+1,1));
        }
    }
    //cout<<i<<" "<<j<<" "<<k<<" "<<tmp<<endl;
    dp[i][j][k] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s>>t;
    n = s.length();
    m = t.length();
    for (int i=0; i<=n; i++) for (int j=0; j<=m; j++) for (int k=0; k<2; k++) dp[i][j][k] = -1;

    int ans = solve(0,0,0);

    cout<<ans<<endl;

    return 0;

}
