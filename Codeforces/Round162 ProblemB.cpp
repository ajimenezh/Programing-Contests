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
int a[100010];
vector<int> decom[100010];
int last[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) {
        int t = a[i];
        for (int j=2; j*j<=t; j++) if (t%j==0) {
            while (t>0 && t%j==0) {
                t /= j;
            }
            decom[i].push_back(j);
        }
        if (t>1) decom[i].push_back(t);
    }

    int ans = 0;
    for (int i=0; i<n; i++) {
        int m = 0;
        for (int j=0; j<decom[i].size(); j++) {
            m = max(last[decom[i][j]],m);
        }
        ans = max(ans, m+1);
        for (int j=0; j<decom[i].size(); j++) {
            last[decom[i][j]] = m+1;
        }
    }

    cout<<ans<<endl;

    return 0;

}
