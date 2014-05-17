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

double dp[2010][2010];
set<int> col, row;
int n,m;

double solve(int N, int M) {
    if (N>n || M>n) return 0.0;
    if (N==n && M==n) return 0.0;
    if (dp[N][M]>=-0.5) return dp[N][M];

    double p1 = solve(N, M+1) + 1.0;
    double p2 = solve(N+1, M) + 1.0;
    double p3 = solve(N+1, M+1) + 1.0;

    double p = N*(n-M)*p1 + (n-N)*M*p2 + (n-N)*(n-M)*p3;
    p = p / (n*n) + (double)N*M/(n*n);
    p = p / (1.0 - (double)N*M/(n*n));

    dp[N][M] = p;

    return p;

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d", &a,&b);
        row.insert(a);
        col.insert(b);
    }
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = -1.0;
    double p = solve(row.size(), col.size());

    printf("%.12f\n", p);

    return 0;

}
