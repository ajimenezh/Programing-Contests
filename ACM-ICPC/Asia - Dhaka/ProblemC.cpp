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

int n,k;
string s;
int cnt[300];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    for (int tt=1; tt<=t; tt++) {
        cin>>n>>k>>s;
        int ans = 0;
        for (int i=0; i<300; i++) cnt[i] = 0;
        for (int i=0; i<n; i++) {
            if (i>k) cnt[s[i-k-1]]--;
            if (cnt[s[i]]) ans++;
            cnt[s[i]]++;
        }
        printf("Case %d: %d\n",tt,ans);
    }

    return 0;

}
