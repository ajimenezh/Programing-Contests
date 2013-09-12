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
char v[501][501];
int dp[501][26][26];
int c[501][26][26];
pair<int,pair<int,int> > next[501][26][26];
pair<int,pair<int,int> > pre[501][26][26];

int cost(int i, int a, int b) {
    if (a==b) return 3000000;
    if (c[i][a][b]>=0) return c[i][a][b];
    int t = 0;
    for (int j=0; j<m; j+=2) {
        if (v[i][j]-'a'!=a) t++;
        if (j+1<m && v[i][j+1]-'a'!=b) t++;
    }
    c[i][a][b] = t;
    return c[i][a][b];
}


int solve(int i, int a, int b) {
    if (a>25 || b>25) return 3000000;
    if (i==n) return 0;
    if (dp[i][a][b]>=0) return dp[i][a][b];

    int best = 300000;
    pair<int,pair<int,int> > tmp;
    pre[i+1][0][1] = make_pair(i,make_pair(a,b));
    if (solve(i+1,0,1)+cost(i,a,b)<best) {
        best = dp[i+1][0][1]+c[i][a][b];
        tmp = make_pair(i+1,make_pair(0,1));
        pre[i+1][0][1] = make_pair(i,make_pair(a,b));
    }
    pre[i+1][1][0] = make_pair(i,make_pair(a,b));
    if (solve(i+1,1,0)+cost(i,a,b)<best) {
        best = dp[i+1][1][0]+c[i][a][b];
        tmp = make_pair(i+1,make_pair(1,0));
        pre[i+1][1][0] = make_pair(i,make_pair(a,b));
    }
    for (int j=0; j<2; j++) for (int k=0; k<2; k++) if (j!=0 || k!=0) {
        if (a+j==pre[i][a][b].second.first || b+k==pre[i][a][b].second.second) continue;
        pre[i][a+j][b+k] = pre[i][a][b];
        int t = solve(i,a+j,b+k);
        if (t<best) {
            best = dp[i][a+j][b+k];
            tmp = make_pair(i,make_pair(a+j,b+k));
            pre[i][a+j][b+k] = pre[i][a][b];
        }
    }

    dp[i][a][b] = best;
    next[i][a][b] = tmp;

    return best;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    char f[2]; gets(f);
    for (int i=0; i<n; i++) gets(v[i]);
    for (int i=0; i<n; i++) for (int j=0; j<26; j++) for (int k=0; k<26; k++) dp[i][j][k] = -1;
    for (int i=0; i<n; i++) for (int j=0; j<26; j++) for (int k=0; k<26; k++) c[i][j][k] = -1;
    pre[0][0][0] = make_pair(0,make_pair(-1,-1));
    cout<<solve(0,0,0)<<endl;
    pair<int,pair<int,int> > p = make_pair(0,make_pair(0,0));
    pair<int,int> sol = make_pair(0,0);
    for (int i=0; i<n; i++) {
        while (next[p.first][p.second.first][p.second.second].first==p.first) {
            p = next[p.first][p.second.first][p.second.second];
        }
        sol = p.second;
        for (int j=0; j<m; j+=2) {
            printf("%c",char('a'+sol.first));
            if (j+1<m) printf("%c",char('a'+sol.second));
        }
        cout<<"\n";
        p = next[p.first][p.second.first][p.second.second];
    }

    return 0;

}
