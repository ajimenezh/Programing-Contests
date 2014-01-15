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
vector<pair<int,int> > qe[1000010];
vector<int> sol[10000010];
int q;
int v[1000010];
int next[1000010];
map<int,int> last;
bool rep[1000010];
set<pair<int,int> > pos;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (cin>>n>>q && n!=0) {
        for (int i=0; i<n; i++) scanf("%d",v+i);
        for (int i=0; i<n; i++) {
            next[i] = n+1;
            rep[i] = 0;
        }
        last.clear();
        pos.clear();
        for (int i=0; i<n; i++) {
            if (last.find(v[i])==last.end()) {
                last[v[i]] = i;
            }
            else {
                next[last[v[i]]] = i;
                if (!rep[last[v[i]]]) pos.insert(make_pair(i,v[i]));
                last[v[i]] = i;
                rep[i] = 1;
            }
        }
        for (int i=0; i<n; i++) qe[i].clear();
        for (int i=0; i<q; i++) {
            int l,r;
            scanf("%d%d",&l,&r);
            l--;
            r--;
            qe[l].push_back(make_pair(r,i));
            sol[i].clear();
        }
        for (int i=0; i<n; i++) sort(qe[i].begin(),qe[i].end());

        for (int i=0; i<n; i++) {
            set<pair<int,int> >::iterator it = pos.begin();
            vector<int> tmp;
            for (int j=0; j<qe[i].size(); j++) {
                while (tmp.size()==0 && it!=pos.end() && (*it).first<=qe[i][j].first) {
                    tmp.push_back((*it).second);
                    it++;
                }
                sol[qe[i][j].second] = tmp;
            }

            if (next[i]==n+1) continue;
            else {
                int ne = next[i];
                if (next[ne]==n+1) {
                    rep[ne] = 0;
                    pos.erase(make_pair(ne,v[ne]));
                }
                else {
                    rep[ne] = 0;
                    pos.erase(make_pair(ne,v[ne]));
                    pos.insert(make_pair(next[ne],v[ne]));
                }
            }
        }

        for (int i=0; i<q; i++) {
            if (sol[i].size()==0) cout<<"OK\n";
            else {
                for (int j=0; j<sol[i].size(); j++) {
                    cout<<sol[i][j]<<" ";
                }
                cout<<"\n";
            }
        }
        cout<<"\n";
    }

    return 0;

}
