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

int n,m,k;
vector<int> e[100010];
set<pair<int,int> > cur;
vector<pair<int,int> > ans;
bool done;

void dfs(int p, int t) {
    //cout<<p<<endl;
    cur.insert(make_pair(p,t));
    //rep(it,cur) cout<<(*it).first<<" "<<(*it).second<<endl;
    for (int i=0; i<e[p].size(); i++) {
        int u = e[p][i];
        //cout<<p<<" "<<u<<endl;
        set<pair<int,int> >::iterator it = lower_bound(cur.begin(),cur.end(), make_pair(u,-1));
        if (it!=cur.end() && (*it).first==u) {
            int c = (*it).second;
            if (t-c>=k) {
                rep(it,cur) {
                    if ((*it).second>=c) ans.push_back(make_pair((*it).second,(*it).first));
                }
                done = 1;
                return;
            }
        }
    }
    if (done) return;
    int tot = 0;
    while(true) {
        int u = e[p][rand()%e[p].size()];
        tot++;
        //cout<<p<<" "<<u<<endl;
        set<pair<int,int> >::iterator it = lower_bound(cur.begin(),cur.end(), make_pair(u,-1));
        if (it!=cur.end() && (*it).first==u) {
        }
        else {
            dfs(u,t+1);
            break;
        }
        if (done) return;
        if (tot>2*k) break;
    }
    cur.erase(make_pair(p,t));
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        a--; b--;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    while (!done) dfs(rand()%n, 0);
    sort(ans.begin(),ans.end());
    cout<<ans.size()<<endl;
    for (int i=0; i<ans.size(); i++) cout<<ans[i].second+1<<" ";

    return 0;

}
