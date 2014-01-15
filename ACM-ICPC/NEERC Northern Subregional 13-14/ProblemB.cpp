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
string names[12];
pair<int,int> cnt[12];

int main() {

    freopen("bad.in","r",stdin);
    freopen("bad.out","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>names[i];
    for (int i=0; i<=n; i++) cnt[i].second = i;
    names[n] = "Invalid";
    for (int i=0; i<m; i++) {
        string s;
        cin>>s;
        int c = 0;
        for (int j=0; j<s.length(); j++) if (s[j]=='X') c++;
        if (c!=1) cnt[n].first--;
        else {
            for (int j=0; j<s.length(); j++) {
                if (s[j]=='X') {
                    cnt[j].first--;
                }
            }
        }
    }
    sort(cnt,cnt+n);

    for (int i=0; i<=n; i++) {
        cout<<names[cnt[i].second]<<" ";
        printf("%.2lf%%\n",(double)-cnt[i].first*100.0/m);
    }

    return 0;

}
