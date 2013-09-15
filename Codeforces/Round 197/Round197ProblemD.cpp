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
int a[1<<17];
int v[520000];

void build(int id, int l, int r, int t) {
    if (l==r) {
        v[id] = a[l-1];
        return;
    }
    int h = (l+r)>>1;
    build(2*id,l,h,1-t);
    build(2*id+1,h+1,r,1-t);
    if (t) {
        v[id] = v[2*id]^v[2*id+1];
    }
    else {
        v[id] = v[2*id]|v[2*id+1];
    }
}

void update(int id, int l, int r, int lt, int rt, int t) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        v[id] = a[l-1];
        return;
    }
    int h = (l+r)>>1;
    update(2*id,l,h,lt,rt,1-t);
    update(2*id+1,h+1,r,lt,rt,1-t);
    if (t) {
        v[id] = v[2*id]^v[2*id+1];
    }
    else {
        v[id] = v[2*id]|v[2*id+1];
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<(1<<n); i++) scanf("%d",a+i);
    int t = (n%2==0?1:0);
    n = (1<<n);

    build(1,1,n,t);

    for (int i=0; i<m; i++) {
        int p,b;
        scanf("%d%d",&p,&b);
        a[p-1] = b;
        update(1,1,n,p,p,t);
        cout<<v[1]<<endl;
    }

    return 0;

}
