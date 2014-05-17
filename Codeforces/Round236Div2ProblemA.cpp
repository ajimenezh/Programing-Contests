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

int k, a, b, v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>k>>a>>b>>v;

    for (int i=1; i<=a; i++) {
        int tot = 0;
        int bb = b;
        for (int j=1; j<=i; j++) {
            int tmp = min(k-1, bb);
            bb -= tmp;
            tot += tmp+1;
        }
        if (tot*v>=a) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;

}
