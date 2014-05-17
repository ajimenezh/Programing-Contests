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

int n,m;
int k;
const int mod = 1000000007;
int a[8][8];
int dp[8][8][2];

int rec(int x, int y, int f) {
    if (x==n) return 1;
    if (y==m) return rec(x+1,0,0);
    if (dp[x][y][f]>=0) return dp[x][y][f];

    long long tmp = 0;

    if (x==0) {
        if (y==0) tmp = k*rec(x,y+1,0);
        else tmp = (k-1)*rec(x,y+1,0);
    }
    else {
        if (y==0) {
            tmp = rec(x,y+1,1) + (k-2)*rec(x,y+1,0);
        }
        else {
            if (y==m-1) {
                if (f) tmp = (k-1)*rec(x,y+1,0);
                else tmp = (k-2)*rec(x,y+1,0);
            }
            else { cout<<"hola"<<endl;
                if (f) tmp = (k-2)*rec(x,y+1,0) + rec(x,y+1,1);
                else tmp = (k-3)*rec(x,y+1,0) + rec(x,y+1,1);
            }
        }
    }
    dp[x][y][f] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        scanf("%d%d%d",&n,&m,&k);
        if (n>m) swap(n,m);
        long long ans = 0;
        if (n==1) {
            ans = k;
            for (int i=1; i<m; i++) ans = ans*(k-1)%mod;
        }
        if (n==2) {
            ans = (long long)(k-1)*k%mod;
            for (int i=1; i<m; i++) {
                ans = ans*((long long)k*k%mod - 3*k + 3)%mod;
                ans = (ans+mod)%mod;
            }
        }
        if (n==3) {
            if (m==3) {
                long long q = k;
                ans = 0;
                ans = (ans + 79*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 323*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 594*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 648*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 459*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 216*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 66*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 12*q)%mod;
                q = (q*k)%mod;
                ans = (ans + q)%mod;
                ans = (ans+mod)%mod;
            }
            if (m==4) {
                long long q = k;
                ans = 0;
                ans = (ans - 691*q)%mod;
                q = (q*k)%mod;
                ans = (ans  + 3586*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 8706*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 13109*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 13605*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 10207*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 5642*q)%mod;
                q = (q*k)%mod;
                ans = (ans  + 2296*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 674*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 136*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 17*q)%mod;
                q = (q*k)%mod;
                ans = (ans + q)%mod;
                ans = (ans+mod)%mod;
            }
            if (m==5) {
                long long q = k;
                ans = 0;
                ans = (ans + 6041*q)%mod;
                q = (q*k)%mod;
                ans = (ans  - 38012*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 114174*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 217403*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 293138*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 295791*q)%mod;
                q = (q*k)%mod;
                ans = (ans  + 230070*q)%mod;
                q = (q*k)%mod;
                ans = (ans  - 139981*q)%mod;
                q = (q*k)%mod;
                ans = (ans + 66889*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 24966*q)%mod;
                q = (q*k)%mod;
                ans = (ans +7163*q)%mod;
                q = (q*k)%mod;
                ans = (ans -1532*q)%mod;
                q = (q*k)%mod;
                ans = (ans +231*q)%mod;
                q = (q*k)%mod;
                ans = (ans - 22*q)%mod;
                q = (q*k)%mod;
                ans = (ans + q)%mod;
                ans = (ans+mod)%mod;
            }
        }
        if (n==4) {
            if (m==4) {
                long long q = k;
                ans = 0;
                ans = (ans -17493*q)%mod;
                q = (q*k)%mod;
                ans = (ans  +112275*q)%mod;
                q = (q*k)%mod;
                ans = (ans -346274*q)%mod;
                q = (q*k)%mod;
                ans = (ans +682349*q)%mod;
                q = (q*k)%mod;
                ans = (ans -960627*q)%mod;
                q = (q*k)%mod;
                ans = (ans +1022204*q)%mod;
                q = (q*k)%mod;
                ans = (ans  -848056*q)%mod;
                q = (q*k)%mod;
                ans = (ans  +557782*q)%mod;
                q = (q*k)%mod;
                ans = (ans -292883*q)%mod;
                q = (q*k)%mod;
                ans = (ans +122662*q)%mod;
                q = (q*k)%mod;
                ans = (ans -40614*q)%mod;
                q = (q*k)%mod;
                ans = (ans +10437*q)%mod;
                q = (q*k)%mod;
                ans = (ans -2015*q)%mod;
                q = (q*k)%mod;
                ans = (ans +276*q)%mod;
                q = (q*k)%mod;
                ans = (ans -24*q)%mod;
                q = (q*k)%mod;
                ans = (ans + q)%mod;
                ans = (ans+mod)%mod;
            }
        }
        cout<<ans<<endl;
    }

    return 0;

}

