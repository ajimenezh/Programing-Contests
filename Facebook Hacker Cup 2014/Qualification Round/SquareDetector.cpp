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
string vs[25];
int sum[25][25];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int maxCases;
    cin>>maxCases;

    for (int cas=1; cas<=maxCases; cas++) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>vs[i];
        int tot = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (vs[i][j]=='#') tot++;
            }
        }

        for (int i=0; i<=n; i++) for (int j=0; j<=n; j++) sum[i][j] = 0;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (vs[i][j]=='#');
        }

        bool good = 0;
        for (int k=1; k<=n; k++) {
            for (int i=0; i<n-k+1; i++) {
                for (int j=0; j<n-k+1; j++) {
                    int partial = sum[i+k][j+k] - sum[i][j+k] - sum[i+k][j] + sum[i][j];
                    if (partial==tot && partial==k*k) {
                        good = 1;
                    }
                }
            }
        }

        printf("Case #%d: ",cas);
        cout<<(good?"YES":"NO")<<"\n";
    }

    return 0;

}
