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

int n,m;
int p1[101];
int t1[101];
int p2[101];
bool vis[101];
bool vis1[101];
bool vis2[101];

int greedy() {
    int tot = 0;
    while (true) {
        bool done = 0;
        int now = 0;
        int h = 0;
        for (int i=0; i<n; i++) if (!vis1[i] && t1[i]==1) {
            for (int j=0; j<m; j++) if (!vis2[j] && p2[j]>=p1[i]) {
                if (p2[j]-p1[i]>now) {
                    now = p2[j] - p1[i];
                    h = j*1000 + i;
                    done = 1;
                }
            }
        }
        if (!done) break;
        tot += now;
        vis1[h%1000] = 1;
        vis2[h/1000] = 1;
    }
    return tot;
}

int all_attack() {
    for (int i=0; i<m; i++) vis[i] = 0;
    int tot = 0;
    for (int i=0; i<n; i++) {
        int now = 1000000;
        int p = -1;
        for (int j=0; j<m; j++) if (!vis[j]) {
            if (t1[i]==1) {
                if (p2[j]>=p1[i] && p2[j]-p1[i]<now) {
                    now = p2[j]-p1[i];
                    p = j;
                }
            }
            if (t1[i]==0) {
                if (p2[j]>p1[i] && p2[j]-p1[i]<now) {
                    now = p2[j]-p1[i];
                    p = j;
                }
            }
        }
        if (now==1000000) return 0;
        vis[p] = 1;
        if (t1[i]==1) tot += now;
    }
    for (int i=0; i<m; i++) if (!vis[i]) tot += p2[i];
    return tot;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        if (s=="ATK") t1[i] = 1;
        else t1[i] = 0;
        cin>>p1[i];
    }
    for (int i=0; i<m; i++) cin>>p2[i];

    int ans1 = all_attack();
    int ans2 = greedy();

    cout<<max(ans1,ans2);

    return 0;

}
