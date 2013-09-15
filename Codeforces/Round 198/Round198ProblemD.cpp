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
int v[100010];
int sum[100010];
int bit[100010];

int get(int i) {
    int x = 0;
    for (;i>=1; i-=i&-i) x = max(x, bit[i]);
    return x;
}
void update (int i, int x) {
    for (;i<=n; i+=i&-i) bit[i] = max(bit[i],x);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",v+i);

    int ans = 0;
    for (int i=0; i<n; i++) {
        sum[i] = get(v[i]-1) + 1;
        update(v[i], sum[i]);
        ans = max(ans,sum[i]);
    }
    cout<<ans<<endl;

    return 0;

}
