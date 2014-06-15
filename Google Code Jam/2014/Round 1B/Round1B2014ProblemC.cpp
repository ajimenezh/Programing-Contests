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

int n,m;
string s[51];
int a[51][51];
bool vis[51];

int dp[1<<8][1<<8][8];
int next[1<<8][1<<8][8];

pair<string,int> w[51];
int p[55];

int solve(int m1, int m2, int cur) {
    if (m1==(1<<n)-1) return 1;
    if (dp[m1][m2][cur]>=0) return dp[m1][m2][cur];

    int t = 0;

    for (int i=0; i<n; i++) if (((1<<p[i])&m1)==0) {
        for (int j=0; j<n; j++) if (m2&(1<<j)) {
            if (a[p[i]][j]) {
                int tmp = solve(m1 | (1<<p[i]), m2 | (1<<p[i]), p[i]);
                if (tmp==1) {
                    next[m1][m2][cur] = p[i];
                    t = 1;
                    break;
                }
            }
        }
    }

    if (t==1) {
        dp[m1][m2][cur] = 1;
        return 1;
    }


}

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cin>>n>>m;
        for (int i=0; i<n; i++) cin>>s[i];
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) a[i][j] = 0;
        }
        for (int i=0; i<m; i++) {
            int x,y;
            cin>>x>>y;
            a[x-1][y-1] = 1;
            a[y-1][x-1] = 1;
        }


        for (int i=0; i<n; i++) {
            w[i] = make_pair(s[i], i);
        }
        sort(w, w+n);
        for (int i=0; i<n; i++) p[i] = w[i].second;

        for (int j=0; j<(1<<n); j++) {
            for (int k=0; k<(1<n); k++) {
                for (int r=0; r<n; r++) dp[j][k][r] = -1;
            }
        }

        for (int i=0; i<n; i++) {
            int t = solve(1<<p[i], 1<<p[i], p[i]);

        }

        printf("Case #%d: %s\n", tt, best.c_str());
    }

    return 0;

}
