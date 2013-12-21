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

long long next(long long x) {
    vector<int> v;
    while (x>0) {
        v.push_back(x%10);
        x /= 10;
    }
    int r = 1;
    long long y = 0;
    long long k = 1;
    for (int i=0; i<v.size(); i++) {
        if (!r) {
            y += v[i]*k;
        }
        else {
            if (v[i]==4) {
                y += 7*k;
                r = 0;
            }
            else y += 4*k;
        }
        k *= 10;
    }
    if (r) y += k*4;
    return y;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int l, r;
    cin>>l>>r;
    long long x = 4;
    while (x<l) {
        x = next(x);
    }

    long long ans = 0;
    ans += (long long)x*(x-l+1);

    if (r<x) {
        ans = (long long)(r-l+1)*x;
    }
    else {
        while (next(x)<=r) {
            long long y = next(x);
            ans += (long long)y*(y-x);
            x = y;
        }
        long long y = next(x);
        ans += (long long)y*(r-x);
    }

    cout<<ans<<endl;

    return 0;

}
