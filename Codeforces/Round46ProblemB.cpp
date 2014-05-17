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
    //freopen("output.txt","w",stdout);

    int a,b;
    cin>>a>>b;

    int tmp = a;

    int k = 9;
    while (tmp>0) {k = min(k, tmp%10); tmp /= 10;}
    k = 9;
    tmp = b;
    while (tmp>0) {k = min(k, tmp%10); tmp /= 10;}

    int c = a+b;
    int ans = 0;
    for (int i=k+1; i<=c; i++) {
        long long cur = i;
        int len = 0;
        while (c>=cur-1) {
            len++;
            cur = cur*i;
        }
        ans = max(len, ans);
        cout<<i<<" "<<len<<endl;
    }

    cout<<ans<<endl;

    return 0;

}
