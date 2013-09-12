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

int l[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
string s;
map<string,int> ms;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;

    for (int i=0; i<s.length()-9; i++) {

        if (s[i+2]!='-' || s[i+5]!='-') continue;
        if (s[i+3]=='-' || s[i+4]=='-') continue;
        if (s[i+6]=='-' || s[i+7]=='-') continue;
        if (s[i+8]=='-' || s[i+9]=='-') continue;
        if (s[i]=='-' || s[i+1]=='-') continue;

        int b = (s[i+3]-'0')*10 + (s[i+4]-'0');
        if (b>12 || b==0) continue;

        int a = (s[i]-'0')*10 + (s[i+1]-'0');
        if (a==0 || a>l[b-1]) continue;

        int c = (s[i+6]-'0')*1000 +(s[i+7]-'0')*100;
        c += (s[i+8]-'0')*10 + (s[i+9]-'0');

        if (c>2015 || c<2013) continue;

        if (ms.find(s.substr(i,10))==ms.end())
            ms[s.substr(i,10)] = 1;
        else
            ms[s.substr(i,10)]++;
        //cout<<s.substr(i,10)<<endl;
    }

    int m = 0;
    string sol;
    rep(it,ms) {
        if ((*it).second>m) {
            m = (*it).second;
            sol = (*it).first;
        }
    }

    cout<<sol;

    return 0;

}
