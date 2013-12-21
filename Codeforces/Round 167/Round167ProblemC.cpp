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
int a[100010];
long long v[260000];
bool flag[260000];
int m;

void build(int id, int l, int r) {
    if (l==r) {
        v[id] = a[l-1];
        return;
    }
    int h = (l+r)>>1;
    build(2*id,l,h);
    build(2*id+1,h+1,r);
    v[id] = max(v[2*id],v[2*id+1]);
}

void update(int id, int l, int r, int lt, int rt, long long val) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        v[id] = max(v[id],val);
        flag[id] = 1;
        return;
    }
    int h = (l+r)>>1;
    if (flag[id]) {
        flag[id] = 0;
        int h = (l+r)>>1;
        update(2*id,l,h,l,h,v[id]);
        update(2*id+1,h+1,r,l,h,v[id]);
    }
    update(2*id,l,h,lt,rt,val);
    update(2*id+1,h+1,r,lt,rt,val);
    v[id] = max(v[2*id],v[2*id+1]);
}

long long get(int id, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) return v[id];
    int h = (l+r)>>1;
    if (flag[id]) {
        int h = (l+r)>>1;
        update(2*id,l,h,l,h,v[id]);
        update(2*id+1,h+1,r,l,h,v[id]);
        flag[id] = 0;
    }
    long long ret = get(2*id,l,h,lt,rt);
    ret = max(ret, get(2*id+1,h+1,r,lt,rt));
    return ret;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    build(1,1,n);
    cin>>m;
    for (int i=0; i<m; i++) {
        int w,h;
        scanf("%d%d",&w,&h);
        long long ans = get(1,1,n,1,w);
        cout<<ans<<endl;
        update(1,1,n,1,w,ans+h);
    }

    return 0;

}
