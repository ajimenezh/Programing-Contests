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

int k,n;
int t[10010];
int f[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d%d",&f[i],&t[i]);

    bool done = false;
    int res;
    int tmp;
    for (int i=0; i<n; i++) {
        if (t[i]<k) tmp = f[i];
        else tmp = f[i] - (t[i]-k);
        if (!done || res<tmp) res = tmp;
        done = true;
    }
    cout<<res;


    return 0;

}
