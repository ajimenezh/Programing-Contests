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
int v[200010];
int w[200010];
map<int,int> mp;

void update(int x) {
    for (;x<=200000; x+=x&-x) w[x]++;
}
int get(int x) {
    int sum = 0;
    for(;x>=1;x-=x&-x) sum += w[x];
    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        scanf("%d",&n);
        for (int i=0; i<n; i++) scanf("%d", v+i);
        for (int i=0; i<n; i++) w[i] = v[i];
        sort(w,w+n);
        int m = 0;
        mp.clear();
        for (int i=0; i<n; i++) {
            if (i==0 || w[i]!=w[i-1]) mp[w[i]] = ++m;
        }
        for (int i=0; i<n; i++) v[i] = mp[v[i]];
        for (int i=0; i<=n; i++) w[i] = 0;
        long long ans = 0;
        for (int i=0; i<n; i++) {
            ans += i - get(v[i]);
            update(v[i]);
        }
        cout<<ans<<"\n";
    }

    return 0;

}
