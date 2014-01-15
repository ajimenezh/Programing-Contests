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

int n,m;
int v[100010];
map<int,int> cnt;
int k;
int w[1000];
int bit[100010];
pair<int,int> intv[100010];
int ans[100010];

void update(int x) {
    for (;x<=n; x+=x&-x) bit[x]++;
}
int get(int x) {
    if (!x) return 0;
    int sum = 0;
    for (;x>=1; x-=x&-x) sum += bit[x];
    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d",v+i);
    for (int i=0; i<n; i++) cnt[v[i]]++;
    rep(it, cnt) {
        if ((*it).second>=(*it).first) w[k++] = (*it).first;
    }
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        intv[i] = make_pair(a,b);
    }

    for (int i=0; i<k; i++) {
        for (int j=0; j<=n; j++) bit[j] = 0;
        for (int j=0; j<n; j++) if (v[j]==w[i]) update(j+1);
        for (int j=0; j<m; j++) {
            int tmp = get(intv[j].second) - get(intv[j].first-1);
            if (tmp==w[i]) ans[j]++;
        }
    }

    for (int i=0; i<m; i++) printf("%d\n", ans[i]);

    return 0;

}
