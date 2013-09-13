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

    int t,s;
    cin>>t>>s;
    double m = 0.0;
    if (t==1) m = 2*s;
    else if (t==2) m = sqrt(2)*s;
    else m = s;

    int n;
    cin>>n;
    int res = 0;
    for (int i=0; i<n; i++) {
        cin>>t>>s;
        if (t==1) {
            if (m-2*s>-1.0e-8) res++;
        }
        else if (t==2) {
            if (m-s>-1.0e-8) res++;
        }
        else {
            if (m-s*sqrt(3.0)/2.0>-1.0e-8) res++;
        }
    }

    cout<<res<<endl;

    return 0;

}
