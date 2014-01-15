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
int s[110];
int m;
pair<int,int> q[21];
int dp[1<<20];
bool vis[1<<20];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>s[i];
    sort(s,s+n);
    reverse(s,s+n);
    cin>>m;
    for (int i=0; i<m; i++) {
        char c; int t;
        cin>>c>>t;
        int p;
        if (c=='p') p = 1;
        else p = 0;
        q[i] = make_pair(t,p);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n-1; j++) {
            if (q[i].second==q[i+1].second && q[i].first==0 && q[i+1].first==1) {
                swap(q[i], q[i+1]);
            }
        }
    }
    n = m;


    //cout<<ans<<endl;
    for (int i=1; i<(1<<n); i++) {
        int k = __builtin_popcount(i) - 1;
        if (q[k].first==1) {
            dp[i] = -10000000;
            if (q[k].second==1) {
                for (int j=n-1; j>=0; j--) if (((1<<j)&i)) {
                    dp[i] = max(dp[i-(1<<j)]+s[j],dp[i]);
                    break;
                }
            }
            else {
                for (int j=0; j<n; j++) if (((1<<j)&i)) {
                    dp[i] = max(dp[i-(1<<j)],dp[i]);
                }
            }
        }
        else {
            dp[i] = 100000000;
            if (q[k].second==1) {
                for (int j=n-1; j>=0; j--) if (((1<<j)&i)) {
                    dp[i] = min(dp[i-(1<<j)]-s[j],dp[i]);
                    break;
                }
            }
            else {
                for (int j=0; j<n; j++) if (((1<<j)&i)) {
                    dp[i] = min(dp[i-(1<<j)],dp[i]);
                }
            }
        }
        cout<<i<<" "<<dp[i]<<endl;
    }

    cout<<dp[(1<<n)-1];

    return 0;

}
