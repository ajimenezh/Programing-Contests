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

string s;
int c1, c2, c;
set<string> res;

void solve(int a, int b, int i) {
    int n = s.length();
    if ((n%2==0 && a==b) || (n%2!=0 && b-1==a)) {
        if (s[n-2]=='?') {
            if (s[n-1]=='?') {
                if (c-i>=2) res.insert("11");
                if (c-i>=1) res.insert("01");
                if (c-i>=2) res.insert("10");
                if (i>=2) res.insert("00");
            }
            else {
                if (c-i>=1) res.insert("1"+s.substr(n-1,1));
                if (i>=1) res.insert("0"+s.substr(n-1,1));
                if (n%2!=0 && b-1==a && s[n-1]=='1') {
                    if (i>=2) res.insert("00");
                }
            }
        }
        else {
            if (s[n-1]=='?') {
                if (i>=1) res.insert(s.substr(n-2,1)+"0");
                if (c-i>=1) res.insert(s.substr(n-2,1)+"1");
                if (n%2!=0 && b-1==a && s[n-2]=='1') {
                    if (b>=2 && c-i>=1) res.insert("01");
                }
            }
            else {
                res.insert(s.substr(n-2,2));
            }
        }
    }
    else {
        if (a>b) {
            res.insert("00");
        }
        else {
            res.insert("11");
        }
    }
    return;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    c = 0;
    c1 = 0;
    c2 = 0;

    for (int i=0; i<s.length(); i++) {
        if (s[i]=='0') c1++;
        if (s[i]=='1') c2++;
        if (s[i]=='?') c++;
    }

    for (int i=0; i<=c; i++) {
        solve(c1+i,c2+c-i,i);
        if (res.size()==4) break;
    }

    rep(it,res) cout<<(*it)<<endl;

    return 0;

}
