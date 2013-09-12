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

string s;

bool vocal(char a) {
    if (a=='a' || a=='e') return true;
    if (a=='o' || a=='i' || a=='u') return true;
    if (a=='A' || a=='E') return true;
    if (a=='O' || a=='I' || a=='U') return true;
    return false;
}

int a[200010];
int tree[600010];
int m;

void build(int node) {
    if (node >= m) {
        tree[node] = a[node-m];
        return;
    }

    build(2*node);
    build(2*node+1);

    tree[node] = min(tree[2*node],tree[2*node+1]);

    return;

}

int query(int k, int node, int a) {
    if (node>=m) {
        if (node-m>a) return a+2;
        return tree[node] <= k ? node-m : a+2;
    }

    //cout<<k<<" "<<node<<" "<<tree[2*node]<<endl;
    if (tree[2*node] <= k) return query(k,2*node,a);
    return query(k,2*node+1,a);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    int n = s.length();


    for (int i=1; i<=n; i++) a[i] = vocal(s[i-1]) ? -1 : 2;

    a[0] = 0;
    for (int i=1; i<=n; i++) a[i] = a[i] + a[i-1];

    //for (int i=0; i<=n; i++) cout<<a[i]<<" "; cout<<endl;

    for (int i=0; (1<<i)<(n); i++) m = i;
    m = 1<<(m+1);

    for (int i=0; i<=m; i++) tree[i] = -10000000;

    build(1);

    int d = 0;

    for (int i=1; i<=n; i++) {
        //cout<<query(a[i],1,i)<<" "<<a[i]<<endl;

        d = max(d,i - query(a[i],1,i));
    }

    if (d<=0) {
        cout<<"No solution"<<endl;
        return 0;
    }

    int c,v;
    c = 0;
    v = 0;
    int res = 0;

    for (int i=0; i<d; i++) {
        c += !vocal(s[i]);
        v += vocal(s[i]);
    }

    if (v<=2*c) res++;

    for (int i=d; i<n; i++) {
        c += !vocal(s[i]);
        v += vocal(s[i]);

        c -= !vocal(s[i-d]);
        v -= vocal(s[i-d]);

        if (v<=2*c) res++;
    }

    cout<<d<<" "<<res<<endl;

    return 0;

}
