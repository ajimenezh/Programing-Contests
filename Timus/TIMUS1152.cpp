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
int v[21];
int dp[1<<20];
int damage[1<<20];

int solve(int mask) {
    if (mask==0) return 0;
    if (dp[mask]>=0) return dp[mask];

    int tmp = 1000000;
    for (int i=0; i<n; i++) {
        int x = i;
        int x1 = (i+1)%n;
        int x2 = (i-1)%n;
        int next = (1<<x) + (1<<x1) + (1<<x2);
        if (mask&next) {
            next = mask;
            if (next&(1<<x)) next -= (1<<x);
            if (next&(1<<x1)) next -= (1<<x1);
            if (next&(1<<x2)) next -= (1<<x2);

            tmp = min(tmp, damage[next] + solve(next));
        }
    }

    dp[mask] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>v[i];
    for (int i=0; i<(1<<n); i++) dp[i] = -1;

    for (int i=0; i<(1<<n); i++) {
        int t = 0;
        for (int j=0; j<n; j++) if (i&(1<<j)) t += v[j];
        damage[i] = t;
    }


    cout<<solve((1<<n)-1);

    return 0;

}
