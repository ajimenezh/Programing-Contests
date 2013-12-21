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

long long w,m,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>w>>m>>k;

    long long t = 1;
    long long p = 1;
    while (t*10<m) {t *= 10; p++;}
    t *= 10;

    long long s = 0;
    while (w) {
        if ((t-m)<=w/(p*k)) {
            s += (t-m);
            w -= p*(t-m)*k;
            p++;
            m = t;
            t *= 10;
        }
        else {
            s += w/(p*k);
            w = 0;
        }
    }
    cout<<s<<endl;

    return 0;

}
