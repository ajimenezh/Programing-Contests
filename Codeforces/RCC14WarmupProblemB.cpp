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

int n;
int last[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    bool bad = 0;
    for (int i=0; i<100000; i++) last[i] = -1;
    for (int i=0; i<n; i++) {
        int x,k;
        scanf("%d%d", &x, &k);
        if (last[k-1]<x-1) bad = 1;
        last[k-1] = max(last[k-1], x);
    }
    if (bad) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;

    return 0;

}
