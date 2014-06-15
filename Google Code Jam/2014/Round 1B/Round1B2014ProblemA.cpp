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
string s[110];
string w[110];
int cnt[110][110];

int main() {

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>s[i];
        for (int i=0; i<n; i++) w[i] = "";

        for (int i=0; i<n; i++) {
            int tot = 0;
            for (int j=0; j<s[i].length(); j++) {
                if (j==0 || s[i][j]==s[i][j-1]) {
                    tot++;
                }
                else {
                    w[i] += s[i][j-1];
                    cnt[i][w[i].length()-1] = tot;
                    tot = 1;
                }
            }
            w[i] += s[i][s[i].length()-1];
            cnt[i][w[i].length()-1] = tot;

        }

        bool bad = 0;
        for (int i=1; i<n; i++) {
            if (w[i]!=w[i-1]) bad = 1;
        }

        if (bad) {
            printf("Case #%d: Fegla Won\n", tt);
        }
        else {
            int res = 0;
            for (int i=0; i<w[0].size(); i++) {
                int m = 0;
                for (int j=0; j<n; j++) m = max(m, cnt[j][i]);
                int best = 1000000;
                for (int k=1; k<=m; k++) {
                    int tot = 0;
                    for (int j=0; j<n; j++) {
                        tot += abs(cnt[j][i]-k);
                    }
                    best = min(best, tot);
                }
                res += best;
            }
            printf("Case #%d: %d\n", tt, res);
        }
    }

    return 0;

}
