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

map<pair<string,string>,set<pair<string,string> > > edges;
set<string> roots;

void dfs(pair<string,string> s, int t) {
    for (int i=0; i<t; i++) cout<<" ";
    cout<<s.first;
    cout<<endl;
    rep(it,edges[s]) {
        dfs(*it,t+1);
    }
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        string s;
        cin>>s;
        for (int j=0; j<s.length(); j++) if  (s[j]=='\\') s[j] = ' ';
        stringstream ss(s);
        vector<string> vs;
        while (ss>>s) {
            vs.push_back(s);
        }
        string str = "";
        for (int j=0; j<vs.size()-1; j++) {
            edges[make_pair(vs[j],str)].insert(make_pair(vs[j+1],str+"\\"+vs[j]));
            str += "\\";
            str += vs[j];
        }
        roots.insert(vs[0]);
    }

    rep(it,roots) {
        dfs(make_pair(*it,""),0);
    }

    return 0;

}
