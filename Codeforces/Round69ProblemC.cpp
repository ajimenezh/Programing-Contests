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

int n;
int c[100010];
vector<int> e[100010];
bool vis[100010];
int s;

pair<int,int> dfs(int p, int pre) {
    vis[p] = 1;
    //cout<<p<<endl;
    int tmp = 0;
    int k = 0;
    vector<pair<int,int> > cnt;
    rep(it,e[p]) {
        int q = *it;
        if (q==pre) continue;
        cnt.push_back(dfs(q,p));
        k++;
    }

    sort(cnt.begin(),cnt.end());
    reverse(cnt.begin(),cnt.end());

    for (int i=0; i<k; i++) {
        //cout<<c[p]<<" "<<cnt[i].first<<" "<<cnt[i].second<<endl;
        if ((c[p]>1 || ( p==s-1 && c[p]>0)) && cnt[i].second>0){
            tmp += cnt[i].first + 2;
            cnt[i].second--;
            c[p]--;
        }
    }
    //cout<<p+1<<" "<<tmp<<" "<<c[p]<<endl;
    for (int i=0; i<k; i++) {
        if ((c[p]>1 || (p==s-1 && c[p]>0)) && cnt[i].second>0) {
            tmp += 2*min(cnt[i].second,c[p]-1);
            int t = min(cnt[i].second,c[p]-1);
            cnt[i].second -= t;
            c[p] -= t;
        }
    }


    //cout<<p+1<<" "<<tmp<<" "<<c[p]<<endl;
    return make_pair(tmp,c[p]);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",&c[i]);
    for (int i=0; i<n-1; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    cin>>s;
    for (int i=0; i<n; i++) vis[i] = 0;

    pair<int,int> p = dfs(s-1,-1);

    cout<<p.first<<endl;

    return 0;

}
