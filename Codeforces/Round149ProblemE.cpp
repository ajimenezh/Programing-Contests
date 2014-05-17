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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 520000

int n;
int b[MAXN],a[MAXN];

struct ST{

    int val[MAXN];
    int rev[MAXN];
    void init(int id, int l, int r, int *b) {
        rev[id] = 0;
        if (l==r) {
            val[id] = b[l];
            return;
        }

        int m = (l+r)/2;
        init(2*id,l,m,b);
        init(2*id+1,m+1,r,b);
        val[id] = val[2*id] + val[2*id+1];
    }

    int get(int id, int l, int r) {
        if (!rev[id]) return val[id];
        else return (r-l+1) - val[id];
    }

    void push(int id, int l, int r) {
        if (!rev[id]) return;
        rev[2*id] ^= 1;
        rev[2*id+1] ^= 1;
        rev[id] = 0;
    }
    void pull(int id, int l, int r) {
        int m = (l+r)/2;
        val[id] = get(2*id,l,m) + get(2*id+1,m+1,r);
    }

    int query(int id, int tl, int tr, int l, int r) {
        if (r<tl || l>tr) return 0;
        if (l<=tl && r>=tr) return get(id,tl,tr);
        push(id,tl,tr);
        int m = (tl+tr)/2;
        int q1 = query(2*id,tl,m,l,r);
        int q2 = query(2*id+1,m+1,tr,l,r);
        pull(id,tl,tr);
        return q1+q2;
    }

    void update(int id, int tl, int tr, int l, int r){
        if (r<tl || l>tr) return;
        if (l<=tl && r>=tr) {
            rev[id] ^= 1;
            return;
        }
        push(id,tl,tr);
        int m = (tl+tr)/2;
        update(2*id,tl,m,l,r);
        update(2*id+1
               ,m+1,tr,l,r);
        pull(id,tl,tr);
    }
}tree[22];


int main() {

    cin>>n;

    fo(j,n) b[j] = 0;
    fo(i,n) scanf("%d",&a[i]);

    for (int j=0; j<20; j++)
    {
        fo(i,n+1) b[i] = 0;
        for (int i=0; i<n; i++) if ((1<<j)&a[i]) b[i+1]++;
        tree[j].init(1,1,n,b);
    }

    int q;
    cin>>q;

    fo(qq,q)
    {
        int t,l,r;
        scanf("%d%d%d",&t,&l,&r);
        if (t==1)
        {
            long long sol = 0;
            for (int j=0; j<20; j++) {
                sol += (1LL<<j)*tree[j].query(1,1,n,l,r);
            }
            cout<<sol<<endl;
        }
        else
        {
            int y;
            scanf("%d",&y);
            for (int j=0; j<20; j++) if ((1<<j)&y) tree[j].update(1,1,n,l,r);
        }
    }

	return 0;

}
