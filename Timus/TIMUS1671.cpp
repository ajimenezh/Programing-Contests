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
int par[100010];
int si[100010];
pair<int, int> e[100010];
map<pair<int,int>,int> all;
int w[100010];

int get(int a) {
    if (a==par[a]) return a;
    par[a] = get(par[a]);
    return par[a];
}

bool connect(int a, int b) {
    a = get(a);
    b = get(b);
    if (a==b) return false;
    if (si[a]>si[b]) {
        par[a] = b;
        si[b]++;
    }
    else {
        par[b] = a;
        si[a]++;
    }

    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) par[i] = i;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[i] = make_pair(min(a,b)-1,max(a,b)-1);
    }
    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int t;
        scanf("%d",&t);
        w[i] = t-1;
        all[e[t-1]]++;
    }
    vector<int> ans;

    int cnt = n;
    for (int i=0; i<m; i++) {
        if (all[e[i]]==0) {
            if (connect(e[i].first,e[i].second)) cnt--;
        }
        else all[e[i]]--;
    }
    ans.push_back(cnt);
    for (int i=q-1; i>=1; i--) {
        if (connect(e[w[i]].first,e[w[i]].second)) cnt--;
        ans.push_back(cnt);
    }
    reverse(ans.begin(),ans.end());

    for (int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";

    return 0;

}
