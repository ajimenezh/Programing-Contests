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

#define MAXN 1000010

int tree[4*MAXN];

void update(int id, int l, int r, int ll, int rr, int val) {
    if (l>rr || r<ll) return;
    if (l>=ll && r<=rr) {
        tree[id] = val;
        return;
    }

    int h = (l+r)/2;

    update(2*id,l,h,ll,rr,val);
    update(2*id+1,h+1,r,ll,rr,val);

    tree[id] = max(tree[2*id],tree[2*id+1]);
}

int get(int id, int l, int r, int ll, int rr) {
    if (l>rr || r<ll || ll>rr) return -1;
    if (l>=ll && r<=rr) {
        return tree[id];
    }
    int h = (l+r)/2;
    return max(get(2*id,l,h,ll,rr),get(2*id+1,h+1,r,ll,rr));
}

int t;
int n; int m;
int v[MAXN];
int w[MAXN];
int l[MAXN];
int r[MAXN];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        scanf("%d%d",&n,&m);
        for (int i=0; i<n; i++) scanf("%d",v+i);
        for (int i=0; i<=4*n; i++) tree[i] = -1;
        for (int i=0; i<n; i++) {
            if (i!=0 && v[i]==v[i-1]) {
                w[i] = w[i-1] + 1;
            }
            else {
                w[i] = 1;
            }
        }
        for (int i=0; i<n; i++) update(1,1,n,i+1,i+1,w[i]);
        l[0] = 0;
        for (int i=1; i<n; i++) {
            if (v[i]==v[i-1]) {
                l[i] = l[i-1];
            }
            else l[i] = i;
        }
        r[n-1] = n-1;
        for (int i=n-2; i>=0; i--) {
            if (v[i]==v[i+1]) {
                r[i] = r[i+1];
            }
            else r[i] = i;
        }

        printf("Test case #%d\n",tt+1);
        for (int i=0; i<m; i++) {
            int a,b;
            scanf("%d%d",&a,&b);
            a--; b--;
            int k = get(1,1,n,r[a]+2,l[b]);
            k = max(k,r[a]-a+1);
            k = max(k,b-l[b]+1);
            printf("%d\n",k);
        }
    }

    return 0;

}
