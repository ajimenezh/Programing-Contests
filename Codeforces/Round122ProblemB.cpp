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

int n, u, r;
int a[30], b[30], p[30], k[30];
long long res;
bool first;

void doit(int v[]) {
    long long tmp = 0;
    for (int i=0; i<n; i++) {
        tmp += v[i]*k[i];
    }
    res = max(res,tmp);
    if (first) {
        first = false;
        res = tmp;
    }
}

void dfs(int v[], int _u, bool can) {
    int next[30];
    if (_u%2==0) {
        doit(v);
    }
    if (_u==0) {
        return;
    }
    if (can) {
        for (int i=0; i<n; i++) {
            next[i] = v[i]^b[i];
        }
        dfs(next,_u-1,0);
    }

    for (int i=0; i<n; i++) {
        next[i] = v[p[i]]+r;
    }
    dfs(next,_u-1,1);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>u>>r;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) scanf("%d",&b[i]);
    for (int i=0; i<n; i++) scanf("%d",&k[i]);
    for (int i=0; i<n; i++) scanf("%d",&p[i]);
    for (int i=0; i<n; i++) p[i]--;

    first = 1;
    res = 0;
    dfs(a, u, 1);

    cout<<res;

    return 0;

}
