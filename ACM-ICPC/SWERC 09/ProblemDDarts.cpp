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

double dp[505][505][2];
int pts[20] = {20,1,18,4,13,6,10,15,2,17,3,19,7,16,8,11,14,9,12,5};

int n;
double dp2[101][101][2][101];

double solve2(int pa, int pb, int t, int iter) {
    if (pa<=0) return 1.0;
    if (pb<=0) return 0.0;
    if (pa>100) return 0.0;
    if (pb>100) return 1.0;
    if (iter==0) return 0.5;
    if (dp2[pa][pb][t][iter]>=-0.1) return dp2[pa][pb][t][iter];

    //cout<<pa<<" "<<pb<<" "<<t<<" "<<iter<<endl;

    double p = 0.0;
    if (t==0) {
        int k = 0;
        for (int j=1; j<=20; j++) {
            if (pa-j>=0) {
                p +=  (solve2(pa-j,pb,1,iter-1))/20.0;
            }
            else {
                p +=  (solve2(pa,pb,1,iter-1))/20.0;
            }
        }
    }
    else {
        int in = 0;
        int fn = 20;
        for (int j=0; j<20; j++) {
            double tmp = 0.0;
            int k = 0;
            if (pb-pts[j]>=0) tmp += (solve2(pa,pb-pts[j],0,iter-1))/3.0;
            else tmp += (solve2(pa,pb,0,iter-1))/3.0;
            if (pb-pts[(j+1)%20]>=0)tmp += (solve2(pa,pb-pts[(j+1)%20],0,iter-1))/3.0;
            else  tmp += (solve2(pa,pb,0,iter-1))/3.0;
            if (pb-pts[(j-1+20)%20]>=0)tmp += (solve2(pa,pb-pts[(j-1+20)%20],0,iter-1))/3.0;
            else tmp += (solve2(pa,pb,0,iter-1))/3.0;

            tmp = 1.0 - tmp;

            p = max(tmp, p);
        }
        p = 1.0 - p;
    }

    dp2[pa][pb][t][iter] = p;
    return p;

}

double solve(int pa, int pb, int t) {
    if (pb<=20 || pa<=20) return solve2(pa,pb,t,100);
    if (pb==0) return 0.0;
    if (pa==0) return 1.00;
    if (dp[pa][pb][t]>=-0.1) return dp[pa][pb][t];

    double p = 0.0;
    if (t==0) {
        for (int j=1; j<=20; j++) {
            p +=  (solve(pa-j,pb,1))/20.0;
        }
    }
    else {
        int in = 0;
        int fn = 20;
        for (int j=0; j<20; j++) {
            double tmp = 0.0;
            tmp += (solve(pa,pb-pts[j],0))/3.0;
            tmp += (solve(pa,pb-pts[(j+1)%20],0))/3.0;
            tmp += (solve(pa,pb-pts[(j-1+20)%20],0))/3.0;

            tmp = 1.0 - tmp;

            p = max(tmp, p);
        }
        p = 1.0 - p;
    }

    dp[pa][pb][t] = p;
    return p;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    n = 501;
    for (int i=0; i<=n; i++) {
        for (int j=0; j<=n; j++) {
            dp[i][j][0] = -1;
            dp[i][j][1] = -1;
        }
    }

    for (int i=0; i<=100; i++) {
        for (int j=0; j<=100; j++) {
            for (int k=0; k<=100; k++) {
                dp2[i][j][0][k] = -1;
                dp2[i][j][1][k] = -1;
            }
        }
    }


    while (cin>>n && n!=0) {
        printf("%.12lf %.12lf\n",solve(n,n,0),1.0-solve(n,n,1));
    }

    return 0;

}
