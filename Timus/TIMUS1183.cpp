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
#include <stack>

using namespace std;

#define fo(i,n) for(int i=0; i<(int)n; i++)
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXM 250000
#define MAXN 250000

int fail[MAXM];
int pref[MAXN];
int suf[MAXN];
int v[MAXN];
string s;
string p;
int n;

void kmp(string _p) {
    p = _p;
    int m = p.length();
    int cnt = fail[0] = -1;
    for (int i=1; i<=m; i++) {
        while (cnt>=0 && p[cnt] != p[i-1]) cnt = fail[cnt];
        fail[i] = ++cnt;
    }
}

int doit() {
    int m = s.length();
    for (int i=0, j=0; i<m; i++) {
        while (j>=0 && s[i]!=p[j]) j = fail[j];
        if (++j==m) {
            v[i] = m-1;
            j = fail[j];
        }
        else v[i] = j;
    }
    return -1;
}

int res = 0;
int sum[MAXM];

string t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>s;
    cin>>t;
    s = s+s;
    kmp(t);
    int i = doit();

    bool done = 0;
    for (int i=0; i<2*n; i++) if (v[i]==n) {
        int ans = n-((i+1)-n);
        if (ans==n) ans = 0;
        cout<<ans<<endl;
        done = 1;
        break;
    }
    if (!done) cout<<-1;

    return 0;

}
