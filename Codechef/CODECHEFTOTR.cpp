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
string su;
bool letter(char c) {
    if (c>='a' && c<='z') return true;
    if (c>='A' && c<='Z') return true;
    if (c=='_') return true;
    return false;
}
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    cin>>s;
    su = s;
    for (int i=0; i<s.length(); i++) {
        su[i] = char(s[i]-'a' + 'A');
    }
    for (int t=0; t<tt; t++) {
        string m;
        cin>>m;
        for (int i=0; i<m.length(); i++) {
            if (!letter(m[i])) cout<<m[i];
            else {
                if (m[i]=='_') cout<<' ';
                else {
                    if (m[i]>='A' && m[i]<='Z') {
                        cout<<su[m[i]-'A'];
                    }
                    else cout<<s[m[i]-'a'];
                }
            }
        }
        cout<<endl;
    }

    return 0;

}
