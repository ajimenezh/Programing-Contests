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
string name[110];
set<string> all[110];

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    cin>>n;
    string s;
    getline(cin,s);
    for (int i=0; i<n; i++) {
        getline(cin,s);
        stringstream ss(s);
        ss>>s;
        name[i] = s;
        while (ss>>s) {
            for (int k=0; k<s.length(); k++) {
                if (s[k]>='A' && s[k]<='Z') s[k] = char('a' + s[k] - 'A');
            }
            all[i].insert(s);
        }
    }
    while (getline(cin,s)) {
        for (int k=0; k<s.length(); k++) {
            if (s[k]==',') s[k] = ' ';
            if (s[k]=='.') s[k] = ' ';
            if (s[k]=='!') s[k] = ' ';
            if (s[k]=='?') s[k] = ' ';
            if (s[k]==')') s[k] = ' ';
            if (s[k]=='(') s[k] = ' ';
        }
        for (int k=0; k<s.length(); k++) {
            if (s[k]>='A' && s[k]<='Z') s[k] = char('a' + s[k] - 'A');
        }
        stringstream ss(s);
        bool done = 0;
        while (ss>>s) {
            for (int i=0; i<n; i++) {
                if (all[i].find(s)!=all[i].end()) {
                    cout<<name[i]<<endl;
                    done = 1;
                    break;
                }
            }
            if (done) break;
        }
    }

    return 0;

}
