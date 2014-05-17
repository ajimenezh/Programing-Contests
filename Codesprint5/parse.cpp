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

    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    string s;

    if (true) {

        cout<<"{";
        bool first = 0;
        while (getline(cin,s)) {
            if (first) cout<<",";
            cout<<"\""<<s<<"\"";
            first = 1;
        }

        cout<<",\"\"}";
    }
    else {
        while (getline(cin,s)) {
            stringstream ss(s);
            ss>>s;
            for (int i=0; i<s.length(); i++) if (s[i]=='[' || (s[i]>='0' && s[i]<='9')) {
                s = s.substr(0,i);
                break;
            }
            cout<<s<<endl;
        }
    }



    return 0;

}
