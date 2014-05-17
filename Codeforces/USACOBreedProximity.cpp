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

int n,k;
int a[50010];
map<int,int> prev;

int main() {

    freopen("proximity.in","r",stdin);
    freopen("proximity.out","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    int sol = -1;
    for (int i=0; i<n; i++) {
        if (prev.find(a[i])==prev.end()) {
            prev[a[i]] = i;
        }
        else {
            if (i-prev[a[i]]<=k) {
                sol = max(sol,a[i]);
            }
            prev[a[i]] = i;
        }
    }
    cout<<sol;
    return 0;

}
