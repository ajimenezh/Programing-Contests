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

    int n;
    cin>>n;
    long long red = 0, blue = 0;

    for (int i=0; i<n; i++) {
        if (i%2==0) {
            red = (red + blue + 1)%1000000007;
        }
        else {
            blue = (red + blue + 1)%1000000007;
        }
    }

    long long tot = (red + blue)%1000000007;

    cout<<tot<<endl;

    return 0;

}
