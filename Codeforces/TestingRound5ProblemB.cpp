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
vector<int> v[7][7];
int cnt[7];
bool vis[7];
vector<pair<int,int> > sol;

void dfs(int p) {
    vis[p] = 1;
    for (int i=0; i<7; i++) {
        if (!v[p][i].empty()) {
            int to = v[p][i].back();
            v[p][i].pop_back();
            dfs(i);
            sol.push_back(make_pair(to,1));
        }
        else if (!v[i][p].empty()) {
            int to = v[i][p].back();
            v[i][p].pop_back();
            dfs(i);
            sol.push_back(make_pair(to,-1));
        }
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[a][b].push_back(i);
        cnt[a]++;
        cnt[b]++;
    }

    int odd = 0;
    for (int i=0; i<7; i++) if (cnt[i]%2!=0) odd++;
    if (odd>2) {
        cout<<"No solution"<<endl;
        return 0;
    }
    int start = -1;
    for (int i=0; i<7; i++) if (cnt[i]%2==1) start = i;
    if (start==-1) {
        for (int i=0; i<7; i++) if (cnt[i]>0) start = i;
    }
    dfs(start);
    for (int i=0; i<7; i++) if ((cnt[i]>0 && !vis[i]) || sol.size()!=n) {
        cout<<"No solution"<<endl;
        return 0;
    }
    reverse(sol.begin(),sol.end());
    for (int i=0; i<sol.size(); i++) {
        cout<<sol[i].first+1<<" "<<(sol[i].second>0?"+":"-")<<endl;
    }

    return 0;

}
