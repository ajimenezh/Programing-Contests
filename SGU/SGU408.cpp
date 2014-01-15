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
double dp[1100][1100];
bool vis[1100][1100];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    if (n==1) {
        cout<<"1.000"<<endl;
        return 0;
    }
    if (n==2) {
        cout<<"5.000"<<endl;
        return 0;
    }

    double sum = 0.0;

    dp[2][2] = 5;
    for (int i=2; i<=n; i++) {
        for (int j=2; j<=n; j++) {
            if (dp[i][j]>=0) {
                dp[i+1][j] = max(dp[i+1][j], dp[i][j] + (i+1)*j);
                dp[i][j+1] = max(dp[i][j+1], dp[i][j] + (j+1)*i);
            }
            if (i-2+j==n) sum = max(dp[i][j], sum);
        }
    }
    printf("%.3lf",sum);

    return 0;

}
