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
int nex[300010];
int v[300010];

int next(int k) {
    if (!v[nex[k]]) return nex[k];
    nex[k] = next(nex[k]);
    return nex[k];
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) nex[i] = i+1;
    for (int i=0; i<m; i++) {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        l--; x--; r--;
        int k = l;
        while (k<=r) {
            if (k==x) {

            }
            else if (!v[k]) {
                v[k] = x+1;
                nex[k] = k+1;
            }
            k = next(k);
        }
    }
    for (int i=0; i<n; i++) cout<<v[i]<<" ";

    return 0;

}
