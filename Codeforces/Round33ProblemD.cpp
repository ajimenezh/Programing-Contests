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

int n,m,k;
pair<int,int> kn[1010];
pair<int,pair<int,int> > p[1010];
vector<int> e[1001];
int r[1010];
int d[1010];
int dp[1010][11];
int par[1010];

long long sqr(long long a) {return a*a;}

bool inside(int i, int j) {
    long long x = sqr((long long)p[i].second.first - (long long)p[j].second.first);
    long long y = sqr((long long)p[i].second.second - (long long)p[j].second.second);

    if (x+y<p[j].first) return true;
    return false;
}

void dfs(int p, int q) {
    d[p] = 1 + d[q];
    par[p] = q;
    rep(it,e[p]) if (*it!=q) {
        dfs(*it,p);
    }
}

int lcm(int a, int b) {
    if (d[b]<d[a]) return lcm(a,b);

    for (int i=10; i>=0; i--) {
        if (d[a] - (1<<i) >= d[b]) {
            a = dp[a][i];
        }
    }
    if (a==b) return a;
    for (int i=10; i>=0; i--) {
        if (dp[a][i]!=-1 && dp[a][i]!=dp[b][i]) {
            a = dp[a][i]; b = dp[b][i];
        }
    }
    return par[a];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) {
        scanf("%d%d",&kn[i].first,&kn[i].second);
    }
    for (int i=0; i<m; i++) {
        scanf("%d%d%d",&p[i].first, &p[i].second.first,&p[i].second.second);
    }
    sort(p,p+m);
    reverse(p,p+m);

    for (int i=0; i<m; i++) {
        for (int j=0; j<i; j++) {
            if (inside(j,i)) {
                e[j+1].push_back(i+1);
                e[i+1].push_back(j+1);
            }
        }
    }
    for (int i=0; i<n; i++) {
        r[i] = 0;
        for (int j=m-1; j>=0; j--) {
            long long x = sqr((long long)kn[i].first - (long long)p[j].second.first);
            long long y = sqr((long long)kn[i].second - (long long)p[j].second.second);

            if (x+y<p[j].first) {
                r[i] = j+1;
                break;
            }
        }
    }

    for (int i=0; i<m; i++) if (e[i+1].size()==0) e[0].push_back(i+1);
    m++;
    dfs(0,0);
    par[0] = -1;
    for (int i=0; i<m; i++) dp[i][0] = par[i];
    for (int j=1; j<11; j++) {
        for (int i=0; i<m; i++) {
            dp[i][j] = dp[dp[i][j-1]][j-1];
        }
    }
    for (int kk=0; kk<k; kk++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        int l = lcm(a,b);
        if (l==a || l==b) {
            printf("%d\n",max(d[a],d[b]) - min(d[a],d[b]));
        }
        else {
            printf("%d\n",d[a]-d[l] + d[b]-d[l]);
        }
    }

    return 0;

}
