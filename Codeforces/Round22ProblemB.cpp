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
string s[29];
int sum[30][30];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>s[i];
    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) sum[i+1][j+1] = sum[i][j+1] + sum[i+1][j] - sum[i][j] + (s[i][j]=='1');
    }
    int best = 0;
    for (int i=0; i<n;i++) {
        for (int j=0; j<m; j++) {
            for (int ii=i; ii<n; ii++) {
                for (int jj=j; jj<m; jj++) {
                    int tot = sum[ii+1][jj+1] - sum[i][jj+1] - sum[ii+1][j] + sum[i][j];
                    if (tot==0) best = max(best, 2*(ii-i+1) + 2*(jj-j+1));
                }
            }
        }
    }
    cout<<best<<endl;

    return 0;

}
