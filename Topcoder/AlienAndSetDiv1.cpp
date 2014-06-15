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

#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)


class AlienAndSetDiv1 {
	public:
	int getNumber(int N, int K) ;
};

int dp[102][51][1<<10];
int n,k;
int mod = 1000000007;

int solve(int i, int b, int a) {
    if (i==2*n && b==0 && a==0) return 1;
    if (i==2*n) return 0;
    if (dp[i][b][a]>=0) return dp[i][b][a];

    int tmp = 0;

    int next = a>>1;
    b = b + (a&1);

    if (b>0) tmp = (tmp + solve(i+1, b-1, next))%mod;
    if (i+b<2*n) {
        tmp = (tmp + solve(i+1, b, next | (1<<(k-1))))%mod;
        if (b==0 && a==0) tmp = (tmp + solve(i+1, b, next | (1<<(k-1))))%mod;
    }

    //cout<<i<<" "<<b<<" "<<a<<" "<<tmp<<endl;

    dp[i][b][a] = tmp;

    return tmp;
}

int AlienAndSetDiv1::getNumber(int N, int K) {
	n = N; k = K;

	for (int i=0; i<2*n; i++) for (int j=0; j<=n; j++) for (int t=0; t<=(1<<k); t++) dp[i][j][t] = -1;

    return solve(0, 0, 0);

};

