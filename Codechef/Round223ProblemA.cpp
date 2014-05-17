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

int m;
int t[100010];
int x[100010];
int c[100010];
int n;
long long k[100010];
long long par[100010];
int ans[100010];
set<pair<long long,int> > all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m;
    long long len = 0;
    for (int i=0; i<m; i++) {
        scanf("%d",t+i);
        if (t[i]==1) {
            scanf("%d",x+i);
            len++;
        }
        else {
            scanf("%d%d",x+i,c+i);
            len = len + (long long)x[i]*c[i];
        }
    }
    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d", k+i);
    for (int i=0; i<n; i++) all.insert(make_pair(-k[i],i));

    for (int i=m-1; i>=0; i--) {
        if (t[i]==1) {
            while (-(*all.begin()).first==len) {
                ans[(*all.begin()).second] = x[i];
                all.erase(all.begin());
            }
            len--;
        }
        else {
            len = len - (long long)x[i]*c[i];

            while (-(*all.begin()).first>len) {
                long long tt = -(*all.begin()).first;
                int pp = (*all.begin()).second;
                tt = (tt-len-1)%x[i] + 1;
                all.erase(all.begin());
                all.insert(make_pair(-tt, pp));
            }
        }
        //cout<<i<<" "<<len<<endl;
        //rep(it, all) cout<<-(*it).first<<" "; cout<<endl;
    }

    for (int i=0; i<n; i++) cout<<ans[i]<<" "; cout<<endl;

    return 0;

}
