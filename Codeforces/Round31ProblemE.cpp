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
string s;
long long dp[18][18];
long long p[19];
pair<pair<int,int>,char> next[18][18];

long long solve(int a, int b) {
    if ((a+b)>=2*n) return 0;
    if (dp[a][b]>=0) return dp[a][b];

    long long t1;
    if (a<n) t1 = (s[a+b]-'0')*p[n-a-1] + solve(a+1,b);
    long long t2;
    if (b<n) t2 = (s[a+b]-'0')*p[n-b-1] + solve(a,b+1);

    if (t1>t2 && a<n && b<n) {
        next[a][b] = make_pair(make_pair(a+1,b),'H');
        dp[a][b] = t1;
    }
    else if (t1<=t2 && a<n && b<n) {
        next[a][b] = make_pair(make_pair(a,b+1),'M');
        dp[a][b] = t2;
    }
    else if (b==n) {
        next[a][b] = make_pair(make_pair(a+1,b),'H');
        dp[a][b] = t1;
    }
    else if (a==n) {
        next[a][b] = make_pair(make_pair(a,b+1),'M');
        dp[a][b] = t2;
    }

    return dp[a][b];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>s;
    for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) dp[i][j] = -1;
    p[0] = 1;
    for (int i=1; i<19; i++) p[i] = 10LL*p[i-1];

    //cout<<
    solve(0,0);

    int a = 0, b = 0;
    while (a+b<2*n) {
        cout<<next[a][b].second; int tmp = a;
        a = next[a][b].first.first;
        b = next[tmp][b].first.second;
        //cout<<a<<" "<<b<<endl;
    }

    return 0;

}
