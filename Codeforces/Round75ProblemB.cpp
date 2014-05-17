#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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
int sum[100010];
int a[100010];
int v[100010];
map<int,int> id;
int ans[100010];

void add(int x, int p) {
    for(;x<=n;x+=x&-x) sum[x] = max(sum[x], p);
}
int get(int x) {
    int p = -1;
    for(;x>=1;x-=x&-x) p = max(sum[x], p);
    return p;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) v[i] = a[i];
    sort(v,v+n);
    int cnt = 1;
    for (int i=0; i<n; i++) if (i==0 || v[i]!=v[i-1]) id[v[i]] = cnt++;
    for (int i=0; i<n; i++) a[i] = id[a[i]];

    for (int i=0; i<=n; i++) sum[i] = -1;

    for (int i=n-1; i>=0; i--) {
        int k = get(a[i]-1);
        if (k==-1) ans[i] = -1;
        else ans[i] = k-i-1;
        add(a[i],i);
    }
    for (int i=0; i<n; i++) cout<<ans[i]<<" ";

    return 0;

}
