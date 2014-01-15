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

int n;
int q;
int last[1000010];
int dif[1000010];
int num[1000010];
int a[1000010];
long long dp[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        for (int i=0; i<n; i++) scanf("%d",a+i);
        for (int i=0; i<n; i++) last[a[i]] = 0;
        for (int i=0; i<=n; i++) dif[i] = 0;
        for (int i=0; i<n; i++) {
            dif[i+1-last[a[i]]]++;
            last[a[i]] = i+1;
        }
        for (int i=0; i<n; i++) last[a[i]] = 0;
        num[0] = 0;
        for (int i=n-1; i>=0; i--) {
            last[a[i]]++;
            if (last[a[i]]==1) num[n-i] = num[n-i-1] + 1;
            else  num[n-i] = num[n-i-1];
        }
        int cur = n;
        dp[1] = n;
        for (int i=2; i<=n; i++) {
            cur -= dif[i-1];
            dp[i] = dp[i-1] + cur - num[i-1];
        }
        cin>>q;
        for (int i=0; i<q; i++) {
            int w;
            scanf("%d",&w);
            cout<<dp[w]<<"\n";
        }
    }

    return 0;

}
