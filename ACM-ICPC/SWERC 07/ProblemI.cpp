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

#define MAXN 1000+5

int n;
int woman[MAXN][MAXN];
int man[MAXN][MAXN];
vector<int> pref[MAXN];
int ind[MAXN];
bool vis[MAXN];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n;
        for (int i=0; i<n; i++) vis[i] = 0;
        for (int i=0; i<n; i++) ind[i] = 0;
        for (int i=0; i<n; i++) pref[i].clear();
        for (int i=0; i<n; i++) {
            int c;
            for (int j=0; j<n; j++) {
                scanf("%d",&c);
                man[i][j] = c-1;
            }
        }
        for (int i=0; i<n; i++) {
            int c;
            for (int j=0; j<n; j++) {
                scanf("%d",&c);
                woman[i][c-1] = j;
            }
        }

        while (true) {
            for (int i=0; i<n; i++) if (!vis[i]) pref[man[i][ind[i]]].push_back(i);

            for (int i=0; i<n; i++) {
                int p = -1;;
                int best = 1005;
                for (int j=0; j<pref[i].size(); j++) if (woman[i][pref[i][j]]<best) {
                    p = pref[i][j];
                    best = woman[i][pref[i][j]];
                }
                if (p==-1) continue;
                for (int j=0; j<pref[i].size(); j++) if (pref[i][j]!=p) {ind[pref[i][j]]++; vis[pref[i][j]] = 0;}
                pref[i].clear();
                pref[i].push_back(p);
                vis[p] = 1;

            }

            bool done = 1;
            for (int i=0; i<n; i++) if (!vis[i]) done = 0;
            if (done) break;
        }

        vector<pair<int,int> > v;
        for (int i=0; i<n; i++) v.push_back(make_pair(pref[i][0]+1,i+1));
        sort(v.begin(),v.end());
        for (int i=0; i<n; i++) {
            printf("%d\n",v[i].second);
        }
        if (t!=0) printf("\n");
    }


    return 0;

}
