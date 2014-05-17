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

#define INF 10000000000LL

int t,r,c;
int s[501][501];
pair<long long,long long> dp[501][501];
bool vis[501][501];

pair<long long,long long> solve(int x, int y) {
    if (x<0 || y<0) return make_pair(-INF,-INF);
    if (x==0 && y == 0) return make_pair(s[x][y],s[x][y]);
    if (vis[x][y]) return dp[x][y];
    vis[x][y] = 1;
    pair<long long,long long> t1 = solve(x-1,y);
    pair<long long,long long> t2 = solve(x,y-1);
//    if (min(s[x][y]+t1.first,t1.second)>min(s[x][y]+t2.first,t2.second)) {
//        dp[x][y] = make_pair(s[x][y]+t1.first,min(s[x][y]+t1.first,t1.second));
//    }
//    else if (min(s[x][y]+t1.first,t1.second)<min(s[x][y]+t2.first,t2.second)) {
//        dp[x][y] = make_pair(s[x][y]+t2.first,min(s[x][y]+t2.first,t2.second));
//    }
//    else {
        if (s[x][y]+t2.first>s[x][y]+t1.first)
            dp[x][y] = make_pair(s[x][y]+t2.first,min(s[x][y]+t2.first,t2.second));
        else
           dp[x][y] = make_pair(s[x][y]+t1.first,min(s[x][y]+t1.first,t1.second));
//    }
    return dp[x][y];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>r>>c;
        for (int i=0; i<r; i++) for (int j=0; j<c; j++) scanf("%d",&s[i][j]);
        for (int i=0; i<r; i++) for (int j=0; j<c; j++) vis[i][j] = 0;
        long long f = solve(r-1,c-1).second;
        //cout<<t<<endl;
        if (f<=0) f = -f +1;
        else f = 0;
        printf("%I64d\n",f);
    }

    return 0;

}
