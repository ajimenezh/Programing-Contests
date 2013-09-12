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

int m;
int v[55];
bool dp[10010];
bool vis[10010];

bool solve(int n) {//1 L , 0 W
    if (n==0) return 0;
    if (vis[n]) return dp[n];

    bool tmp = 0;
    for (int i=0; i<m; i++) if (v[i]<=n) tmp |= solve(n-v[i]);

    vis[n] = 1;
    dp[n] = 1-tmp;
    return 1-tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n>>m;
    for (int i=0; i<m; i++) cin>>v[i];

    int t = solve(n);

    cout<<1+t<<endl;

    return 0;

}
