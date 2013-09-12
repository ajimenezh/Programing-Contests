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
int a[100010], b[100010];
int posa[100010], posb[100010];
int c[100010];
set<int> s1,s2;
set<int> s1n,s2n;
int cnt[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&a[i]);
    for (int i=0; i<n; i++) scanf("%d",&b[i]);

    for (int i=0; i<n; i++) {
        posa[a[i]] = i;
        posb[b[i]] = i;
        cnt[i] = 0;
    }
    cnt[n] = 0;

    for (int i=1; i<=n; i++) {
        int r = abs(posa[i] - posb[i]);
        if (posb[i] < posa[i]) r = -r;
        s1.insert(r);
        s1n.insert(-r);
        cnt[r]++;

    }

    for (int i=0; i<n; i++) {
        int r1=n,r1n=n,r2=n,r2n=n;
        set<int>::iterator it;
        it = s1.lower_bound(-i);
        if (it!=s1.end()) r1 = *(it) + i;
        it = s1n.lower_bound(-i);
        if (it!=s1n.end()) r1n = *(it) + i;
        it = s2.lower_bound(i);
        if (it!=s2.end()) r2 = *(it)-i;
        it = s2n.lower_bound(-i);
        if (it!=s2n.end()) r2n = *(it)+i;

        c[i] = min(min(r1,r1n),min(r2,r2n));

        int r = abs(posa[b[n-1-i]] - (n-1-i));
        if ((n-1-i) < posa[b[n-1-i]]) r = -r;
        cnt[r]--;
        if (cnt[r]==0) {
            s1.erase(r);
            s1n.erase(-r);
        }
        s2.insert((n) - r);
        s2n.insert(-((n)-r));

        rep(it,s1) cout<<(*it)<<" "; cout<<endl;
        rep(it,s1n) cout<<(*it)<<" "; cout<<endl;
        rep(it,s2) cout<<(*it)<<" "; cout<<endl;
        rep(it,s2n) cout<<(*it)<<" "; cout<<endl;
    }

    for (int i=0; i<n; i++) {
        printf("%d\n",c[i]);
    }


    return 0;

}
