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

int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) scanf("%d", a+i);

    long long ans = 0;
    int last = 0;
    for (int i=1; i<n; i++) {
        if (a[i]!=a[i-1]) {
            int k = i-last;
            ans += (long long)k*(k+1)/2;
            last = i;
        }
    }
    int k = n-last;
    ans += (long long)k*(k+1)/2;

    cout<<ans;

    return 0;

}
