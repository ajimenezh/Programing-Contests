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

int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int n;
        cin>>n;
        for (int i=0; i<n; i++) scanf("%d", &a[i]);
        sort(a,a+n);
        long long tot = 0;
        int last = 0;
        for (int i=1; i<n; i++) {
            if (a[i]!=a[i-1]) {
                tot += (long long)(i-last)*(i-last-1);
                last = i;
            }
        }
        tot += (long long)(n-last)*(n-last-1);
        printf("%lld\n", tot);
    }

    return 0;

}
