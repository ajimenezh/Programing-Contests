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

int n;
pair<int,int> x[100010];
map<pair<int,int> ,int> m;
vector<pair<int,int> > v;
int f[100010];
int res[100010];

int rec(int i) {
    if (i>=n) return 0;
    if (f[i]!=-1) return f[i];

    vector<pair<int,int> >::iterator it1, it2;

    it1 = lower_bound(v.begin(),v.end(),make_pair(x[i].first+1,-1));
    it2 = lower_bound(v.begin(),v.end(),make_pair(x[i].first+x[i].second-1,-1));

    int sol;

    if (it1==it2) {
        if (it2!=v.end()) {
            if ((*it2).first == x[i].first+x[i].second-1)
                sol = 1 + rec((*it2).second);
            else
                sol = 1;
        }
        else sol = 1;
    }
    else if ((it2)!=v.end() && (*it2).first>x[i].first+x[i].second-1) {
        sol = 1 + (it2 - it1) - 1 + rec((*it2).second);
    }
    else if ((it2)==v.end()) {
        sol = 1 + (it2-it1);
    }
    else {
        int t = (it2 - it1);
        it2++;
        if ((it2)!=v.end()) sol = 1 + t + rec((*it2).second);
        else sol = 1 + t;
    }

    f[i] = sol;

    return sol;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d%d",&x[i].first,&x[i].second);
    for (int i=0; i<n; i++) m[x[i]] = i;
    sort(x,x+n);
    for (int i=0; i<n; i++) v.push_back(make_pair(x[i].first,i));
    for (int i=0; i<n; i++) f[i] = -1;
    for (int i=0; i<n; i++) if (f[i]==-1) rec(i);
    for (int i=0; i<n; i++) res[m[x[i]]] = f[i];
    for (int i=0; i<n; i++) printf("%d ",res[i]);

    return 0;

}
