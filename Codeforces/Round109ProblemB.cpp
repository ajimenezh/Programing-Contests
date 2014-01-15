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
vector<int> pr[100010];
bool isprime[100010];
bool vis[100010];
set<int> last[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<=n; i++) isprime[i] = 1;
    for (int i=2; i<=n; i++) if (isprime[i]) {
        pr[i].push_back(i);
        for (int j=2*i; j<=n; j+=i) pr[j].push_back(i);
    }
    for (int i=1; i<=n; i++) vis[i] = 0;
    for (int i=0; i<m; i++) {
        char c;
        scanf("%s",&c);
        if (c=='+') {
            int x;
            scanf("%d",&x);
            bool done = 0;
            if (!vis[x]) {
                for (int j=0; j<pr[x].size(); j++) {
                    if (!done && last[pr[x][j]].size()>0) {
                        cout<<"Conflict with "<<(*last[pr[x][j]].begin())<<"\n";
                        done = 1;
                    }
                }
                for (int j=0; j<pr[x].size(); j++) {
                    if (!done) {
                        last[pr[x][j]].insert(x);
                    }
                }
                if (!done) vis[x] = 1;
                if (!done) cout<<"Success\n";
            }
            else {
                cout<<"Already on\n";
            }
        }
        else {
            int x;
            scanf("%d",&x);
            if (!vis[x]) cout<<"Already off\n";
            else {
                for (int j=0; j<pr[x].size(); j++) {
                    last[pr[x][j]].erase(x);
                }
                vis[x] = 0;
                cout<<"Success\n";
            }
        }
    }

    return 0;

}
