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

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int cas=1; cas<=t; cas++) {
        int n,k,c;
        cin>>n>>k>>c;

        int ans = 100000000;

        for (int i=0; i<n; i++) {
            int m = k%(n-i);
            int tmp = i;
            int cc = c - (k-m);
            if (cc<=0) tmp += c;
            else tmp += c + ((n-i)-m);
            ans = min(ans, tmp);
        }

        printf("Case #%d: %d\n",cas,ans);
    }

    return 0;

}
