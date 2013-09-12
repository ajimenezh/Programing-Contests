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

#define mod 1000000007LL

int n;
string s;
string t;
long long dp[100010][2][2];

long long solve(int i, int p, int q) {
    if (i==n) {
        if (p==1 && q==1) return 1;
        return 0;
    }
    if (dp[i][p][q]>=0) return dp[i][p][q];

    long long tmp = 0;
    if (s[i]!='?') {
        if (t[i]!='?') {
            if (s[i]>t[i]) tmp += solve(i+1,1,q);
            else if (s[i]<t[i]) tmp += solve(i+1,p,1);
            else tmp += solve(i+1,p,q);
        }
        else {
            tmp = (tmp + max(0,s[i]-'0')*solve(i+1,1,q))%mod;
            tmp = (tmp + max(0,9-(s[i]-'0'))*solve(i+1,p,1))%mod;
            tmp = (tmp + solve(i+1,p,q))%mod;
        }
    }
    else {
        if (t[i]!='?') {
            tmp = (tmp + max(0,t[i]-'0')*solve(i+1,p,1))%mod;
            tmp = (tmp + max(0,9-(t[i]-'0'))*solve(i+1,1,q))%mod;
            tmp = (tmp + solve(i+1,p,q))%mod;
        }
        else {
            tmp = (tmp + 10*solve(i+1,p,q))%mod;
            tmp = (tmp + 45*solve(i+1,1,q))%mod;
            tmp = (tmp + 45*solve(i+1,p,1))%mod;
        }
    }

    tmp %= mod;
    dp[i][p][q] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>s>>t;

    for (int i=0; i<n; i++) for (int j=0; j<2; j++)for (int k=0; k<2; k++) dp[i][j][k] = -1;
    long long res = solve(0,0,0);

    cout<<res<<endl;

    return 0;

}
