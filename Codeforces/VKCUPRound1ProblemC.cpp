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

int l1,r1,l2,r2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>l1>>r1>>l2>>r2;
    if (l1>l2) {
        int tmp = l1; l1 = l2; l2 = tmp;
        tmp = r1; r1 = r2; r2 = tmp;
    }

    if (l2>=l1 && r1>=r2) {
        cout<<r2-l2+1<<endl;
        return 0;
    }

    int res = 0;
    if (l2<r1) res = r1 - l2 + 1;


    for (int i=1; l1+(1<<i)<=r2; i++) {
        int k = (1<<i);
        int a = (l2-l1-1)/k + 1;
        int l = l1 + k*a;
        int r = min(r2,min(l+k-1,r1+k*a));

        res = max(res, r-l+1);
    }
    cout<<res<<endl;

    return 0;

}
