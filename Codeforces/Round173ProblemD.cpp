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
int a[301];
bool dp[301][301];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    if (n==1) {
        if (a[0]) cout<<"BitLGM"<<endl;
        else cout<<"BitAryo"<<endl;
    }
    else if (n==2) {
        for (int i=0; i<301; i++) for (int j=0; j<301; j++) dp[i][j] = 1;
        dp[0][0] = 1;
        for (int i=0; i<301; i++) for (int j=0; j<301; j++) for (int k=1; k<301; k++) if (i!=0 || j!=0) {
            bool f = 0;
            if (i>=k) f |= dp[i-k][j];
            if (j>=k) f |= dp[i][j-k];
            if (j>=k && i>=k) f |= dp[i-k][j-k];
            dp[i][j] = (1-f) && dp[i][j];
        }
        if (!dp[a[0]][a[1]]) cout<<"BitLGM"<<endl;
        else cout<<"BitAryo"<<endl;
    }
    else {
        int t = a[0]^(a[1]^a[2]);
        if (t) cout<<"BitLGM"<<endl;
        else cout<<"BitAryo"<<endl;
    }

    return 0;

}
