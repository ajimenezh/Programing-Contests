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


vector<pair<int,int> > v;
set<pair<int,int> > vis;
int x[3000010], y[3000010], r[3000010];
int n;

bool check(int a, int b) {
    if ((long long)(x[a]-x[b])*(x[a]-x[b]) + (long long)(y[a]-y[b])*(y[a]-y[b]) <= (long long)(r[a]+r[b])*(r[a]+r[b])) return true;
    return false;
}

int main() {

    int in, fn;
    string s;
    getline(cin,s);
    for (int i=0; i<s.length(); i++) if (s[i]==',') s[i] = ' ';
    stringstream ss(s);
    ss>>in>>fn;
    in--; fn = in+fn-1;

    freopen("points","r",stdin);

    while (scanf("%d%d%d", x+n, y+n, r+n)!=EOF) n++;

    v.resize(2*n);
    for (int i=0; i<n; i++) v[i] = make_pair(x[i]+r[i]+1, i);
    for (int i=0; i<n; i++) v[i+n] = make_pair(x[i]-r[i], i);
    sort(v.begin(), v.end());

    long long tot = 0;
    for (int i=0; i<v.size(); i++) {
        int t = v[i].second;
        if (t<in && t>fn) continue;
        if (vis.find(make_pair(y[t]-r[t], t))!=vis.end()) {
            vis.erase(make_pair(y[t]-r[t], t));
        }
        else {
            set<pair<int,int> >::iterator it = vis.lower_bound(make_pair(y[t]-r[t], -1));
            while ((*it).first>=y[t]-r[t]-1000) {
                if (check((*it).second, t)) tot++;
                if (it==vis.begin()) break;
                it--;
            }
            it = vis.lower_bound(make_pair(y[t]-r[t], -1));
            if (it!=vis.end()) it++;
            while (it!=vis.end() && y[t]+r[t]>=(*it).first) {
                if (check((*it).second, t)) tot++;
                it++;
            }
            vis.insert(make_pair(y[t]-r[t], t));
        }
    }

    cout<<tot<<endl;

    return 0;

}
