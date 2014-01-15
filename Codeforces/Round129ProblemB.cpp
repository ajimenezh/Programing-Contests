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

int n;
map<int,int> up;
map<int,int> down;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (up.find(a)==up.end()) up[a] = 0;
        if (up.find(b)==up.end()) up[b] = 0;
        if (down.find(a)==down.end()) down[a] = 0;
        if (down.find(b)==down.end()) down[b] = 0;
        up[a]++;
        if (a!=b) down[b]++;
    }

    int res = 1000000000;
    n = (n-1)/2 + 1;
    rep(it, up) {
        int d = down[(*it).first];
        int u = (*it).second;
        if (d+u>=n) {
            if (u>=n) res = 0;
            else res = min(res, n-u);
        }
    }

    if (res==1000000000) cout<<-1;
    else cout<<res;

    return 0;

}
