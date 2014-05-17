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
#define piii pair<pii,pii>

#define MAXN 2500000
#define MAXS 1000100

struct node
{
    int n4,n7,n47,n74;
    bool flag;
}tree[MAXN];

int n;

void update(int node, int v)
 {
    if (node==0) return;
    if (node>=n)
    {
        if (v==4) tree[node].n4 = 1;
        else tree[node].n4 = 0;

        if (v==7) tree[node].n7 = 1;
        else tree[node].n7 = 0;

        tree[node].n47 = 1;
        tree[node].n74 = 1;
    }
    else
    {
        tree[node].n4 = tree[2*node].n4 + tree[2*node+1].n4;
        tree[node].n7 = tree[2*node].n7 + tree[2*node+1].n7;

        tree[node].n47 = max(tree[2*node].n4 + tree[2*node+1].n47,tree[2*node].n47 + tree[2*node+1].n7);
        tree[node].n74 = max(tree[2*node].n7 + tree[2*node+1].n74,tree[2*node].n74 + tree[2*node+1].n4);
    }

    update(node/2, v);

    return;

}

void lazy_update(int node,int a, int b, int l, int r, bool upd=1)
 {
    if (b<l || a>r) return;

    if (a>=l && b<=r)
    {
        int t = tree[node].n4;
        tree[node].n4 = tree[node].n7;
        tree[node].n7 = t;
        t = tree[node].n47;
        tree[node].n47 = tree[node].n74;
        tree[node].n74 = t;
        tree[node].flag = !tree[node].flag;

        if (upd) update(node/2,0);

        return;
    }

    if (tree[node].flag && node<n)
    {
        lazy_update(2*node,a, a+(b-a)/2, a, a+(b-a)/2,0);
        lazy_update(2*node+1,a+(b-a)/2+1, b, a+(b-a)/2+1, b,0);
        tree[node].flag = false;

    }

    lazy_update(2*node, a, a+(b-a)/2, l, r);
    lazy_update(2*node+1, a+(b-a)/2+1, b, l, r);

}

void output(int node)
{
    cout<<node<<" "<<tree[node].n4<<" "<<tree[node].n7<<" "<<tree[node].n47<<" "<<tree[node].n74<<" "<<tree[node].flag<<endl;
    if (node<n) {output(node*2); output(node*2+1);}
    return;
}


int q;
char buf[MAXS];

int main() {

    scanf("%d%d",&n,&q);
    scanf("%s",buf);

    int k;
    for (k=1; (1<<k)<n; k++);

    int m = n;
    n = 1<<k;
    fo(i,m) update(n+i,buf[i]-'0');

    fo(i,q)
    {
        //output(1);
        scanf("%s",buf);
        if (buf[0]=='c')
        {
            int p1 = tree[1].n47;

            cout<<p1<<endl;

            //output(1);
        }
        else
        {
            int l,r;
            scanf("%d%d",&l,&r);

            lazy_update(1,0,n-1,l-1,r-1);

            //cout<<endl;
            //output(1);
            //cout<<endl;
        }
    }

	return 0;

}
