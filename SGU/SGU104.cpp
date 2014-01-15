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

int f,v;
int c[105][105];
int dp[105][105];
int pre[105][105];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>f>>v;
    for (int i=0; i<f; i++) for (int j=0; j<v; j++) scanf("%d",&c[i][j]);

    for (int i=0; i<=v; i++) {
        for (int j=0; j<=f; j++) {
            if (j>v) continue;
            dp[i][j] = -1000000000;
            for (int k=0; k<i; k++) if (j>=0) {
                if (dp[k][j-1]+c[j-1][k]>dp[i][j]) {
                    dp[i][j] = dp[k][j-1]+c[j-1][k];
                    pre[i][j] = k+1;
                }
            }
            if (j==0) dp[i][j] = 0;
            //cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
        }
    }

    cout<<dp[v][f]<<endl;
    int ii = v;
    int jj = f;

    vector<int> sol;
    while (true) {
        sol.push_back(pre[ii][jj]);
        int tmp = pre[ii][jj];
        jj--;
        ii = tmp-1;
        if (jj==0) break;
    }
    reverse(sol.begin(),sol.end());

    for (int i=0; i<sol.size(); i++) cout<<sol[i]<<" ";

    return 0;

}
