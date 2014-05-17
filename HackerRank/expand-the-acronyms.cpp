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

map<string,string> all;
set<string> badUpper;
set<string> goodDown;

string bad[] = {"The","A","If","What","Who","I", "I'm", "He","You", "We", "They", "Where", "How"};
string good[] = {"of"};

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    string s;
    getline(cin,s);
    for (int i=0; i<13; i++) badUpper.insert(bad[i]);
    for (int i=0; i<1; i++) goodDown.insert(good[i]);
    for (int i=0; i<n; i++) {
        getline(cin,s);
        stringstream ss(s);
        vector<string> vs;
        while (ss>>s) {
            if (s[0]>='A' && s[0]<='Z') {
                if (badUpper.find(s)!=badUpper.end()) {
                    if (vs.size()==0) continue;
                    string name;
                    string full;
                    for (int j=0; j<vs.size(); j++) {
                        if (vs[j][0]>='A' && vs[j][0]<='Z') name += vs[j][0];
                        if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]==',') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]==';') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='?') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='!') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        full = full + vs[j] + " ";
                    }
                    full = full.substr(0,full.length()-1);
                    if (s[0]=='(') name = s.substr(1,s.length()-2);
                    all[name] = full;
                    vs.clear();
                }
                else {
                    vs.push_back(s);
                    if (s[s.length()-1]==',' || s[s.length()-1]=='.') {
                        if (vs.size()==0) continue;
                        string name;
                        string full;
                        for (int j=0; j<vs.size(); j++) {
                            if (vs[j][0]>='A' && vs[j][0]<='Z') name += vs[j][0];
                            if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            if (vs[j][vs[j].length()-1]==',') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            if (vs[j][vs[j].length()-1]==';') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            if (vs[j][vs[j].length()-1]=='?') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            if (vs[j][vs[j].length()-1]=='!') vs[j] = vs[j].substr(0,vs[j].length()-1);
                            full = full + vs[j] + " ";
                        }
                        full = full.substr(0,full.length()-1);
                        if (s[0]=='(') name = s.substr(1,s.length()-2);
                        all[name] = full;
                        vs.clear();
                    }
                }
            }
            else {
                if (goodDown.find(s)!=goodDown.end()) {
                    vs.push_back(s);
                }
                else {
                    if (vs.size()==0) continue;
                    string name;
                    string full;
                    for (int j=0; j<vs.size(); j++) {
                        if (vs[j][0]>='A' && vs[j][0]<='Z') name += vs[j][0];
                        if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]==',') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]==';') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='.') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='?') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        if (vs[j][vs[j].length()-1]=='!') vs[j] = vs[j].substr(0,vs[j].length()-1);
                        full = full + vs[j] + " ";
                    }
                    full = full.substr(0,full.length()-1);
                    if (s[0]=='(') name = s.substr(1,s.length()-2);
                    all[name] = full;
                    vs.clear();
                }
            }
        }
    }



    for (int i=0; i<3; i++) {
        getline(cin,s);
        string str = all[s];
        if (str=="") str = "hello world";
        cout<<str<<"\n";
    }

    return 0;

}
