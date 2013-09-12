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
#define read(x) scanf("%d",&x);
#define write(x) printf("%d ",x);

int n;
int a[100010];
int b[100010];
long long v[600010];
bool vis[600010];
long long sum[600010];

void update(int id, int l, int r, int lt, int rt, int x) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        v[id] += x;
        sum[id] += x;
        vis[id] = true;
        return;
    }

    int h = (l+r)/2;
    if (vis[id]) {
        vis[id] = false;
        x += sum[id];
        sum[id] = 0;
    }
    update(2*id,l,h,lt,rt,x);
    update(2*id+1,h+1,r,lt,rt,x);
    v[id] = min(v[2*id],v[2*id+1]);
    return;
}

long long query(int id, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return 0;
    if (l>=lt && r<=rt) {
        return v[id];
    }

    int h = (l+r)/2;
    long long x1 = query(2*id,l,h,lt,rt);
    long long x2 = query(2*id+1,h+1,r,lt,rt);
    long long x = min(x1,x2);
    return x;
}

void print() {
    cout<<endl;
    cout<<"Actual Segment Tree\n";
    cout<<endl;
    for (int i=0;(1<<i)<=2*n; i++) {
        for (int j=0; j<(1<<i); j++) {
            cout<<v[(1<<i)+j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    read(n)
    for (int i=0; i<n; i++) read(a[i])
    for (int i=0; i<n; i++) read(b[i])
    long long suma = 0, sumb = 0;
    for (int i=0; i<n; i++) {
        update(1,1,2*n,i+1,i+1,a[i]+suma-b[i]-sumb);
        suma += a[i];
        sumb += b[i];
    }
    set<int> c;
    for (int i=0; i<n; i++) {
        //print();
        //cout<<query(1,1,2*n,i+1,n+i)<<endl;
        if (query(1,1,2*n,i+1,n+i)>=0) {
            c.insert(i+1);
        }
        update(1,1,2*n,i+2,n+i,-a[i]+b[i]);
    }

    for (int i=0; i<600000; i++) v[i] = 0;
    for (int i=0; i<600000; i++) vis[i] = 0;
    for (int i=0; i<600000; i++) sum[i] = 0;
    suma = 0, sumb = 0;
    for (int i=0; i<n; i++) {
        update(1,1,2*n,2*n-i,2*n-i,a[n-1-i]+suma-b[(2*n-2-i)%n]-sumb);
        suma += a[n-1-i];
        sumb += b[(2*n-2-i)%n];
    }

    for (int i=0; i<n; i++) {
        //print();
        //cout<<query(1,1,2*n,n+1-i,2*n-i)<<endl;
        if (query(1,1,2*n,n+1-i,2*n-i)>=0) {
            c.insert(n-i);
        }
        update(1,1,2*n,n+1-i,2*n-i-1,-a[n-1-i]+b[(2*n-2-i)%n]);
    }

    cout<<c.size()<<endl;
    rep(it,c) write(*it)

    return 0;

}
