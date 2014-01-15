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

long long K;
set<pair<long long,long long> > v;

void solve(int n) {
    long long k = K;

    long long lo = n;
    long long hi = k;

    while (lo<hi) {
        //cout<<lo<<" "<<hi<<endl;
        long long prod = 1;

        long long mid = (lo+hi)/2LL;
        for (int i=0; i<n; i++) {
            if (prod > (1+k/(mid-i))*(i+1)) {
                prod = k + 1;
                break;
            }
            prod *= (mid-i);
            prod /= i+1;
        }

        if (prod>=k) {
            hi = mid;
        }
        else {
            lo = mid+1;
        }
    }

    long long prod = 1;
    for (int i=0; i<n; i++) {
        prod *= (lo-i);
        prod /= i+1;
    }
    //cout<<lo<<" "<<n<<" "<<prod<<endl;
    if (prod==k) {
        v.insert(make_pair(lo,n));
        if (lo != 2*k) {
            v.insert(make_pair(lo,lo-n));
        }
    }

    //cout<<n<<endl;
    //cout<<lo<<" "<<hi<<endl;
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=0; tt<t; tt++) {

        cin>>K;
        v.clear();

        for (int i=0; i<min(65LL,K/2+1); i++) {
            solve(i);
        }

        cout<<v.size()<<endl;;
        rep(it,v) cout<<"("<<(*it).first<<","<<(*it).second<<") ";

        cout<<endl;
    }

    return 0;

}
