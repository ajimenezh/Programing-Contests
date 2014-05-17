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

int n;
int p[1010];
int dp[1010];
const int mod = 1000000007;

int solve(int k) {
    if (k==0) return 2;
    if (dp[k]>=0) return dp[k];

    int tmp = 2;

    for (int i=p[k]; i<k; i++) tmp = (tmp + solve(i))%mod;

    dp[k] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>p[i];
    for (int i=0; i<n; i++) p[i]--;

    for (int i=0; i<n; i++) dp[i] = -1;

    int res = 0;
    for (int i=0; i<n; i++) res = (res + solve(i))%mod;

    cout<<res<<endl;

    return 0;

}
