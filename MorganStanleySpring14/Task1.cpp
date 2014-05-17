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
long long a[60010];
map<long long,int> id;
long long v[60010];
long long to[60010];
int dp[60010];
long long w[60010];

void solve() {
    for (int i=0; i<n; i++) v[i] = a[i];
    sort(v,v+n);
    int cnt = 0;
    id.clear();
    for(int i=0; i<n; i++) if (i==0 || v[i]!=v[i-1]) {
        to[cnt] = v[i];
        id[v[i]] = cnt++;
    }
    for (int i=0; i<n; i++) a[i] = id[a[i]];
    for (int i=0; i<n; i++) dp[i] = 0;
    for (int i=0; i<n; i++) {
        if (a[i]!=0) dp[a[i]] = 1 + dp[a[i]-1];
        else dp[0]  = 1;
    }
    int k = 0;
    int p = -1;
    for (int i=0; i<n; i++) if (dp[a[i]]>k) {
        k = dp[a[i]];
        p = a[i];
    }
    printf("%d\n", n-k);
    int lo = p-k;
    k = 0;
    for (int i=0; i<n; i++) if (a[i]<=lo) w[k++] = to[a[i]];
    sort(w, w+k);
    reverse(w,w+k);
    for (int i=0; i<k; i++) printf("%dB\n",w[i]);
    k = 0;
    for (int i=0; i<n; i++) if (a[i]>p) w[k++] = to[a[i]];
    sort(w, w+k);
    for (int i=0; i<k; i++) printf("%dT\n",w[i]);
    }

int main() {

    freopen("C:\\Users\\Alex-User\\Downloads\\input19.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;
    while (cin>>s) {
        if (s==";") {
            solve();
            printf(";\n");
            n = 0;
        }
        else{
            a[n++] = atoll(s.c_str());
        }
    }
    solve();

    return 0;

}
