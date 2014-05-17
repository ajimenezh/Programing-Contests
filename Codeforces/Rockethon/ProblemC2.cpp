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
int sp[200010];
int dp[2][110][110][110];

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
    int s = 0;
    k = (n+1) - k;
    for (int i=0; i<n; i++) if (p[i]<t-1) k--;
    for (int i=0; i<n; i++) {
        v[i] = make_pair(e[i],i);
    }
    sort(v,v+n);
    for (int i=0; i<n; i++) {
        if (p[v[i].second]==t) sp[i] = 1;
        if (p[v[i].second]==t-1) sp[i] = 2;
    }
    int tot1 = 0, tot2 = 0;;
    for (int i=0; i<n; i++) {
        if (sp[i]==1) tot1++;
        if (sp[i]==2) tot2++;
    }

    int res = 100000000;
    for (int tt=0; tt<=t+2; tt++) {
        for (int j=0; j<=tot1; j++) {
            for (int m=0; m<=tot2; m++) {
                dp[1][tt][j][m] = 100000000;
            }
        }
    }
    dp[1][t+2][0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int tt=0; tt<=t+2; tt++) {
            for (int j=0; j<=tot1; j++) {
                for (int m=0; m<=tot2; m++) {
                    dp[i%2][tt][j][m] = 100000000;

                    if (tt!=t+2) {
                        if (sp[i]==0) {
                            dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j][m]);
                        }
                        if (sp[i]==1) {
                            if (j!=0) dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j-1][m]);
                            else dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                        }
                        if (sp[i]==2) {
                            if (m!=0) dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j][m-1]);
                            else dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                        }
                    }
                    else {
                        dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                    }

                    if (tt==0) res = min(res, dp[i%2][tt][j][m]);
                    if (tt==2) {
                        if (k<=m+j) res = min(res, dp[i%2][tt][j][m]);
                    }

                    //cout<<i<<" "<<tt<<" "<<j<<" "<<m<<" "<<dp[i%2][tt][j][m]<<endl;
                }
            }
        }
    }

    for (int i=0; i<n; i++) {
        if (p[v[i].second]==t || p[v[i].second]==t+1) sp[i] = 1;
        if (p[v[i].second]==t-1) sp[i] = 2;
    }

    tot1 = 0, tot2 = 0;;
    for (int i=0; i<n; i++) {
        if (sp[i]==1) tot1++;
        if (sp[i]==2) tot2++;
    }

    for (int tt=0; tt<=t+2; tt++) {
        for (int j=0; j<=tot1; j++) {
            for (int m=0; m<=tot2; m++) {
                dp[1][tt][j][m] = 100000000;
            }
        }
    }
    dp[1][t+2][0][0] = 0;
    for (int i=0; i<n; i++) {
        for (int tt=0; tt<=t+2; tt++) {
            for (int j=0; j<=tot1; j++) {
                for (int m=0; m<=tot2; m++) {
                    dp[i%2][tt][j][m] = 100000000;

                    if (tt!=t+2) {
                        if (sp[i]==0) {
                            dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j][m]);
                        }
                        if (sp[i]==1) {
                            if (j!=0) dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j-1][m]);
                            else dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                        }
                        if (sp[i]==2) {
                            if (m!=0) dp[i%2][tt][j][m] = min(dp[1-i%2][tt][j][m], v[i].first + dp[1-i%2][tt+1][j][m-1]);
                            else dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                        }
                    }
                    else {
                        dp[i%2][tt][j][m] = dp[1-i%2][tt][j][m];
                    }

                    if (tt==0) res = min(res, dp[i%2][tt][j][m]);
                    if (tt==1) {
                        if (k<=tot2+j) res = min(res, dp[i%2][tt][j][m]);
                    }

                    //cout<<i<<" "<<tt<<" "<<j<<" "<<m<<" "<<dp[i%2][tt][j][m]<<endl;
                }
            }
        }
    }

    if (res!=100000000) cout<<res<<endl;
    else cout<<-1;

    return 0;

}

