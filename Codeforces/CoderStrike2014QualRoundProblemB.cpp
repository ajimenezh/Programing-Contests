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

int cnt[110];
int locked[110];
vector<int> all[110];
bool lc[110];
int ins[110][110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;
    for (int i=0; i<n; i++) for (int j=0; j<m; j++) scanf("%d", &ins[i][j]);

    for (int i=0; i<m; i++) {
        for (int j=0; j<=k; j++) cnt[j] = 0;
        for (int j=0; j<=k; j++) all[j].clear();
        for (int j=0; j<n; j++) {
            int a = ins[j][i];
            if (!locked[j] && lc[a] && a>0) {
                locked[j] = i+1;
            }
            if (!locked[j] && a>0) {
                cnt[a]++;
                all[a].push_back(j);
            }
        }
        for (int j=0; j<=k; j++) if (cnt[j]>1) {
            lc[j] = 1;
            for (int t=0; t<all[j].size(); t++) locked[all[j][t]] = i+1;
        }
    }
    for (int i=0; i<n; i++) cout<<locked[i]<<"\n";

    return 0;

}
