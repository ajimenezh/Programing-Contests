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

#define INF 1000000

#define pii pair<int,int>
#define mp make_pair

int n;
int c[305][305];
int dp[605][305][305];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d",&c[i][j]);
    //for (int i=0; i<n; i++) for (int j=0; j<n; j++) c[i][j] = i*n+j;

    for (int i=0; i<2*n; i++) for (int j=0; j<n; j++) for (int k=0; k<n; k++) dp[i][j][k] = -1000000000;

    dp[0][0][0] = c[0][0];

    if (n==1) {
        cout<<c[0][0]<<endl;
        return 0;
    }

    for (int i=1; i<n; i++) {
        for (int j=0; j<=i; j++) {
            for (int k=j+1; k<=i; k++) {
                if (j>0 && k>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k-1]+c[i-j][j]+c[i-k][k]);
                if (k>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-1]+c[i-j][j]+c[i-k][k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+c[i-j][j]+c[i-k][k]);
                if (j>0) dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-1][k]+c[i-j][j]+c[i-k][k]);
                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
            if (j>0) dp[i][j][j] = max(dp[i][j][j],dp[i-1][j-1][j]+c[i-j][j]);
            if (j>0) dp[i][j][j] = max(dp[i][j][j],dp[i-1][j-1][j-1]+c[i-j][j]);
            dp[i][j][j] = max(dp[i][j][j],dp[i-1][j][j]+c[i-j][j]);
            //cout<<i<<" "<<j<<" "<<j<<" "<<dp[i][j][j]<<endl;
        }
    }
    for (int i=n; i<2*n-1; i++) {
        for (int j=0; j<(2*n-i-1); j++) {
            for (int k=j+1; k<(2*n-i-1); k++) {
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j+1][k+1]+c[n-1-j][(i-n+1)+j]+c[n-1-k][(i-n+1)+k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k+1]+c[n-1-j][(i-n+1)+j]+c[n-1-k][(i-n+1)+k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k]+c[n-1-j][(i-n+1)+j]+c[n-1-k][(i-n+1)+k]);
                dp[i][j][k] = max(dp[i][j][k],dp[i-1][j+1][k]+c[n-1-j][(i-n+1)+j]+c[n-1-k][(i-n+1)+k]);
                //cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl;
            }
            dp[i][j][j] = max(dp[i][j][j],dp[i-1][j][j+1]+c[n-1-j][(i-n+1)+j]);
            dp[i][j][j] = max(dp[i][j][j],dp[i-1][j+1][j+1]+c[n-1-j][(i-n+1)+j]);
            dp[i][j][j] = max(dp[i][j][j],dp[i-1][j][j]+c[n-1-j][(i-n+1)+j]);
            //cout<<i<<" "<<j<<" "<<j<<" "<<dp[i][j][j]<<endl;
        }
    }

    cout<<dp[2*n-2][0][0];

    return 0;

}
