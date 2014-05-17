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

long long a,b,w,x,c;
bool vis[1010];
pair<int,int> p[1010];

void brute_force(int aa, int bb, int cc) {
    int k = 0;
    while (aa<cc) {
        if (bb<x) {
            aa--;
            bb = w - (x-bb);
        }
        else bb -= x;
        cc--;
        k++;
    }
    cout<<k<<endl;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>w>>x>>c;

    //brute_force(a,b,c);

    long long tot = 0;
    long long m = 0;
    int k = b;
    if (c<=a) {
        cout<<0<<endl;
        return 0;
    }
    while (!vis[k]) {
        vis[k] = 1;
        int tmp = k;
        p[k] = make_pair(tot, m);
        if (k<x) {
            k = w-(x-k);
            m++;
        }
        else k -= x;
        tot++;
        if (c-tot<=a-m) {
            cout<<tot<<endl;
            return 0;
        }
    }
    long long ans = p[k].first;
    c -= p[k].first;
    a -= p[k].second;

    tot = tot - p[k].first;
    m = m - p[k].second;


    long long lo = 0;
    long long hi = 2000000000LL;

    while (lo<hi) {
        long long mi = (lo+hi+1)/2;
        if (c-mi*tot<=a-mi*m) hi = mi-1;
        else lo = mi;
    }

    c -= lo*tot;
    a -= m*lo;
    ans += lo*tot;

    while (c>a) {
        if (k<x) {
            k = w-(x-k);
            a--;
        }
        else k -= x;
        c--;
        ans++;
    }

    cout<<ans;

    return 0;

}
