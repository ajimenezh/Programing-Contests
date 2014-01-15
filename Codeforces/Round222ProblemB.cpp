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

int n,m,s;
int a[100010];
pair<int,int> b[100010];
int c[100010];
pair<pair<int,int>,int> v[100010];
int w[100010];
set<pair<int,int> > all;
int cnt[100010];

bool check(int t) {
    all.clear();
    for (int i=0; i<n; i++) cnt[i] = 0;

    int k = 0;
    long long sum = 0;
    for (int i=0; i<m; i++) {
        while (k<n && v[k].first.first>=b[i].first) {
            all.insert(make_pair(v[k].first.second, v[k].second));
            k++;
        }
        set<pair<int,int> >::iterator it = all.begin();
        while (it != all.end()) {
            if (cnt[(*it).second]==t) {
                all.erase(all.begin());
                it = all.begin();
            }
            else {
                cnt[(*it).second]++;
                sum += (*it).first;
                w[b[i].second] = ((*it).second);
                int tmp = (*it).second;
                if ((*it).first!=0) {
                    all.erase(all.begin());
                    all.insert(make_pair(0,tmp));
                }
                break;
            }
        }
        if (it==all.end()) return false;
    }
    if (sum>s) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>s;
    for (int i=0; i<m; i++) {
        int tmp;
        scanf("%d",&tmp);
        b[i] = make_pair(tmp,i);
    }
    for (int j=0; j<n; j++) scanf("%d",a+j);
    for (int i=0; i<n; i++) scanf("%d",c+i);
    sort(b,b+m);
    reverse(b,b+m);
    for (int i=0; i<n; i++) v[i] = make_pair(make_pair(a[i],c[i]),i);
    sort(v,v+n);
    reverse(v,v+n);

    int lo = 1;
    int hi = m+1;

    while (lo<hi) {
        int mi = (lo+hi)/2;
        if (check(mi)) {
            hi = mi;
        }
        else lo = mi+1;
    }

    if (lo == m+1) cout<<"NO";
    else {
        cout<<"YES"<<endl;
        check(lo);
        for (int i=0; i<m; i++) cout<<w[i]+1<<" ";
    }

    return 0;

}
