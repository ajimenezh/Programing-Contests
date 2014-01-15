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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    string s;
    cin>>n;
    cin>>s;
    int t = 0;
    int h = 0;
    for (int i=0; i<n; i++) {
        if (s[i]=='T') t++;
        if (s[i]=='H') h++;
    }
    int ans = 1000000;
    for (int i=0; i<=n; i++) {
        int sumh = 0;
        int sumt = 0;
        for (int j=0; j<i; j++) if (s[j]=='H') sumh++;
        for (int j=i+h; j<n; j++) if (s[j]=='H') sumh++;
        ans = min(ans, sumh);
        for (int j=0; j<i; j++) if (s[j]=='T') sumt++;
        for (int j=i+t; j<n; j++) if (s[j]=='T') sumt++;
        ans = min(ans, sumt);
    }
    cout<<ans<<endl;

    return 0;

}
