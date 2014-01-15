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

int n,s,k;
int p[1010];
int sum[1010][1010];
int v[1010];
int dp[1010][50];
vector<int> all[1010];

void update(int x) {
    for(;x<=n+1;x+=(x&-x)) v[x]++;
}
int get(int x) {
    int res = 0;
    for(;x>=1;x-=(x&-x)) res+=v[x];
    return res;
}

int solve(int i, int cur) {
    if (i==s+1) {
        if (cur==k) return 0;
        else return 100000000;
    }
    if (cur==k) return 100000000;
    if (dp[i][cur]>=0) return dp[i][cur];

    int tmp = 100000000;
    for (int j=i; j<=s; j++) {
        tmp = min(tmp, sum[i][j] + solve(j+1,cur+1));
    }
    dp[i][cur] = tmp;

    return tmp;
}

int main() {

    freopen("flight.in","r",stdin);
    freopen("flight.out","w",stdout);

    cin>>n>>s>>k;
    for (int i=0; i<n; i++) scanf("%d",p+i);
    for (int i=0; i<n; i++) all[p[i]].push_back(i+1);
    for (int i=1; i<=s; i++) {
        for (int j=1; j<=n+1; j++) v[j] = 0;
        for (int j=i; j<=s; j++) {
            for (int t=0; t<all[j].size(); t++) {
                sum[i][j] += get(all[j][t]-1);
            }
            for (int t=0; t<all[j].size(); t++) {
                update(all[j][t]);
            }
        }
        for (int j=i+1; j<=s; j++) sum[i][j] += sum[i][j-1];
        //for (int j=i; j<=s; j++) cout<<i<<" "<<j<<" "<<sum[i][j]<<endl;
    }
    for (int i=0; i<=s; i++) for (int j=0; j<=k; j++) dp[i][j] = -1;
    int ans = solve(1,0);

    cout<<ans<<endl;

    return 0;

}
