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

long long k,b,n,t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>k>>b>>n>>t;

    if (k==1) {
        long long z = 1 + n*b;

        long long m;
        if (z>t) m = (z-t-1)/b + 1;
        else m = 0;

        cout<<m<<endl;
    }
    else {
        double p = (double)((double)t*(k-1)+b)/(b+k-1);
        p = log(p) / log(k);
        int x = n - (int)(p+1.0e-8);
        x = max(0,x);
        cout<<x<<endl;
    }

    return 0;

}
