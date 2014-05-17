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

int t;
int n;
long long p;

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>t;
    for (int tt=0; tt<t; tt++) {
        cin>>n>>p;

        long long all = 0;
        long long tot = 1LL<<n;
        int k = 1;
        while (true) {
            if (p>(1LL<<n)-tot/(1LL<<k) && k<=n) {
                all = 2LL*((1LL<<k)-1LL);
                k++;
            }
            else break;
        }
        all = min(all,(1LL<<n)-1LL);
        long long some = 0;
        tot = 1;
        k = n-1;
        while (true) {
            //cout<<p<<" "<<tot<<" "<<some<<endl;
            if (p>=tot) {
                some = (1LL<<n) - (1LL<<(k+1LL));
                tot = 2LL*tot;
                k--;
            }
            else break;
        }

        printf("Case #%d: %I64d %I64d\n",tt+1,all,some);
    }
    return 0;

}
