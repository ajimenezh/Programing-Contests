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

int x[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,vb,vs;
    cin>>n>>vb>>vs;
    for (int i=0; i<n; i++) {
        cin>>x[i];
    }
    int xu,yu;
    cin>>xu>>yu;

    double ans = 10000000.0;
    double d = 0.0;
    int best;

    for (int i=1; i<n; i++) {
        double t1 = (double)x[i]/vb;
        double t2 = (double)sqrt((long long)(x[i]-xu)*(x[i]-xu) + (long long)yu*yu) / vs;
        if (ans>t1+t2) {
            ans = t1+t2;
            best = i;
            d = (double)sqrt((long long)(x[i]-xu)*(x[i]-xu) + (long long)yu*yu);
        }
        if (abs(ans-t1-t2)<1.0e-6) {
            if (d>(double)sqrt((long long)(x[i]-xu)*(x[i]-xu) + (long long)yu*yu)) {
                d = (double)sqrt((long long)(x[i]-xu)*(x[i]-xu) + (long long)yu*yu);
                best = i;
            }
        }
    }

    cout<<best+1<<endl;

    return 0;

}
