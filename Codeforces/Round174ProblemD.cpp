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
long long a[5001];
int dp[5001];
int p[5001];
long long odd[5001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i = 0; i<n; i++) dp[i] = -1;
    for (int i=0; i<n; i++) {
        long long x = a[i];
        int t = 0;
        while (x%2==0) {x>>=1LL; t++;}
        p[i] = t;
        //cout<<a[i]<<" "<<t<<endl;
    }
    for (int i=0; i<n; i++) {
        long long x = a[i];
        while (x%2==0 && x) x>>=1LL;
        odd[i] = x;
        //cout<<a[i]<<" "<<x<<endl;
    }
    int res = n;
    for (int i=0; i<n; i++) {
        dp[i] = 1;
        for (int j=0; j<i; j++) {
            //cout<<odd[i]<<" "<<odd[j]<<" "<<p[i]<<" "<<p[j]<<" "<<i-j-1<<endl;
            if (odd[j]%odd[i]==0 && (p[j]-p[i]==j-i || p[i]<=i-j-1)) {
                dp[i] = max(dp[i],dp[j] + 1);
            }
        }
        //cout<<i<<" "<<dp[i]<<endl;
        res = min(res,n-dp[i]);
    }

    cout<<res;


    return 0;

}
