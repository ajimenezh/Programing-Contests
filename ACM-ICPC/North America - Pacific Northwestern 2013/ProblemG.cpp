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

unsigned long long f[70];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    f[0] = 1;
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i=4; i<=67; i++) {
        f[i] = f[i-1] + f[i-2] + f[i-3] + f[i-4];
    }

    int tt;
    cin>>tt;
    while (tt--) {
        int n;
        cin>>n;
        cout<<f[n]<<endl;
    }

    return 0;

}
