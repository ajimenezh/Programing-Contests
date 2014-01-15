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

int W,H,w,h;

int main() {

    freopen("garage.in","r",stdin);
    freopen("garage.out","w",stdout);

    cin>>W>>H>>w>>h;

    int ans = 1;

    if (W<w) ans = 0;
    else ans *= max(1,(W/w+1)/2);
    if (H<h) ans = 0;
    else ans *= max(1,(H/h+1)/2);

    cout<<ans<<endl;

    return 0;

}
