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
int a[1000010];
int sum[2500000];
int val[2500000];

void update(int id, int l, int r, int w, int h) {
    if (l==r && l==w) {
        sum[id] = 1;
        val[id] = h;
        return;
    }
    if (l>w || r<w) return;
    update(2*id, l, (l+r)>>1, w, h);
    update(2*id+1, ((l+r)>>1)+1, r, w, h);
    sum[id] = sum[2*id] + sum[2*id+1];
}

void erase(int id, int l, int r, int h) {
    if (l==r && h==1) {
        sum[id] = 0;
        val[id] = -1;
        return;
    }
    if (sum[2*id]<h) {
        erase(2*id+1, ((l+r)>>1)+1, r, h-sum[2*id]);
    }
    else erase(2*id, l, (r+l)>>1, h);
    sum[id] = sum[2*id] + sum[2*id+1];
}

int get(int id, int l, int r, int w) {
    if (l>w || r<w) return -1;
    if (l==r && l==w) return val[id];
    int mi = (l+r)>>1;
    int k1 = get(2*id, l, mi, w);
    int k2 = get(2*id+1, mi+1, r, w);
    if (k1!=-1) return k1;
    return k2;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) scanf("%d",a+i);

    int k = 1;
    for (int i=0; i<n; i++) {
        int h;
        scanf("%d",&h);
        if (h<0) {
            int t = sum[1];
            int j = 0;
            while (j<m && a[j]<=t) {
                j++;
            }
            for(j = j-1;j>=0; j--) erase(1,1,n,a[j]);
        }
        else {
            update(1,1,n,k,h);
            k++;
        }
    }

    if (sum[1]==0) cout<<"Poor stack!";
    else {
        for (int i=1; i<k; i++) {
            if (get(1,1,n,i)>-1) {
                cout<<get(1,1,n,i);
            }
        }
    }

    return 0;

}
