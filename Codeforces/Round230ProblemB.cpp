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

long long dp[40][3][3];
int n;
int t[3][3];

long long solve(int k, int i, int j) {
    if (k==0) return 0;
    if (dp[k][i][j]>=0) return dp[k][i][j];

    long long tmp = 0;
    tmp = solve(k-1, i, (i+1)%3) + t[i][(i+2)%3] + solve(k-1,(i+1)%3, (i+2)%3) ;

    dp[k][i][j] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            cin>>t[i][j];
        }
    }
    cin>>n;

    for (int i=0; i<=n; i++)  for (int j=0; j<3; j++) for (int k=0; k<3; k++) dp[i][j][k] = -1;

    cout<<solve(n, 0, 2);

    return 0;

}
