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

int n,m;
int x[100010], t[100010];
int ans[100010];

int solve(int cur, vector<pair<int,int> > v) {
    sort(v.begin(),v.end());
    int last = 0;
    for (int i=0; i<v.size(); i++) {
        int tmp = v[i].first-last;
        int j = i;
        int tot = 0;
        while (v[j].first==v[i].first) {
            ans[v[j].second] = cur + tmp;
            tot++;
            j++;
        }
        cur += tmp + 1 + tot/2;
        i = j-1;
        last = v[i].first;
    }
    return cur + v[v.size()-1].first;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) scanf("%d%d",&t[i],&x[i]);

    vector<pair<int,int> > v;
    int k = 0;
    int cur = 0;

    while (k<n) {
        v.clear();
        for (int i=k; i<min(k+m, n); i++) {
            v.push_back(make_pair(x[i],i));
            cur = max(cur, t[i]);
        }
        k += m;
        cur = solve(cur, v);
    }

    for (int i=0; i<n; i++) cout<<ans[i]<<" ";

    return 0;

}
