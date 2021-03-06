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
int a[100010];
long long ans;
long long dp[100010][2];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) scanf("%d",a+i);
        ans = 0;
        for (int i=30; i>=0; i--) {
            long long tmp = 0;

            dp[0][0] = 0;
            dp[0][1] = 0;
            if ((1<<i)&a[0]) dp[0][1] = 1;
            else dp[0][0] = 1;
            for (int j=1; j<n; j++) {
                if ((1<<i)&a[j]) {
                    dp[j][0] = dp[j-1][1];
                    dp[j][1] = 1 + dp[j-1][0];
                }
                else {
                    dp[j][0] = 1 + dp[j-1][0];
                    dp[j][1] = dp[j-1][1];
                }
            }
            for (int j=0; j<n; j++) ans += (1LL<<i)*(dp[j][1]);
            //for (int j=0; j<n; j++) cout<<i<<" "<<j<<" "<<dp[j][0]<<" "<<dp[j][1]<<endl;
        }
        cout<<ans<<"\n";
    }

    return 0;

}
