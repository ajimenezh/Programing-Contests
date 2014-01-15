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

#define mod 4073989

int n,m;
int lim;

int v[mod], to[mod];

int hash(int x) {
    int key = x%mod;
    for (int i=key;;i++) {
        if (i==mod) i==0;
        if (to[i]&&to[i]!=x);
        else {
            to[i] = x;
            return i;
        }
    }
}
int search(int x) {
    int key = x%mod;
    for (int i=key;;i++) {
        if (i==mod) i==0;
        if (to[i]&&to[i]!=x);
        else {
            return i;
        }
    }
}

void add(int x, int y,int val) {
    for (int i=x; i<=lim; i+=i&-i) {
        for (int j=y; j<=lim; j+=j&-j) {
            v[hash(i*lim+j)] += val;
        }
    }
}

int sum(int x, int y) {
    int t = 0;
    for (int i=x; i>=1; i-=i&-i) {
        for (int j=y; j>=1; j-=j&-j) {
            t += v[search(i*lim+j)];
        }
    }
    return t;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n && n!=0) {
        cin>>m;
        lim = n*2;
        for (int i=0; i<mod; i++) to[i] = 0;
        for (int j=0; j<mod; j++) v[j] = 0;
        int x,y,z,p;
        for (int i=0; i<m; i++) {
            scanf("%d%d%d%d",&p,&x,&y,&z);
            int xx = x+y-1;
            int yy = x-y+n;
            if (p==1) {
                add(xx,yy,z);
            }
            else {
                int x1 = min(xx+z,lim);
                int y1 = min(yy+z,lim);
                int x2 = max(xx-z,1);
                int y2 = max(yy-z,1);
                int res = sum(x1,y1) - sum(x2-1,y1) - sum(x1,y2-1) + sum(x2-1,y2-1);
                printf("%d\n",res);
            }
        }
    }

    return 0;

}
