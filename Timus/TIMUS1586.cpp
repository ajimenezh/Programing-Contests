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

#define mod 1000000009

int n;
long long dp[10001][10][10];
bool primes[1000];

bool prime(int i) {
    for (int j=2; j*j<=i; j++) if (i%j==0) return false;
    return true;
}

long long solve(int i, int d1, int d2) {
    if (i==n) return 1;
    if (dp[i][d1][d2]>=0) return dp[i][d1][d2];

    long long tmp = 0;
    for (int j=0; j<10; j++) {
        if (primes[100*d1+10*d2+j]) {
            tmp = (tmp + solve(i+1,d2,j))%mod;
        }
    }
    dp[i][d1][d2] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=100; i<=999; i++) if (prime(i)) primes[i] = 1;
    for (int i=0; i<n; i++) for (int j=0; j<10; j++) for (int k=0; k<10; k++) dp[i][j][k] = -1;
    long long t = 0;
    for (int i=1; i<10; i++) for (int j=0; j<10; j++) t = (t + solve(2,i,j))%mod;
    cout<<t<<endl;

    return 0;

}
