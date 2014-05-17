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

const int mod = 1000000007;

string s;
int n;
int dp[1000005][2][2]; //index, can put bomb, has put bomb

char all[] = {'*', '0', '1', '2'};

int solve(int i, int k, int t) {
    if (i==n && k==0) return 1;
    if (dp[i][k][t]>=0) return dp[i][k][t];

    int tmp = 0;

    if (s[i]=='?') {
        if (k==1) {
            tmp = (tmp + solve(i+1, 0, 1))%mod;
            tmp = (tmp + solve(i+1, 1, 1))%mod;
        }
        else {
            if (t==0) {
                tmp = (tmp + solve(i+1, 0, 0))%mod; //0
                tmp = (tmp + solve(i+1, 1, 0))%mod; //1
            }
            else {
                tmp = (tmp + solve(i+1, 0, 0))%mod; //1
                tmp = (tmp + solve(i+1, 1, 0))%mod; //2
            }
        }
    }
    else if (s[i]=='*') {
        if (k==1) {
            tmp = (tmp + solve(i+1, 0, 1))%mod;
            tmp = (tmp + solve(i+1, 1, 1))%mod;
        }
    }
    else if (s[i]=='0' && k==0) {
        if (t==0) tmp = (tmp + solve(i+1, 0, 0))%mod;
    }
    else if (s[i]=='1' && k==0) {
        if (t==0) tmp = (tmp + solve(i+1, 1, 0))%mod;
        else tmp = (tmp + solve(i+1, 0, 0))%mod;
    }
    else if (s[i]=='2' && k==0) {
        if (t==1) tmp = (tmp + solve(i+1, 1, 0))%mod;
    }

    dp[i][k][t] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();
    for (int i=0; i<n; i++) for (int j=0; j<4; j++) {
        dp[i][j][0] = -1;
        dp[i][j][1] = -1;
    }

    int res = (solve(0, 1, 0) + solve(0, 0, 0))%mod;

    cout<<res<<endl;

    return 0;

}
