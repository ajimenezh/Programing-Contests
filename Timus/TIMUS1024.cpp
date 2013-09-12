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
int v[1001];
int vis[1001];
int cnt = 0;
int t[1001];
long long gcd(long long a,long long b) {
    if (a<b) return gcd(b,a);
    return (b==0?a:gcd(b,a%b));
}
long long mcm(long long a, long long b) {
    return a*b/gcd(a,b);
}

void dfs(int i, int c) {
    vis[i] = c;
    if (vis[v[i]]==0) dfs(v[i],c);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>v[i];
        v[i]--;
    }
    for (int i=0; i<n; i++) if (vis[i] == 0) dfs(i,++cnt);
    for (int i=0; i<n; i++) t[vis[i]]++;
    long long res = 1;
    for (int i=1; i<=cnt; i++) res = mcm(res,t[i]);

    cout<<res<<endl;

    return 0;

}
