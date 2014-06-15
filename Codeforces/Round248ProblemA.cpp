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

int n,m;
int a[100010];
vector<pair<int,int> > v[100010];

long long f(int i, int x) {
    long long tot = 0;
    for (int j=0; j<v[i].size(); j++) {
        int t1 = v[i][j].first;
        if (t1==i || t1==-1) t1 = x;
        int t2 = v[i][j].second;
        if (t2==i || t2==-1) t2 = x;
        tot += abs(t1-x) + abs(t2-x);
    }
    return tot;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) scanf("%d", a+i);

    if (m==1) {
        cout<<0<<endl;
        return 0;
    }
    for (int i=0; i<m; i++) {
        if (i==0) v[a[i]].push_back(make_pair(-1, a[i+1]));
        else if (i==m-1) v[a[i]].push_back(make_pair(a[i-1], -1));
        else v[a[i]].push_back(make_pair(a[i-1], a[i+1]));
    }

    int p = 0;
    int to = 0;
    long long best = 0;

    for (int i=1; i<=n; i++) {
        int lo = 1;
        int hi = n;
        long long tmp = f(i,i);
        while (lo<hi-2) {
            int l = (2*lo+hi)/3;
            int r = (lo+2*hi)/3;
            long long fl = tmp - f(i, l);
            long long fr = tmp - f(i,r);

            if (fl<fr) lo = l;
            else hi = r;
        }

        for (int j=lo; j<=hi; j++) {
            if (best<tmp-f(i,j)) {
                best = tmp - f(i, j);
                p = i;
                to = j;
            }
        }
    }
    //cout<<p<<" "<<to<<endl;
    //for (int i=1; i<=n; i++) cout<<f(4, i)<<endl;

    long long res = 0;
    for (int i=0; i<m; i++) if (a[i]==p) a[i] = to;
    for (int i=0; i<m-1; i++) {
        res += abs(a[i+1]-a[i]);
    }
    cout<<res<<endl;

    return 0;

}
