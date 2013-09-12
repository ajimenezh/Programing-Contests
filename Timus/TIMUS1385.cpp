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



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n; cin>>n;
    if (n==1) cout<<14;
    else if (n==2) cout<<155;
    else {
        cout<<1575;
        for (int i=0; i<n-3; i++) cout<<0;
    }

    return 0;

}
