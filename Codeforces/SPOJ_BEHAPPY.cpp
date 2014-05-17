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

int n,m;
long long dp[21][101];
pair<int,int> v[21];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>m>>n && m!=0 || n!=0) {
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            v[i] = make_pair(a,b);
        }
        for (int i=0; i<=n; i++) for (int j=0; j<m; j++) dp[j][i] = 0;
        dp[0][0] = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<=n; j++) {
                for (int k=v[i].first; k<=v[i].second; k++) {
                    if (j-k>=0) dp[i+1][j] += dp[i][j-k];
                }
            }
        }
        printf("%I64d\n",dp[m][n]);
    }

    return 0;

}
