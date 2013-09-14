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

int v[130000];

void update(int id, int l, int r, int i, int x) {
    if (i<l || i>r) return;
    if (l==r && i==l) {
        v[id] = x;
        return;
    }
    int h = (l+r)/2;
    update(2*id,l,h,i,x);
    update(2*id+1,h+1,r,i,x);
    v[id] = max(v[2*id],v[2*id+1]);
}

int get(int id, int l, int r, int lt, int rt) {
    if (l>rt || r<lt) return -1;
    if (l>=lt && r<=rt) {
        return v[id];
    }
    int h = (l+r)/2;
    int x = -1;
    x = max(x, get(2*id,l,h,lt,rt));
    x = max(x, get(2*id+1,h+1,r,lt,rt));
    return x;
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int m, x, i;
    cin>>m;
    for (i=0; i<m; i++) {
        scanf("%d",&x);
        update(1,1,25100,i+1,x);
    }
    cout<<get(1,1,25100,i+1-m,i)<<endl;
    while (scanf("%d",&x) && x!=-1) {
        update(1,1,25100,i+1,x);
        cout<<get(1,1,25100,i+2-m,i+1)<<endl;
        i++;
    }


    return 0;

}

