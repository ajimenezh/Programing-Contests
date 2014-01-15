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
set<int> all;
int v[300010];
set<int>::iterator q[300010];
int in,fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) all.insert(i);
    for (int i=0; i<m; i++) {
        int l,x,r;
        scanf("%d%d%d",&l,&r,&x);
        l--; r--;
        set<int>::iterator it1, it2;
        it1 = all.lower_bound(l);
        in = 0; fn = 0;
        for (set<int>::iterator it = it1; it!=all.end(); it++) {
            if ((*it)>r) break;
            if ((*it)!=x-1) {
                q[fn++] = it;
                v[(*it)] = x;
            }
        }
        while (in<fn) all.erase(q[in++]);
    }

    for (int i=0; i<n; i++) cout<<v[i]<<" ";

    return 0;

}
