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
map<string,set<string> > all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    string s;
    getline(cin,s);
    for (int i=0; i<n; i++) {
        getline(cin,s);
        int last = -1;
        string str;
        for (int j=0; j<s.length(); j++) {
            if (s[j]=='<') last = j;
            else if (s[j]=='>' && last!=-1) {
                str = s.substr(last+1, j-last-1);
                if (str[0]=='/') continue;
                stringstream ss(str);
                string tag;
                ss>>tag;
                if (all.find(tag)==all.end()) all[tag] = set<string>();
                string atrib;
                while (ss>>atrib) {
                    for (int k=0; k<atrib.size(); k++) if (atrib[k]=='=') {
                        all[tag].insert(atrib.substr(0,k));
                        break;
                    }
                }
                last = -1;
            }
        }
    }

    rep(it,all) {
        cout<<(*it).first<<":";
        bool start = 0;
        rep (it2, (*it).second) {
            if (!start) start = 1;
            else cout<<",";
            cout<<(*it2);
        }
        cout<<"\n";
    }

    return 0;

}
