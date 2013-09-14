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

int dp[650][650];
int w,h,n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int cas;
    cin>>cas;
    while (cas--) {
        scanf("%d%d",&w,&h);
        scanf("%d",&n);
        for (int i=0; i<=w; i++) for (int j=0; j<=h; j++) dp[i][j] = 100000000;
        for (int i=0; i<n; i++) {
            int x,y;
            scanf("%d%d",&x,&y);
            dp[x][y] = 0;
        }
        for (int i=0; i<=w; i++) dp[i][0] = 0;
        for (int i=0; i<=h; i++) dp[0][i] = 0;
        for (int i=0; i<=w; i++) for (int j=0; j<=h; j++) {
            dp[i][j] = min(dp[i][j], i*j);
            for (int k=1; k<=i; k++) dp[i][j] = min(dp[i][j], dp[k][j] + dp[i-k][j]);
            for (int k=1; k<=j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j-k]);
        }
        cout<<dp[w][h]<<endl;
    }

    return 0;

}


