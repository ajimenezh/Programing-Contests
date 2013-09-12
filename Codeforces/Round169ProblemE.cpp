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

int n,q;
vector<int> e[100010];
int de[100010];
int tr[100010];
struct SegmentTree {
    vector<int> val;
    int m;
    void init(int _n) {
        m = _n;
        val = vector<int> (4*m+10,0);
    }
    int get(int id, int l, int r, int lt, int rt) {
        if (l>rt || r<lt) return 0;
        int s = 0;
        if (l<=lt && r>=rt) {
            s += val[id];
            //cout<<l<<" "<<r<<" "<<s<<endl;
            if (l==r) return s;
        }

        int h = (l+r)/2;
        s += get(2*id,l,h,lt,rt);
        s += get(2*id+1,h+1,r,lt,rt);
        return s;
    }
    void update(int id, int l, int r, int lt ,int rt, int x) {
        if (l>rt || r<lt) return;
        if (l>=lt && r<=rt) {
            val[id] += x;
            return;
        }
        int h = (l+r)/2;
        update(2*id,l,h,lt,rt,x);
        update(2*id+1,h+1,r,lt,rt,x);
    }
    void print() {
        for (int i=0; (1<<i)<=m; i++) {
            for (int j=0; j<(1<<i); j++) {
                cout<<val[(1<<i)+j]<<" ";
            }
            cout<<endl;
        }
    }
}st[100010];

int dfs(int p, int q, int t) {
    tr[p] = t;
    de[p] = 1+de[q];
    int c = 1;
    rep(it,e[p]) if (*it!=q) {
        c = c + dfs(*it,p,t);
    }
    return c;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>q;
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }
    int k = 0;
    de[0] = 0;
    rep(it,e[0]) {
        int t = dfs(*it,0,k++);
        st[k-1].init(t);
    }
    st[k].init(n);

    int vroot = 0;
    for (int i=0; i<q; i++) {
        int type;
        scanf("%d",&type);
        if (type==0) {
            int v,x,d;
            scanf("%d%d%d",&v,&x,&d);
            v--;
            if (v==0) {
                st[k].update(1,1,st[k].m,1,min(st[k].m,d),x);
                vroot += x;
            }
            else {
                if (d>de[v]) st[k].update(1,1,st[k].m,1,min(st[k].m,d-de[v]),x);
                if (d>=de[v]) vroot += x;
                st[tr[v]].update(1,1,st[tr[v]].m,max(1,de[v]-d),min(d+de[v],st[tr[v]].m),x);
                if (d>de[v]) st[tr[v]].update(1,1,st[tr[v]].m,1,min(d-de[v],st[tr[v]].m),-x);
            }
        }
        else {
            int v;
            scanf("%d",&v);
            v--;
            if (v==0) printf("%d\n",vroot);
            else {
                int c = st[tr[v]].get(1,1,st[tr[v]].m,de[v],de[v]);
                c += st[k].get(1,1,st[k].m,de[v],de[v]);
                printf("%d\n",c);
                //cout<<tr[v]<<" "<<st[tr[v]].m<<endl;
                //st[tr[v]].print();
            }
        }
    }

    return 0;

}
