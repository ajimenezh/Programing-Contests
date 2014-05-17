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

#define MAXN 100005
#define MAXM 3*MAXN

long long sum[MAXM][5];
int ind[MAXM];
int v[MAXN];

void add(int id, int l, int r, int lt, int rt, int to) {
    if (l>rt || r<lt) return;
    if (l==r && l==lt) {
        ind[id] = (to+ind[id])%5;

        return;
    }
    int h = (l+r)/2;
    add(2*id,l,h,lt,rt,to+ind[id]);
    add(2*id+1,h+1,r,lt,rt,to+ind[id]);
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);


    return 0;

}
