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

#define mod 1000000007

int a[11];
int n;
long long C[101][101];
long long F[101];

long long comb(int i, int j) {
    if (j>i) return 0LL;
    return C[i][j];
}

long long fast_pow(long long a, long long m) {
    if (m<0) return 0LL;
    if (m==0) return 1LL;
    if (m==1) return a;
    long long tmp = fast_pow(a,m/2)%mod;
    if (m%2==0) return (tmp*tmp)%mod;

    return (a*((tmp*tmp)%mod)%mod)%mod;
}

long long  invmod(long long a) {
    if (a==0 || a==1) return 1;
    return fast_pow(a,mod-2)%mod;
}

long long fact(int a) {
    return F[a];
}

long long dp[12][110];
int mem[12];
long long solve(int m, int left,int sum) {
    if (left<0) return 0;

    //cout<<m<<" "<<left<<" "<<sum<<endl;

    for (int i=0; i<=10; i++) for (int j=0; j<=left; j++) dp[i][j] = 0;
    mem[0] = 0;
    for (int j=0; j<=9; j++) mem[j+1] = a[j] + mem[j];

    dp[0][left] = 1;

    for (int j=1; j<=10; j++) {
        for (int k=0; k<=left; k++) {
            for (int p=a[j-1]; k+(p-a[j-1])<=left; p++) {
                if (m-mem[j-1]-k-(p-a[j-1])<0) continue;
                //cout<<p<<endl;
                dp[j][k] = (dp[j][k] + (dp[j-1][k+(p-a[j-1])]*comb(m-mem[j-1]-(left-(k+(p-a[j-1]))),p))%mod)%mod;
            }
            //cout<<j<<" "<<k<<" "<<dp[j][k]<<endl;
        }
    }

    return dp[10][0]%mod;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<10; i++) cin>>a[i];

    C[0][0] = 1;
    for (int i=0; i<=n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
        for (int j=1; j<i; j++) {
            C[i][j] = (C[i-1][j-1] + C[i-1][j])%mod;
        }
    }

    F[0] = 1;
    for (int i=1; i<=n; i++) F[i] = (F[i-1]*i)%mod;

    long long res = 0;
    long long c;

    int sum = 0;
    for (int i=0; i<n; i++) sum += a[i];

    for (int k=1; k<=n; k++) {
        for (int i=1; i<=9; i++) {

                c = 0;
                int sum = 0;
                if (a[i]>0) {
                    a[i]--;
                    for (int j=0; j<=9; j++) sum += a[j];
                    c = solve(k-1,k-sum-1,sum);
                    res = (res + c)%mod;
                    a[i]++;
                }
                else {
                    for (int j=0; j<=9; j++) sum += a[j];
                    c = solve(k-1,k-sum-1,sum);
                    res = (res + c)%mod;
                }

        }

    }

    printf("%I64d\n",res);

    return 0;

}
