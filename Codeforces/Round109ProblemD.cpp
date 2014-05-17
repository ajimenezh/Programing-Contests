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

#define MAXN 100010

int n,m;

int gcd(int a, int b)
{
    if (a<b) return gcd(b,a);
    if (a==0 && b==0) return 0;
    if (b==0) return a;
    return gcd(b,a%b);

}

struct ST{

    int val[MAXN];
    int rev[MAXN];
    void init(int id, int l, int r) {
        rev[id] = 0;
        if (l==r) {
            val[id] = 0;
            return;
        }

        int m = (l+r)/2;
        init(2*id,l,m);
        init(2*id+1,m+1,r);

        val[id] = gcd(val[2*id],val[2*id+1]);
        if (val[2*id]==0) val[id] = val[2*id+1];
        else if (val[2*id+1]==0) val[id] = val[2*id];

    }

    int get(int id, int l, int r) {
        if (!rev[id]) return val[id];
        else return val[id];
    }

    void push(int id, int l, int r) {
        if (!rev[id]) return;
        rev[2*id] ^= 1;
        rev[2*id+1] ^= 1;
        rev[id] = 0;
    }
    void pull(int id, int l, int r) {
        int m = (l+r)/2;
        int a = get(2*id,l,m);
        int b = get(2*id+1,m+1,r);
        val[id] = gcd(a,b);
        if (a==0) val[id] = b;
        else if (b==0) val[id] = a;
    }

    int query(int id, int tl, int tr, int l, int r) {
        if (r<tl || l>tr) return 0;
        if (l<=tl && r>=tr) return get(id,tl,tr);
        push(id,tl,tr);
        int m = (tl+tr)/2;
        int q1 = query(2*id,tl,m,l,r);
        int q2 = query(2*id+1,m+1,tr,l,r);
        pull(id,tl,tr);

        int g = gcd(q1,q2);
        if (q1==0) return q2;
        if (q2==0) return q1;
        return g;
    }

    void update(int id, int tl, int tr, int l, int r){
        if (r<tl || l>tr) return;
        if (l<=tl && r>=tr) {
            if (val[id]==0) val[id] = l;
            else val[id] = 0;
            return;
        }
        push(id,tl,tr);
        int m = (tl+tr)/2;
        update(2*id,tl,m,l,r);
        update(2*id+1,m+1,tr,l,r);
        pull(id,tl,tr);
    }

    int take(int id, int l, int r){
        if (val[id]==1) return 1;
        if (l==r) return val[id];
        int m = (l+r)/2;
        int a = take(2*id,l,m);
        if (a!=1 && a!=0) return a;
        a = take(2*id+1,m+1,r);
        return a;
    }
}tree;

bool on[MAXN];

int main() {

    cin>>n>>m;

    tree.init(1,1,n);
    memset(on,0,sizeof(on));

    int cnt = 0;

    fo(i,m)
    {
        char c;
        int a;
        scanf("%s%d",&c,&a);
        if (c=='+')
        {
            if (on[a-1]) cout<<"Alredy on"<<endl;
            else
            {
                cnt ++;
                on[a-1] = 1;
                tree.update(1,1,n,a,a);
                if (tree.query(1,1,n,1,n) == 1 || cnt == 1) cout<<"Success"<<endl;
                else
                {
                    cout<<"Conflict with "<<tree.take(1,1,n)<<endl;
                    tree.update(1,1,n,a,a);
                    on[a-1] = 0;
                    cnt--;
                }
            }
        }
        else
        {
            if (!on[a-1]) cout<<"Alredy off"<<endl;
            else
            {
                on[a-1] = 0;
                tree.update(1,1,n,a,a);
                cout<<"Success"<<endl;
                cnt--;
            }
        }
    }


	return 0;

}
