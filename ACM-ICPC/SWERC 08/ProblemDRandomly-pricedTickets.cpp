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

double dp[110][3100];
int n,r;
int dist[110][110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int cas=1; cas<=tt; cas++) {
        cin>>n>>r;

        for (int i=0; i<=n; i++) {
            for (int j=0; j<n*r; j++) {
                dp[i][j] = 0.0;
            }
        }

        dp[0][0] = 1;

        for (int i=0; i<n; i++) {
            for (int j=0; j<n*r; j++) {
                if (dp[i][j]<1.0e-8) continue;

                for (int k=1; k<=r; k++) if (j+k<=n*r) {
                    dp[i+1][j+k] += dp[i][j]*1.0/(double)r;
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=1; j<n*r; j++) {
                dp[i][j] = dp[i][j-1] + dp[i][j];
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                dist[i][j] = 10000;
            }
            dist[i][i] = 0;
        }

        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            for (int j=0; j<s.length(); j++) {
                if (s[j]=='Y') dist[i][j] = 1;
            }
        }

        for (int k=0; k<n; k++) {
            for (int i=0; i<n; i++) {
                for (int j=0; j<n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int q;
        cin>>q;
        printf("Case %d\n",cas);
        for (int i=0; i<q; i++) {
            int a,b,m;
            scanf("%d%d%d",&a,&b,&m);
            a--; b--;
            m = min(m, n*r-1);
            printf("%.12lf\n", dp[dist[a][b]][m]);
        }
        printf("\n");
    }

    return 0;

}
