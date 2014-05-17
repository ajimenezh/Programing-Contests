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

string s;
string rev;
int dp[2][20010][3][2];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    //cin>>s;
    for (int i=0; i<10000; i++) s += 'A';
    for (int j=0; j<10000; j++) s += 'N';
    rev = s;
    reverse(rev.begin(),rev.end());
    for (int i=0; i<rev.length(); i++) {
        if (rev[i]>='N') rev[i] = char('A' + rev[i]-'N');
        else rev[i] = char('N' + rev[i]-'A');
    }
    n = s.length();

    int best = 0;
    int p, q;
    int x1,x2,y1,y2;
    for (int i=0; i<n; i++) {
        int cur = i%2;
        int next = 1 - cur;
        for (int t=0; t<2; ++t) {
            for (int j=0; j<n; ++j) {
                for (int k=(t==1?0:2); k<3; ++k) {
                    dp[next][j][k][t] = 0;
                }
            }
        }
        for (int t=0; t<2; ++t) {
            for (int j=0; j<n; ++j) {
                for (int k=(t==1?0:2); k<3; ++k) {
                    if (t==1 && dp[cur][j][k][t]>0) {
                        if (s[i]==rev[j]) {
                            if (1 + dp[cur][j][k][t] > dp[next][j+1][k][t])
                                dp[next][j+1][k][t] = 1 + dp[cur][j][k][t];
                        }
                        else {
                            if (k>0 && dp[cur][j][k][t]>dp[cur][j+1][k-1][t]) dp[cur][j+1][k-1][t] = dp[cur][j][k][t];
                        }
                    }
                    else {
                        if (s[i]==rev[j] && dp[next][j+1][k][1]<1) {
                            dp[next][j+1][k][1] = 1;
                        }
                    }
                }
            }
        }
        for (int t=0; t<2; ++t) {
            for (int j=0; j<=n; ++j) {
                for (int k=(t==1?0:2); k<3; ++k) {
                    if (dp[cur][j][k][t]>best) {
                        x1 = i - dp[cur][j][k][t];
                        y1 = i - 1;
                        y2 = j - dp[cur][j][k][t] - (2-k);
                        x2 = j - 1;
                        y2 = n - 1 - y2;
                        x2 = n - 1 - x2;

                        if (x1>y2 || x2>y1) {
                            //cout<<dp[cur][j][k][t]<<" "<<i<<" "<<j<<" "<<k<<endl;
                            //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

                            best = dp[cur][j][k][t];
                            p = x1;
                            q = x2;
                        }
                    }
                }
            }
        }
    }

    int cur = n%2;
    int i = n;
    for (int j=0; j<=n; j++) {
        for (int k=0; k<3; k++) {
            int t = 1;
            if (dp[cur][j][k][t]>best) {
                x1 = i - dp[cur][j][k][t];
                y1 = i - 1;
                y2 = j - dp[cur][j][k][t] - (2-k);
                x2 = j - 1;
                y2 = n - 1 - y2;
                x2 = n - 1 - x2;

                if (x1>y2 || x2>y1) {
                    //cout<<dp[cur][j][k][t]<<" "<<i<<" "<<j<<" "<<k<<endl;
                    //cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;

                    best = dp[cur][j][k][t];
                    p = x1;
                    q = x2;
                }
            }
        }
    }

    if (best==0) printf("-\n");
    else {
        cout<<s.substr(p,best)<<"\n";
        printf("%d\n%d\n", p+1, q+1);
    }

    return 0;

}
