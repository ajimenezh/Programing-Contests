#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

int n,m;
long long a[100010];
long long tree[265000][30];
int v[100010][30];

int where(int l, int z) {
    if (z==2) {
        if (l%2==1) return 0;
        else return 1;
    }
    else if (z==3) {
        for (int i=0; i<(2*3-2); i++) {
            if (l%4==i) return 2+i;
        }
    }
    else if (z==4) {
        for (int i=0; i<(2*4-2); i++) {
            if (l%6==i) return 6+i;
        }
    }
    else if (z==5) {
        for (int i=0; i<(2*5-2); i++) {
            if (l%8==i) return 12+i;
        }
    }
    else if (z==6) {
        for (int i=0; i<(2*6-2); i++) {
            if (l%10==i) return 20+i;
        }
    }
}

void build(int id, int l, int r, int t) {
    if (l==r) {
        tree[id][t] = v[l][t]*a[l-1];
        return;
    }
    int h = (l+r)>>1;
    build(2*id,l,h,t);
    build(2*id+1,h+1,r,t);
    tree[id][t] = tree[2*id][t] + tree[2*id+1][t];
}

void update(int id, int l, int r, int lt, int  rt, int  val, int t) {
    if (l>rt || r<lt) return;
    if (l>=lt && r<=rt) {
        tree[id][t] = (long long)v[l][t]*val;
        return;
    }
    int h = (l+r)>>1;
    update(2*id,l,h,lt,rt,val,t);
    update(2*id+1,h+1,r,lt,rt,val,t);
    tree[id][t] = tree[2*id][t] + tree[2*id+1][t];
}

long long get(int id, int l, int r, int lt, int rt, int t) {
    if (l>rt || r<lt) return 0 ;
    if (l>=lt && r<=rt) {
        return tree[id][t];
    }
    int h = (l+r)>>1;
    long long sum = 0;
    sum += get(2*id,l,h,lt,rt,t);
    sum += get(2*id+1,h+1,r,lt,rt,t);
    return sum;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%I64d",a+i);
    }
    for (int i=2; i<=6; i++) {
        //cout<<i<<endl;
        for (int j=1; j<=(2*i-2); j++) {
            //cout<<j<<endl;
            int h = where(j,i);
            for (int k=j; k<=n; k++) {
                if ((k-j+1)%(2*(i-1))==0) v[k][h] = 2;
                else if ((k-j+1)%(2*(i-1))>0 && (k-j+1)%(2*(i-1))<=i) v[k][h] = (k-j+1)%(2*(i-1));
                else v[k][h] = 2*i -  (k-j+1)%(2*(i-1));
                //cout<<v[k][h]<<" ";
            }
            build(1,1,n,h);
            //cout<<endl<<endl;
        }
        //cout<<endl;
    }

    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int type;
        scanf("%d",&type);
        if (type==1) {
            int p, val;
            scanf("%d%d",&p,&val);
            for (int ii=2; ii<=6; ii++) {
                for (int j=1; j<=(2*ii-2); j++) {
                    int h = where(j,ii);
                    if (p>=j) update(1,1,n,p,p,val,h);
                }
            }
        }
        else {
            int l,r,z;
            scanf("%d%d%d",&l,&r,&z);
            int h = where(l,z);
            //cout<<v[l][h]<<endl;
            printf("%I64d\n", get(1,1,n,l,r,h));
        }
    }

    return 0;

}
