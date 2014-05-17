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

int a[1000010];
long long sum[1000010];
int n;
long long h[21];
long long r[21];

long long get(int x) {
    long long tot = 0;
    for (;x<=(1<<n);x+=x&-x) tot += sum[x];
    return tot;
}

void update(int x, int v) {
    for(;x>0;x-=x&-x) sum[x]+=v;
}

long long solve(int k) {
    int p = 1<<k;
    long long tot = 0;
    for (int i=0; i<(1<<n); i++) sum[i+1] = 0;
    for (int i=0; i<(1<<n); i+=(1<<k)) {
        r[k] += (long long)p*(p-1)/2;
        for (int j=i; j<i+(1<<k); j++) {
            tot += get(a[j]+1);
            update(a[j], 1);
        }
        for (int j=i; j<i+(1<<k); j++) update(a[j], -1);
    }
    h[k] = tot;
    r[k] = r[k] - tot;
    return h[k];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<(1<<n); i++) scanf("%d", a+i);
    for (int i=1; i<=n; i++) {
        solve(i);
        //cout<<h[i]<<" "<<r[i]<<endl;
    }

    long long cur = h[n];

    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int p;
        scanf("%d", &p);
        if (p==0) {
            printf("%I64d\n", cur);
        }
        else {
            cur -= h[p] - r[p];
            printf("%I64d\n", cur);
            long long last = h[p];
            swap(h[p], r[p]);
            for (int j=p+1; j<=n; j++) {
                h[j] -= h[p];
                r[j] += last;
            }
        }
    }

    return 0;

}
