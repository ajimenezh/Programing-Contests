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
long long k;
int a[100010];
map<int,int> m;
int v1[100010],v2[100010];
int f;
long long tot;
long long b[100010];
bool vis[100010];
long long res;

int ask(int* v,int c) {
    if (c==0) return 0;
    int s = 0;
    for (int i=c; i>0; i -= i & -i) s += v[i];
    return s;
}

int query(int* v,int c, int d) {
    if (c<d) return query(v,d,c);
    return ask(v,c) - ask(v,d-1);
}

void update(int* v,int c, int val) {
    for (int i=c; i<=f; i += i & -i) v[i] += val;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) m[a[i]] = 0;
    rep(it,m) (*it).second = ++f; f++;
    for (int i=0; i<n; i++) a[i] = m[a[i]];
    for (int i=0; i<n; i++) {
        update(v1,a[i],1);
        tot += query(v1,a[i]+1,f);
    }
    update(v1,a[n-1],-1);
    update(v2,a[n-1],1);
    for (int r=n-1,l=n-2;;) {
        while (l>=0 && tot>k) {
            tot -= query(v1,a[l]+1,f);
            tot -= ask(v2,a[l]-1);
            update(v1,a[l],-1);
            vis[l] = 1;
            l--;
        }//cout<<tot<<" "<<l<<endl;
        if (l<0) break;
        res += l + 1;
        if (vis[r-1]) {
            tot += query(v1,a[r-1]+1,f);
            tot += ask(v2,a[r-1]-1);
        }
        update(v2,a[r-1],1);
        r--; if (l==r) l--;
    }
    cout<<res;

    return 0;

}
