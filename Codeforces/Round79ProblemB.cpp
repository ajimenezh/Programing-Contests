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
#define MAXN 100100

int m;
long long n;
set<long long> s;
pair<long long, long long> v[MAXN];
vector<int> e[MAXN];
map<long long, int> ma;

long long dp[MAXN];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;

    for (int i=0; i<m; i++) {
        long long a,b;
        scanf("%I64d%I64d",&a,&b);
        v[i] = make_pair(a,b);
        s.insert(a);
        s.insert(b);
    }

    int k = 0;
    rep(it,s) ma[*it] = k++;

    if (s.find(n)==s.end() || s.find(0)==s.end()) {
        cout<<0;
        return 0;
    }

    n = ma[n];

    for (int i=0; i<m; i++) {
        e[ma[v[i].second]].push_back(ma[v[i].first]);
    }

    for (int i=0; i<=n; i++) dp[i] = 0;

    for (int i=n; i>=0; i--) {
        if (i==n) {
            for (int j=0; j<e[i].size(); j++) {
                dp[i]++;
                if (e[i][j]!=0) dp[e[i][j]-1]--;
            }
            //cout<<dp[i]<<endl;
        }
        else{
            dp[i] = (dp[i] + dp[i+1] + mod)%mod;
            long long t = dp[i]%mod;
            //cout<<dp[i]<<endl;
            for (int j=0; j<e[i].size(); j++) {
                dp[i] = (dp[i] + t)%mod;
                if (e[i][j]!=0) dp[e[i][j]-1] = (dp[e[i][j]-1] - t + mod)%mod;
            }
            //cout<<i<<" "<<dp[i]<<endl;
        }
    }


    printf("%I64d",dp[0]);

    return 0;

}
