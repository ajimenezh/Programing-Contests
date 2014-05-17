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

int n,k,m;
int d[101];
set<int> s;
bool dp[101][10010];
long long p[3001][3001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>m;
    for (int i=0; i<n; i++) cin>>d[i];

    for (int i=0; i<=n; i++) for (int j=0; j<=101*n; j++) dp[i][j] = 0;

    dp[0][0] = 1;
    for (int i=0; i<n; i++) {
        for (int j=0; j<=101*n; j++) {
            dp[i+1][j] = dp[i][j];
            if (j-d[i]>=0) {
                dp[i+1][j] = (dp[i+1][j] || dp[i][j-d[i]]);
            }
        }
    }
    int z = 0;
    for (int i=m-1; i>=0; i--) if (dp[n][i]) {z = i; break;}
    cout<<z<<endl;

    for (int i=0; i<=z; i++) for (int j=0; j<=z; j++) p[i][j] = 0;
    for (int i=1; i<=z; i++) p[i][i] = 1;
    for (int i=1; i<=z; i++) for (int j=i-1; j>=1; j--) p[j][i] = (p[j+1][i] + p[j][i-j])%1000000007;

    long long cnt = 1LL;

    for (int i=1; i<=z/2; i++) cnt = (cnt + p[i][z-i])%1000000007;

    cout<<cnt<<endl;

    return 0;

}
