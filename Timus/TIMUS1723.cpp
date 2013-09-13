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

int _cnt(string txt, string s) {
    int res = 0;
    for (int i=0; i<txt.length()-s.length()+1; i++) {
        if (txt.substr(i,s.length())==s) res++;
    }
    return res;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    string ans;
    int best = 0;
    for (int i=0; i<s.length(); i++) {
        for (int j=1; j<=s.length()-i; j++) {
            string str = s.substr(i,j);
            if (_cnt(s,str)>best) {
                best = _cnt(s,str);
                ans = str;
            }
        }
    }
    cout<<ans;

    return 0;

}
