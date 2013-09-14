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
int m[110][110];
int sum[100][100][100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
        scanf("%d",&m[i][j]);
    }
    int ans = -100000000;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            sum[i][j][0] = m[i][j];
            ans = max(ans, sum[i][j][0]);
            for (int k=i-1; k>=0; k--) {
                sum[i][j][i-k] = sum[i][j][i-k-1] + m[k][j];
                ans = max(ans, sum[i][j][i-k]);
            }
        }
    }

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (j>0) {
                for (int k=i; k>=0; k--) {
                    sum[i][j][i-k] = max(sum[i][j][i-k], sum[i][j-1][i-k] + sum[i][j][i-k]);
                    ans = max(ans, sum[i][j][i-k]);
                }
            }
        }
    }
    cout<<ans<<endl;

    return 0;

}
