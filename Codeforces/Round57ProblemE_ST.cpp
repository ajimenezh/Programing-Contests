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

#define fact 320
#define MAXN 400000

int n;
int a[100010];
int b[100010];
int c1[100010];
int c2[100010];

int val[MAXN];

long long get(int id, int l, int r, int lt, int rt) {
    if (rt<lt || lt>rt) return 0;
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) return val[id];

    int mi = (l+r)/2;
    return get(id,l,mi,lt,rt) + get(2*id+1,mi+1,r,lt,rt);
}

void update(int id, int l, int r, int i, int v) {
    if (l>i || r<i) return;
    if (l==r && l==i) {val[id] += v; return;}

    int mi = (l+r)/2;

    update(2*id,l,mi,i,v);
    update(2*id+1,mi+1,r,i,v);

    val[id] = val[2*id] + val[2*id+1];
}

int main() {

    scanf("%d",&n);
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) b[i] = a[i];
    sort(b,b+n);
    int k = 0;
    for (int i=1; i<n; i++) if (b[i]!=b[k]) b[k++] = b[i];

    for (int i=0; i<n; i++) {
        int l=0, r=k;
        while (l<r) {
            int mi = (l+r)/2;
            if (a[i]<b[mi]) r = mi;
            else l = mi+1;
        }
        a[i] = r+1;
    }

    int m;
    k++;
    for (m = 0; (1<<m) < k; m++);

    for (int i=0; i<MAXN; i++) val[i] = 0;

    for (int i=n-1; i>=0; i--) {
        c1[i] = get(1,1,k,1,a[i]-1);
        update(1,1,k,a[i],1);
    }

    for (int i=0; i<MAXN; i++) val[i] = 0;

    for (int i=0; i<n; i++) {
        c2[i] = get(1,1,k,a[i]+1,k);
        update(1,1,k,a[i],1);
        //for (int j=0; j<=m; j++) {
        //    for (int r=0; r<(1<<j); r++) cout<<val[(1<<j)+r]<<" "; cout<<endl;
        //}
    }

    long long res = 0;
    for (int i=0; i<n; i++) {
        res += c1[i]*c2[i];
    }

    cout<<res;


    return 0;
}
