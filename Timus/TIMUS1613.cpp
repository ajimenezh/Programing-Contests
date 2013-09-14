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
int v[71000];
map<int,int> id;
int cnt;
vector<int> all[70010];
vector<pair<pair<int,int> ,int> > intv[70010];
bool good[70010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",v+i);
        if (id.find(v[i])==id.end()) id[v[i]]=cnt++;
        v[i] = id[v[i]];
    }
    for (int i=0; i<n; i++) all[v[i]].push_back(i+1);
    int q;
    cin>>q;
    for (int i=0; i<q; i++) {
        int l,r,x;
        scanf("%d%d%d",&l,&r,&x);
        if (id.find(x)==id.end()) continue;
        x = id[x];
        intv[x].push_back(make_pair(make_pair(l,r),i));
    }
    for (int i=0; i<cnt; i++) {
        if (intv[i].size()>0) {
            sort(intv[i].begin(),intv[i].end());
            int j = 0;
            int k = 0;
            for (j=0; j<all[i].size(); j++) {
                while (k<intv[i].size() && all[i][j]>=intv[i][k].first.first) {
                    if (all[i][j]<=intv[i][k].first.second) good[intv[i][k].second] = 1;
                    k++;
                }
            }
        }
    }
    for (int i=0; i<q; i++) cout<<good[i];


    return 0;

}
