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

vector<int> e[110];
int a[110];
int b[110];
int n;
bool border[110];
int sum = 0;

bool check(int x) {
    set<pair<int,int> > all;
    for (int i=0; i<n; i++) b[i] = a[i];

    for (int i=0; i<n; i++) if (border[i]) {
        b[i] -= x;
        if (b[i]<0) all.insert(make_pair(b[i],i));
    }

    while (!all.empty()) {
        int p = (*all.begin()).second;
        all.erase(all.begin());
        bool done = 0;
        for (int j=0; j<e[p].size(); j++) {
            int i = e[p][j];
            if (b[i]>0) {
                int tmp = min(-b[p],b[i]);
                b[p] += tmp;
                b[i] -= tmp;
                done = 1;
                if (!border[i]&&b[i]==0) {
                    b[i] = -1;
                    all.insert(make_pair(b[i],i));
                }
            }
            if (b[p]==0) break;
        }
        if (!done) break;
        if (b[p]<0) {
            all.insert(make_pair(b[p],p));
        }
    }

    for (int i=0; i<n; i++) if (b[i]<0)  return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>a[i];
        for (int i=0; i<n; i++) border[i] = 0;
        for (int i=0; i<n; i++) e[i].clear();
        for (int i=0; i<n; i++) {
            string s;
            cin>>s;
            if (a[i]==0) continue;
            for (int j=0; j<n; j++) if (s[j]=='Y') {
                if (a[j]!=0) e[i].push_back(j);
                else border[i] = 1;
            }
        }

        int lo = 1;
        int hi = 10000;

        while (lo<hi) {
            int mi = (lo+hi)>>1;
            if (check(mi)) lo = mi+1;
            else hi = mi;
        }

        cout<<lo-1<<endl;
    }

    return 0;

}
