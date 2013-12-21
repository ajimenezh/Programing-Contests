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

int dp[1000010];
int f[1000010];
int n;
int a[100010];
int x,y;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    //for (int i=0; i<100000; i++) a[i] = (15467158+rand())%1000000000;
    sort(a,a+n);
    int tot = 0;
    a[tot++] = a[0];
    for (int i=1; i<n; i++) if (a[i]!=a[i-1]) {
        a[tot++] = a[i];
    }
    n = tot;
    cin>>x>>y;

    for (int i=1; i<=(x-y); i++) dp[i] = y+i-1;

    for (int i=0; i<n; i++) {
        int l = (y/a[i])*a[i];
        while (l<=y) l+=a[i];
        for (;l<=x;l+=a[i]) if (l-1>=y && l-a[i]>=y) dp[l-1-y] = min(dp[l-1-y], l-a[i]);
        if (x-x%a[i]>=y) dp[x-y] = min(dp[x-y], x-x%a[i]);
    }
    //for (int i=x; i>=y; i--) cout<<i<<" "<<dp[i-y]<<endl;
    for (int i=x-1; i>=y; i--) dp[i-y] = min(dp[i-y], dp[i+1-y]);
    f[0] = 0;
    for (int i=y+1; i<=x; i++) f[i-y] = f[dp[i-y]-y] + 1;

    cout<<f[x-y]<<endl;

    return 0;

}
