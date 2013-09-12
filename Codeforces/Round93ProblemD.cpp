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

#define MAX 1000000000000000000LL

int n;
long long f[100];
bool is[100];
int dp[100][2];
long long t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    f[0] = 1LL; f[1] = 1LL;
    int k = 0;
    for (int i=0; i<91; i++) {f[k+2] = f[k] + f[k+1]; k++;}
    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%I64d",&t);
        long long x = t;
        for (int j=0; j<100; j++) is[j] = 0;
        for (int j=k; j>0; j--) if (x>=f[j]) {is[j] = 1; x -= f[j];}
        dp[0][0] = 1;
        dp[0][1] = 0;
        int last = 0;
        for (int j=1; j<k; j++) {
            if (is[j]) {
                dp[j][0] = dp[last][0] + dp[last][1];
                dp[j][1] = dp[last][0]*((j-last-1)/2) + dp[last][1]*((j-last)/2);
                last = j;
            }
        }
        int res = dp[last][0] + dp[last][1];
        printf("%d\n",res);
    }

    return 0;

}
