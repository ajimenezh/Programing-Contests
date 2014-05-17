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

int cntL[2000010];
int cntR[2000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int x = 0, m = 0, t = 0;
    int pt = 0, pm = 0;

    string s;
    cin>>s;

    int n = s.length();

    for (int i=0; i<n; i++) {
        if (s[i]=='R') {
            x++;
            cntR[x+1000000] = 1 - cntR[x+1000000];
        }
        else {
            x--;
            cntL[x+1000000] = 1 - cntL[x+1000000];
        }
        if (x<t) {
            t = x;
            pt = 0;
        }
        else if (t==x) {
            pt++;
        }
        if (x>m) {
            m = x;
            pm = 0;
        }
        else if (m==x) {
            pm++;
        }
    }

    if (pm==0 && x==m) {
        cout<<1;
        return 0;
    }
    if (pt==0 && x==t) {
        cout<<1;
        return 0;
    }

    int tot = 0;
    int p = x;
    for (int i=m; i>0; i--) {
        x -= cntR[i+1000000];
        if (x<t) tot++;
    }
    x = p;
    for (int i=t; i<0; i++) {
        x += cntL[i+1000000];
        if (x>m) tot++;
    }

    cout<<tot<<endl;

    return 0;

}
