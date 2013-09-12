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

string f(string a, string b) {
    if (a.length()>b.length()) return a;
    if (b.length()>a.length()) return b;

    return max(a,b);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    cin>>s;
    string sol = "0";

    for (int i=0; i<s.length(); i++) if (s[i]!='0') {
        int j;
        bool done = 0;
        int p = -1;
        for (j=i; j<s.length();j++) {
            if (!(s[j]>='0' && s[j]<='9') && done) break;
            else if (!(s[j]>='0' && s[j]<='9')) {
                p = j;
                done = 1;
            }
        }
        j--;
        char tmp;
        if (p!=-1) {
            tmp = s[p];
            s[p] = '9';
        }
        string str = s.substr(i,j-i+1);
        //cout<<str<<endl;
        if (p!=-1) s[p] = tmp;
        sol = f(sol,str);
    }

    cout<<sol;

    return 0;

}
