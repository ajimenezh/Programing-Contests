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

int x[6],y[6];
int dp[1<<6];

const double eps = 1.0e-6;

int solve(int mask) {
    if (__builtin_popcount(mask)<2) return 1;
    if (dp[mask]>=0) return dp[mask];

    int res = __builtin_popcount(mask);

    for (int i=0; i<5; i++) if ((1<<i)&mask) {
        for (int j=i+1; j<5; j++) if ((1<<j)&mask) {
            if (x[i]==x[j]) continue;

            double t = sqrt(0.5*9.81*(x[j]-x[i])/(x[j]*y[i]-x[i]*y[j]));

            if (abs(y[i] - 0.5*9.81*t*t)<eps) continue;

            double alp = atan(x[i] / (y[i] - 0.5*9.81*t*t));

            if (abs(sin(alp))<eps) continue;

            double v = x[i] / t / sin(alp);

            int tmp = mask;

            for (int k=0; k<5; k++) if ((1<<k)&mask) {

                cout<<i<<" "<<j<<" "<<k<<" "<<y[k] - v*cos(alp)*t+0.5*9.81*t*t<<" "<<x[k] - v*sin(alp)*t<<endl;

                if (abs(y[k] - v*cos(alp)*t - 0.5*9.81*t*t)<eps && abs(x[k] - v*sin(alp)*t)<eps ) tmp -= (1<<k);

            }

            if (tmp!=mask) res = min(res, 1 + solve(tmp));

        }
    }

    int tmp = mask;

    for (int k=0; k<5; k++) if ((1<<k)&mask) {

        if (x[k]==0) tmp -= (1<<k);

    }

    if (tmp!=mask) res = min(res, 1 + solve(tmp));

    tmp = mask;

    for (int k=0; k<5; k++) if ((1<<k)&mask) {

        if (y[k]==0) tmp -= (1<<k);

    }

    if (tmp!=mask) res = min(res, 1 + solve(tmp));

    for (int k=0; k<5; k++) if ((1<<k)&mask) {

        if (tmp!=mask) res = min(res, 1 + solve(mask-(1<<k)));

    }

    dp[mask] = res;

    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=0; i<5; i++) cin>>x[i]>>y[i];
    for (int i=0; i<(1<<5); i++) dp[i] = -1;

    cout<<solve((1<<5)-1);

    return 0;

}
