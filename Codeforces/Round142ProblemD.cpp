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

long long sum[5010];
long long dp[5010];
int c[5010];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        cin>>a;
        sum[i+1] = sum[i] + a;
    }

    dp[1] = sum[1];
    c[1] = 0;
    for (int i=2; i<=n; i++) {
        dp[i] = sum[i];
        c[i] = i-1;
        for (int j=1; j<i; j++) {
            if (sum[i]-sum[j]>=dp[j] && sum[i]-sum[j]<=dp[i]) {
                if (dp[i]>sum[i]-sum[j]) {
                    dp[i]=sum[i]-sum[j];
                    c[i] = c[j] + (i-j-1);
                }
                else {
                    c[i] = min(c[i],c[j] + (i-j-1));
                }
            }
        }
        //cout<<dp[i]<<" "<<c[i]<<endl;
    }

    cout<<c[n]<<endl;

    return 0;

}
