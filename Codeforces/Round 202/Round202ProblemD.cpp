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

#define mod 1000000007

int n,m;
bool a[3001][3001];
long long dp[3001][3001];

long long add(long long a, long long b) {
    a = a+b;
    while (a>=mod) a -= mod;
    return a;
}

long long solve(int x1, int y1, int x2, int y2) {
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            dp[i][j] = 0;
        }
    }
    if (a[x1][y1]) dp[x1][y1] = 1;

    if (!a[x1][y1] || !a[x2][y2]) return 0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) if (a[i][j]) {
            if (j==0) {
                if (i==0) continue;
                if (a[i-1][j]) {
                    dp[i][j] = add(dp[i][j],dp[i-1][j]);
                }
            }
            else {
                if (i==0) {
                    if (a[i][j-1]) {
                        dp[i][j] = add(dp[i][j],dp[i][j-1]);
                    }
                }
                else {
                    if (a[i][j-1]) {
                        dp[i][j] = add(dp[i][j],dp[i][j-1]);
                    }
                    if (a[i-1][j]) {
                    dp[i][j] = add(dp[i][j],dp[i-1][j]);
                }
                }
            }
        }
    }

    return dp[x2][y2];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<m; j++) a[i][j] = (s[j]=='.');
    }

    long long a11 = solve(0,1,n-2,m-1);
    long long a12 = solve(0,1,n-1,m-2);
    long long a21 = solve(1,0,n-2,m-1);
    long long a22 = solve(1,0,n-1,m-2);

    long long det = (a11*a22 - a12*a21)%mod;
    det = (det+mod)%mod;

    cout<<det<<endl;

    return 0;

}
