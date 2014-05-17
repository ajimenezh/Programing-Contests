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

#define mod 10007

int t,n;
vector<int> e[100011];
int par[100011];
pair<int,int> dp[100011][2];
bool leaf[100011];

void dfs(int p, int q) {
    par[p] = q;
    bool done = 0;
    rep(it,e[p]) {
        if (*it==q) continue;
        dfs(*it,p);
        done = 1;
    }
    if (!done) leaf[p] = 1;
}

pair<int,int> solve(int p, int on) {
    if (leaf[p]) return make_pair(1-on,1);
    if (dp[p][on].first>=0) return dp[p][on];

    int tmp = 1000000;
    int c = 1;

    if (on) {
        int t = 1;
        long long k = 1;
        rep(it,e[p]) if (*it!=par[p]) {
            t += solve(*it,1).first;
            k = (k * solve(*it,1).second)%mod;
        }
        tmp = min(tmp,t);
        c = k;
        t = 0;
        k = 1;
        rep(it,e[p]) if (*it!=par[p]) {
            t += solve(*it,0).first;
            k = (k * solve(*it,0).second)%mod;
        }
        if (tmp==t) {
            c = c + k;
            c %= mod;
        }
        else if (t<tmp) {
            tmp = t;
            c = k;
        }
    }
    else {
        int t = 1;
        long long k = 1;
        rep(it,e[p]) if (*it!=par[p]) {
            t += solve(*it,1).first;
            k = (k * solve(*it,1).second)%mod;
        }
        tmp = min(tmp,t);
        c = k;
    }

    c %= mod;

    dp[p][on] = make_pair(tmp,c);

    //cout<<p<<" "<<on<<" "<<tmp<<" "<<c<<endl;

    return make_pair(tmp,c);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) leaf[i] = 0;
        for (int i=0; i<n-1; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            e[a].push_back(b);
            e[b].push_back(a);
        }
        dfs(0,-1);
        for (int i=0; i<n; i++) dp[i][0].first = -1;
        for (int i=0; i<n; i++) dp[i][1].first = -1;
        int m = solve(0,1).first;
        int w = solve(0,1).second;

        printf("%d %d\n",m,w);
    }

    return 0;

}
