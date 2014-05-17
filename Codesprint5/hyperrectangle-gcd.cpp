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

int K;
int a[505];
int m;
const long long mod = 1000000007;
bool vis[100100];
int cnt[20];
int dp[100010][505];
int sum[100010];

int gcd(int x, int y) {
    if (x<y) return gcd(y,x);
    if (y==0) return x;
    return gcd(y, x%y);
}

int solve(int g, int i) {
    if (i==K) return g;
    if (dp[g][i]>=0) return dp[g][i];

    int tmp = 0;

    for (int j=1; j<=a[i]; j++) {
        int x = gcd(g, j);
        tmp = (tmp + solve(x, i+1))%mod;
    }

    dp[g][i] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>K;
        for (int i=0; i<K; i++) scanf("%d",a+i);
        m = 0;
        for (int i=0; i<K; i++) m = max(m, a[i]);

        for (int i=0; i<=K; i++) {
            for (int j=0; j<=m; j++) dp[j][i] = -1;
        }

        int ans = 0;

        for (int i=1; i<=a[0]; i++) ans = (ans + solve(i, 1))%mod;

        printf("%d\n", ans);
    }

    return 0;

}
