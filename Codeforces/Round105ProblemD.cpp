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

int w,b;
double dp[1010][1010][2];

double solve(int a, int b, int k) {
    if (a==0) return 0.0;
    if (b==0) {
        if (k==0) return 1.0;
        else return 0.0;
    }
    if (dp[a][b][k]>=-0.5) return dp[a][b][k];

    double res = 0;

    if (k==0) {
        res = (double)a/(a+b)*1.0 + (double)b/(a+b)*solve(a,b-1,1);
    }
    else {
        res = (double)a/(a+b)*0.0 + (double)b/(a+b)*(double)a/(a+b-1)*solve(a-1,b-1,0);
        if (b!=1) res += (double)b/(a+b)*(double)(b-1)/(a+b-1)*solve(a,b-2,0);
    }

    dp[a][b][k] = res;
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>w>>b;
    for (int i=0; i<=w; i++) for (int j=0; j<=b; j++) for (int k=0; k<2; k++) dp[i][j][k] = -1;

    double ans = solve(w,b,0);

    printf("%.12lf\n", ans);

    return 0;

}
