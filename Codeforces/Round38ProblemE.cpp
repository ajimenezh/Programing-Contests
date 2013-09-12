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
pair<long long, long long> tmp[3001];
long long x[3001];
long long c[3001];

int pinned[3001];
int k;

long long partial[3001][3001];
long long dp[3001];

long long solve(int i) {
    if (i == n-1) return 0;
    if (dp[i]!=-1) return dp[i];

    long long tmp = partial[i][n-1];

    for (int j=i+1; j<n; j++) {
        tmp = min(tmp, partial[i][j-1] + c[j] + solve(j));
    }

    dp[i] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    k = 0;
    for (int i=0; i<n; i++) scanf("%I64d%I64d",&tmp[i].first,&tmp[i].second);
    sort(tmp, tmp+n);

    for (int i=0; i<n; i++) {x[i] = tmp[i].first; c[i] = tmp[i].second;}

    pinned[k++] = 0;
    int last = 0;

    for (int i=0; i<n; i++) {
        partial[i][i] = 0;
        for (int j=i+1; j<n; j++) {
            partial[i][j] = partial[i][j-1] + x[j]-x[i];
            //cout<<partial[i][j]<<endl;
            //cout<<x[j]<<" "<<x[i]<<endl;
        }
        //cout<<endl;
    }

    for (int i=0; i<n; i++) dp[i] = -1;

    dp[0] = solve(0);

    //for (int i=0; i<n; i++) cout<<dp[i]<<endl;


    cout<<dp[0]+c[0];

    return 0;

}
