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

int n,m;
map<string,int> id;
map<int,string> idv;
vector<pair<int,int> > v;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        id[s] = i;
        idv[i] = s;
    }
    for (int i=0; i<m; i++) {
        string s1,s2;
        cin>>s1>>s2;
        v.push_back(make_pair(id[s1],id[s2]));
    }

    int best = 0;
    int mask = 0;
    for (int i=0; i<(1<<n); i++) {
        bool good = 1;
        if (__builtin_popcount(i)<=best) continue;
        for (int j=0; j<m; j++) {
            if ((1<<(v[j].first))&i) {
                if ((1<<(v[j].second))&i) {
                    good = 0;
                    break;
                }
            }
        }
        if (good) {
            mask = i;
            best = __builtin_popcount(i);
        }
    }

    vector<string> s;
    for (int i=0; i<n; i++) {
        if ((1<<i)&mask) s.push_back(idv[i]);
    }
    sort(s.begin(),s.end());
    cout<<s.size()<<endl;
    for (int i=0; i<s.size(); i++) {
        cout<<s[i]<<endl;
    }

    return 0;

}
