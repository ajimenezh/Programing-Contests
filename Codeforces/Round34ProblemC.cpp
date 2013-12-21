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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    for (int i=0; i<s.length(); i++) if (s[i]==',') s[i]=' ';
    stringstream ss(s);
    set<int> all;
    while (ss>>s) {
        all.insert(atoi(s.c_str()));
    }

    vector<pair<int,int> > v;
    int p = -5;
    int t = -5;
    rep(it, all) {
        int k = *it;
        if (k-1!=t) {
            if (p<0) {
                p = k;
                t = p;
            }
            else {
                v.push_back(make_pair(p,t));
                p = k;
                t = k;
            }
        }
        else t = k;
    }
    v.push_back(make_pair(p,t));

    for (int i=0; i<v.size(); i++) {
        if (v[i].second==v[i].first) {
            cout<<v[i].first;
        }
        else cout<<v[i].first<<"-"<<v[i].second;
        if (i!=v.size()-1) cout<<",";
    }
    cout<<endl;

    return 0;

}
