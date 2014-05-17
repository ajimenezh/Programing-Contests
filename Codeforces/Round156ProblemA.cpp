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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n;
int a[4001];
set<int> s;
map<int,vector<pair<int,int> > > m;
map<int,int> un;

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];
    for (int i=0; i<n; i++) s.insert(a[i]);
    forit(it,s) {
        vector<pair<int,int> > v;
        forit(it,s) v.push_back(make_pair(*it,0));
        sort(v.begin(),v.end());
        m[*it] = v;
    }
    for (int i=0; i<n; i++) {
        int k = a[i];
        for (int j=0; j<m[k].size(); j++) {
            if (m[k][j].second%2==0) m[k][j].second++;
        }
        forit(it,m) {
            vector<pair<int,int> >::iterator it2 = lower_bound((*it).second.begin(),(*it).second.end(),make_pair(k,0));
            if ((*it2).second%2!=0) (*it2).second++;
        }
    }
    int res = 0;
    forit(it,s) {
        for (int j=0; j<m[*it].size(); j++) {
            //cout<<*it<<" "<<m[*it][j].first<<" "<<m[*it][j].second<<endl;
            if (m[*it][j].first != *it) res = max(res,m[*it][j].second);
        }
    }

    forit(it,s) un[*it] = 0;
    for (int i=0; i<n; i++) un[a[i]]++;
    forit(it,s) res = max(res,un[*it]);

    cout<<res<<endl;

	return 0;

}
