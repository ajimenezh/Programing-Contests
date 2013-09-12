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

int dp[21][11][11][6][6];
int n,t;
int solve(int i, int l1, int l2, int v, int pre) {
    if (l1<0 || l2<0) return 0;
    if (i==n && l1==0 && l2==0 && v<pre) return 1;
    if (i==n) return 0;
    if (dp[i][l1][l2][v][pre]!=-1) return dp[i][l1][l2][v][pre];

    int tmp = 0;
    for (int j=v+1; j<=4; j++) {
        if (v>pre || i==1) tmp += solve(i+1,l1,l2,j,v);
        else tmp += solve(i+1,l1,l2-1,j,v);
    }
    for (int j=1; j<v; j++) {
        if (v<pre || i==1) tmp += solve(i+1,l1,l2,j,v);
        else tmp += solve(i+1,l1-1,l2,j,v);
    }

    //cout<<i<<" "<<l1<<" "<<l2<<" "<<v<<" "<<pre<<" "<<tmp<<endl;
    dp[i][l1][l2][v][pre] = tmp;
    return tmp;

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>t;
    int res = 0;
    for (int i=0; i<=n; i++) for (int j=0; j<=t; j++) for (int p=0; p<=t; p++) for (int k=0; k<5; k++) for (int r=0; r<=6; r++) dp[i][j][p][k][r] = -1;
    for (int i=1; i<4; i++) res += solve(1,t,t-1,i,0);
    cout<<res<<endl;

    return 0;

}
