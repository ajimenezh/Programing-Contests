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

set<string> all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s = "ABC";
    string str;
    for (int i=0; i<3; i++) {
        cin>>str;
        all.insert(str);
    }

    do {
        bool bad = 0;
        string s1 = s.substr(0,1) + "<" + s.substr(1,1);
        if (all.find(s1)!=all.end()) bad = 1;
        s1 = s.substr(1,1) + ">" +s.substr(0,1);
        if (all.find(s1)!=all.end()) bad = 1;
        s1 = s.substr(1,1) + "<" +s.substr(2,1);
        if (all.find(s1)!=all.end()) bad = 1;
        s1 = s.substr(2,1) + ">" +s.substr(1,1);
        if (all.find(s1)!=all.end()) bad = 1;
        s1 = s.substr(0,1) + "<" +s.substr(2,1);
        if (all.find(s1)!=all.end()) bad = 1;
        s1 = s.substr(2,1) + ">" +s.substr(0,1);
        if (all.find(s1)!=all.end()) bad = 1;
        if (!bad) {
            reverse(s.begin(), s.end());
            cout<<s<<endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout<<"Impossible"<<endl;

    return 0;

}
