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

int n,a[100010];
pair<int,int> b[100010];
bool lucky(int c) {
    while (c>0) {
        if (c%10!=4 && c%10!=7) return false;
        c /= 10;
    }
    return true;
}
pair<int,int> v[200010];
map<pair<int,int>,int> ind;

void change(int c, int d) {
    int t = a[c];
    a[c] = a[d];
    a[d] = t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) b[i] = make_pair(a[i],i);
    sort(b,b+n);
    bool done = true;
    for (int i=0; i<n; i++) if (b[i]!=a[i]) done = false;
    if (done) {cout<<0<<endl; return 0;}
    int p = -1;
    for (int i=0; i<n; i++) if (lucky(a[i])) {p = i; break;}
    if (p==-1) {cout<<-1<<endl; return 0;}
    int k = 0;
    for (int i=0; i<n; i++) ind[make_pair(a[i],i)] = i;
    for (int i=0; i<n; i++) {
        if (p!=i) v[k++] = make_pair(p,i);
        ind[a[i]] = p;
        ind[a[p]] = i;
        change(i,p);
        if (i!=ind[b[i]]) v[k++] = make_pair(i,ind[b[i]]);
        int c = ind[b[i]];
        ind[a[i]] = ind[b[i]];
        ind[b[i]] = i;
        change(i,c);
        p = c;
    }
    cout<<k<<endl;
    for (int i=0; i<k; i++) printf("%d %d\n",v[i].first+1,v[i].second+1);

    return 0;

}
