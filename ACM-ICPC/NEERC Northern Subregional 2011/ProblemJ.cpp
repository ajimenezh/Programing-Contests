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
pair<int,int> v[2][100010];
int a[100010];
int w[100010];
int sum[100010];

void update(int x) {
    for(;x<=n;x+=x&-x) sum[x]++;
}

int get(int x) {
    int s = 0;
    for(;x>=1; x-=x&-x) s += sum[x];
    return s;
}

long long solve() {
    for (int i=0; i<=n; i++) sum[i] = 0;
    map<int,int> id;
    for (int i=0; i<n; i++) w[i] = a[i];
    sort(w,w+n);
    int cnt = 1;
    for (int i=0; i<n; i++) {
        if (i==0 || w[i]!=w[i-1]) id[w[i]] = cnt++;
    }
    for (int i=0; i<n; i++) a[i] = id[a[i]];

    long long ans = 0;

    for (int i=0; i<n; i++) {
        ans += get(a[i]);
        update(a[i]);
    }

    return (long long)n*(n-1)/2 - ans;
}

long long calc(int k) {
    for (int i=0; i<n; i++) a[i] = v[k][i].first;
    long long res = solve();
    for (int i=0; i<n; i++) a[i] = v[k][i].second;
    res += solve();
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[0][i] = make_pair(a,b);
        v[1][i] = make_pair(b,a);
    }
    sort(v[0],v[0]+n);
    sort(v[1],v[1]+n);

    long long ans = min(calc(0), calc(1));

    cout<<ans<<endl;

    return 0;

}
