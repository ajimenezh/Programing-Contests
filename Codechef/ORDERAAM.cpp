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

int n;
pair<int,pair<int,int> > v[500];
int s[210];
int d[210];
int p[210];
int x[210];
long long dp[410];

long long solve(int i) {
    if (i==2*n) return 0;
    if (dp[i]>=0) return dp[i];

    long long tmp = 0;

    if (v[i].second.second<0) {
        for (int j=i+1; j<2*n; j++) {
            if (v[j].second.second<0) {
                int k = v[j].first - v[i].first;
                tmp = max(tmp, min(k, -v[j].second.second)*v[j].second.first + solve(j));
            }
            else {
                tmp = max(tmp, solve(j));
            }
        }
    }
    else {
        for (int j=i+1; j<2*n; j++) {
            if (v[j].second.second<0) {
                if (v[j].first-v[i].first>v[i].second.second) {
                    int k = v[j].first - v[i].first - v[i].second.second;
                    tmp = max(tmp, min(k, -v[j].second.second)*v[j].second.first + v[i].second.second*v[i].second.first + solve(j));
                }
                else {
                    int k = v[j].first - v[i].first;
                    tmp = max(tmp, min(k, v[i].second.second)*v[i].second.first + solve(j));
                }
            }
            else {
                int k = v[j].first - v[i].first;
                tmp = max(tmp, min(k, v[i].second.second)*v[i].second.first + solve(j));
            }
        }
    }
    cout<<i<<" "<<v[i].first<<" "<<tmp<<endl;
    dp[i] = tmp;

    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) scanf("%d%d%d%d",s+i,x+i,d+i,p+i);
        for (int i=0; i<n; i++) {
            v[2*i] = make_pair(s[i], make_pair(p[i],x[i]));
            v[2*i+1] = make_pair(d[i], make_pair(p[i],-x[i]));
        }
        sort(v,v+2*n);
        for (int i=0; i<2*n; i++) dp[i] = -1;
        long long ans = solve(0);
        ans = -ans;
        for (int i=0; i<n; i++) ans += p[i]*x[i];
        printf("%lld\n",ans);
    }

    return 0;

}
