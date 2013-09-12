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

int memo[5010][5010];
int n,m;
char a[5010];
bool vis[5010];

int next(int x) {
    if (a[x]=='R') {
        for (int i=x; i<(x/m)*m+m; i++) {
            if (!vis[i] && a[i]!='.') return i;
        }
    }
    if (a[x]=='R') {
        for (int i=x; i>=(x/m)*m; i--) {
            if (!vis[i] && a[i]!='.') return i;
        }
    }
    if (a[x]=='U') {
        for (int i=x; i>=x%m; i-=m) {
            if (!vis[i] && a[i]!='.') return i;
        }
    }
    if (a[x]=='D') {
        for (int i=x; i<(n-1)*m+x%m; i+=m) {
            if (!vis[i] && a[i]!='.') return i;
        }
    }
    return -1;
}

int solve(int x, int ne) {
    if (ne = -1) return 0;
    if (memo[x][ne]!=-1) return memo[x][ne];

    int y = next(x);
    vis[y] = 1;
    return 1 + solve(y,next(y));

}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<s.length(); j++) a[i*n+j] = s[j];
    }

    for (int i=0; i<n*n; i++) for (int j=0; j<max(n,m); j++) memo[i][j] = -1;

    int m = 0;
    int k = 0;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
        for (int r=0; r<m*n; r++) vis[r] = 0;
        vis[i*n+j] = 1;
        int t = 1+solve(i*n+j,next(i*n+j));
        if (t>m) {
            m = t;
            k = 0;
        }
        if (t==m) k++;
    }

    cout<<m<<" "<<k<<endl;

    return 0;

}
