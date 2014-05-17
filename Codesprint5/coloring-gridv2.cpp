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
int k;
const int mod = 1000000007;
int a[8][8];

int rec(int x, int y) {
    if (x==n) return 1;
    if (y==m) return rec(x+1,0);

    long long tmp = 0;
    set<int> all;
    for (int i=0; i<x; i++) {
        for (int j=0; j<m; j++) all.insert(a[i][j]);
    }
    for (int j=0; j<y; j++) all.insert(a[x][j]);
    rep(it, all) {
        if (y==0) {
            if (x==0) rec(x,y);
            else {
                if (*it!=a[x-1][y]) {
                    a[x][y] = *it;
                    tmp = (tmp + rec(x,y+1));
                }
            }
        }
        else {
            if (x==0) {
                if (*it!=a[x][y-1]) {
                    a[x][y] = *it;
                    tmp = (tmp + rec(x,y+1));
                }
            }
            else {
                if (*it!=a[x][y-1] && *it!=a[x-1][y]) {
                    a[x][y] = *it;
                    tmp = (tmp + rec(x,y+1));
                }
            }
        }
    }
    a[x][y] = all.size()+1;
    tmp = (tmp + (k-all.size())*rec(x,y+1)%mod);
    if (tmp>=mod) tmp -= mod;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m>>k;
        if (n<m) swap(n,m);
        long long ans = 0;
        if (m==1) {
            ans = k;
            for (int i=0; i<n-1; i++) ans = (ans*(k-1))%mod;
        }
        else {
            ans = rec(0,0);
        }
        cout<<ans<<endl;
    }

    return 0;

}
