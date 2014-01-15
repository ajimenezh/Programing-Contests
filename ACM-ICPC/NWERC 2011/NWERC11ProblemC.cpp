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

int t;
int n,m;
int to[100010];
int dp[210010];

void update(int a, int v) {
    for (int x = a; x<=(n+m+10); x += x & -x) dp[x] += v;
}
int get(int a) {
    int v = 0;
    for (int x = a; x>=1; x -= x & -x) v += dp[x];
    return v;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n>>m;
        for (int i=0; i<n+m+10; i++) dp[i] = 0;
        for (int i=0; i<n; i++) to[i] = 1 + m + i;
        for (int i=0; i<n; i++) update(1+m+i,1);

        for (int i=0; i<m; i++) {
            int k;
            scanf("%d",&k);
            cout<<get(to[k-1]-1)<<" ";
            update(to[k-1],-1);
            to[k-1] = m-i;
            update(to[k-1],1);
        }
        cout<<endl;
    }

    return 0;

}
