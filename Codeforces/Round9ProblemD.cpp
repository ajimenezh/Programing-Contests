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

long long dp[35][35][75][2];
int n,h;

long long solve(int a, int b, int c, bool r) {
    if (a>b || b<0 || a>=n) return 1LL;
    if (a==b && !r && c>n+1) return 1LL;
    if (a==b && !r && c<=n+1) return 0LL;
    if (a==b && c>n+1 && r) return 0LL;
    if (a==b && c<=n+1 && r) return 1LL;
    if (dp[a][b][c][r]!=-1) return dp[a][b][c][r];

    long long tmp = 0;


    for (int i=a; i<=b; i++) {
        if (r) {
            if (i-1>=a && i+1<=b) {
                tmp += solve(a,i-1,c-1,1)*solve(i+1,b,c-1,0);
                tmp += solve(a,i-1,c-1,0)*solve(i+1,b,c-1,1);
                tmp += solve(a,i-1,c-1,1)*solve(i+1,b,c-1,1);
            }
            else if (i-1<a && i+1<=b) {
                tmp += solve(i+1,b,c-1,1);
            }
            else if (i-1>=a && i+1>b) {
                tmp += solve(a,i-1,c-1,1);
            }
        }
        if (!r) {
            tmp += solve(a,i-1,c-1,0)*solve(i+1,b,c-1,0);
        }
    }

    dp[a][b][c][r] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>h;

    long long res = 0;

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) for (int k=0; k<=(h+n); k++) for (int p=0; p<2; p++) dp[i][j][k][p] = -1;

    for (int i=0; i<n; i++) {
            if (i-1>=0 && i+1<n) {
                res += solve(0,i-1,h+n-1,1)*solve(i+1,n-1,h+n-1,0);
                res += solve(0,i-1,h+n-1,0)*solve(i+1,n-1,h+n-1,1);
                res += solve(0,i-1,h+n-1,1)*solve(i+1,n-1,h+n-1,1);
            }
            else if (i-1<0 && i+1<n) {
                res += solve(i+1,n-1,h+n-1,1);
            }
            else if (i-1>=0 && i+1>=n) {
                res += solve(0,i-1,h+n-1,1);
            }
            else
                res += 1;
    }

    cout<<res<<endl;

    return 0;

}
