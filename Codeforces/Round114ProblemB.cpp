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

bool isa(string s) {
    for (int i=0; i<s.length(); i++) {
        if (s[i]!=' ') {
            if (s[i]=='#') return true;
            return false;
        }
    }
    return false;
}

string f(string s) {
    string s2;
    for (int i=0; i<s.length(); i++) {
        if (s[i]!=' ' && s[i]!='\n') s2 += s[i];
    }
    if (s2[s2.length()-1]=='\n') s2 = s2.substr(0,s2.length()-1);
    return s2;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    vector<string> vs;
    string s;
    while (getline(cin,s)) vs.push_back(s);

    vector<string> ans;
    string str;
    bool done = 0;
    for (int i=0; i<vs.size(); i++) {
        if (isa(vs[i])) {
            if (done) ans.push_back(str);
            str = "";
            done = 0;
            ans.push_back(vs[i]);
        }
        else {
            if (vs[i]!="" && vs[i][0]!='\n') str += f(vs[i]);
            done = 1;
        }
    }
    if (done) ans.push_back(str);

    for (int i=0; i<ans.size(); i++) {
        if (i!=ans.size()-1) cout<<ans[i]<<"\n";
        else cout<<ans[i]<<endl;
    }

    return 0;

}
