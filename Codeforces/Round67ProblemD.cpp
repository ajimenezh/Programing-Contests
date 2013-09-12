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

struct node{
    long long l,r,sum,full;
    node() {
        l = 0; r = 0; sum = 0; full = 0;
    }
};

int n,m;
int a[5005][51];
node v[550000];
node p[51];
int s[51];
int b[250010];

void update(int id, int l, int r, int pos, node t) {
    if (l>pos || r<pos) return;
    if (l==r && l==pos) {
        v[id] = t;
        return;
    }

    int h = (l+r)/2;
    update(2*id,l,h,pos,t);
    update(2*id+1,h+1,r,pos,t);

    v[id].full = v[2*id].full + v[2*id+1].full;
    v[id].l = max(v[2*id].l, v[2*id].full + v[2*id+1].l);
    v[id].r = max(v[2*id+1].r,v[2*id+1].full + v[2*id].r);
    v[id].sum = max(v[2*id].sum, v[2*id+1].sum);
    v[id].sum = max(v[id].sum, v[2*id].r+v[2*id+1].l);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        scanf("%d",&s[i]);
        for (int j=0; j<s[i]; j++) {
            scanf("%d",&a[j][i]);
        }
    }
    for (int i=0; i<m; i++) {
        scanf("%d",&b[i]);
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<3*s[i]; j++) v[j] = node();
        for (int j=0; j<s[i]; j++) {
            node t;
            t.sum = (long long)a[j][i];
            t.full = (long long)a[j][i];
            t.l = (long long)a[j][i];
            t.r = (long long)a[j][i];
            update(1,1,s[i],j+1,t);
        }
        p[i] = v[1];
        //cout<<v[1].sum<<endl;
    }

    for (int i=0; i<550000; i++) v[i] = node();
    for (int i=0; i<m; i++) {
        update(1,1,m,i+1,p[b[i]-1]);
    }

    cout<<v[1].sum<<endl;

    return 0;

}
