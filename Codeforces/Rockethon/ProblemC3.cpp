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

int n,k;
int p[200010];
int p2[200010];
int e[200010];
pair<int,int> v[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d%d",p+i,e+i);
    for (int i=0; i<n; i++) v[i] = make_pair(p[i],e[i]);

    sort(v,v+n);
    reverse(v,v+n);
    int t = v[k-1].first;
    if (t>n) {
        cout<<-1<<endl;
        return 0;
    }

    for (int i=0; i<n; i++) v[i] = make_pair(e[i],i);
    sort(v,v+n);

    long long res = 1000000000000LL;
    long long tot = 0;
    for (int i=0; i<t+2; i++) tot += v[i].first;
    res = min(res, tot);

    for (int i=0; i<n; i++) {
        if (p[i]==t+1 || p[i]==t) v[i] = make_pair(e[i],-1);
        else v[i] = make_pair(e[i],1);
    }
    int s = 0;
    tot = 0;
    sort(v,v+n);
    int tmp = (n+1) - k;
    for (int i=0; i<n; i++) if (p[i]<t) tmp--;
    int tt = t+1;
    for (int i=0; i<n; i++) {
        if (v[i].second==-1) {
            if (tmp>0) {
                tmp--;
                tt--;
                tot += v[i].first;
            }
            else {
                if (tt>0) {
                    tt--;
                    tot += v[i].first;
                }
            }
        }
        else {
            if (tt>tmp) {
                tot += v[i].first;
                tt--;
            }
        }
    }
    if (tt<=0 && tmp<=0) res = min(res, tot);

    for (int i=0; i<n; i++) {
        if (p[i]==t-1 || p[i]==t) v[i] = make_pair(e[i],-1);
        else v[i] = make_pair(e[i],1);
    }
    s = 0;
    tot = 0;
    sort(v,v+n);
    tmp = (n+1) - k;
    for (int i=0; i<n; i++) if (p[i]<t-1) tmp--;
    tt = t;
    for (int i=0; i<n; i++) {
        if (v[i].second==-1) {
            if (tmp>0) {
                tmp--;
                tt--;
                tot += v[i].first;
            }
            else {
                if (tt>0) {
                    tt--;
                    tot += v[i].first;
                }
            }
        }
        else {
            if (tt>tmp) {
                tot += v[i].first;
                tt--;
            }
        }
    }
    if (tt<=0 && tmp<=0) res = min(res, tot);

    cout<<res<<endl;

    return 0;

}
