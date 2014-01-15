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

string s[110];
int cnt[26];

int main() {

    freopen("arrange.in","r",stdin);
    freopen("arrange.out","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) cin>>s[i];
    for (int i=0; i<n; i++) cnt[s[i][0]-'A']++;
    int ans = 0;
    for (int i=0; i<26; i++) {
        if (cnt[i]) ans++;
        else break;
    }

    cout<<ans<<endl;

    return 0;

}


