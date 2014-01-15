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

int n,k;
int x[55], y[55];
int dp[2][2510][51];
int p[55];


bool comp(int i, int j) {
    return y[i]*x[j] > y[j]*x[i];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        cin>>n>>k;
        for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);
        for (int i=0; i<=2500; i++) for (int j=0; j<=k; j++) dp[0][i][j] = 0;
        for (int i=0; i<n; i++) p[i] = i;
        sort(p,p+n,comp);
        dp[0][0][0] = 1;
        for (int i=0; i<n; i++) {
            for (int j=0; j<=2500; j++) for (int r=0; r<=k; r++) dp[1-i%2][j][r] = 0;
            for (int j=0; j<=2500; j++) for (int r=0; r<=k; r++) if (dp[i%2][j][r]>0) {
                dp[1-i%2][j][r] = max(dp[1-i%2][j][r], dp[i%2][j][r]);
                if (r==k || j+y[p[i]]>2500) continue;
                dp[1-i%2][j+y[p[i]]][r+1] = max(dp[1-i%2][j+y[p[i]]][r+1], dp[i%2][j][r] + 2*j*x[p[i]] + x[p[i]]*y[p[i]]);
            }
        }
        int ans = 0;
        for (int i=0; i<=2500; i++) ans = max(ans, dp[n%2][i][k]-1);
        printf("Case %d: %d\n",t,ans);
    }

    return 0;

}
