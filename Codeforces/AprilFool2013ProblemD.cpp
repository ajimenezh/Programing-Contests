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

char upper(char a) {
    if (a>='A' && a<='Z') return a;
    return char(a-'a'+'A');
}
char lower(char a) {
    if (a>='a' && a<='z') return a;
    return char(a-'A'+'a');
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    int a;
    cin>>s;
    cin>>a;

    string str;

    for (int i=0; i<s.length(); i++) s[i] = lower(s[i]);

    for (int i=0; i<s.length(); i++) {
        char b = s[i];
        if (b<a+97) {
            str += upper(b);
        }
        else {
            str += lower(b);
        }
    }

    cout<<str;

    return 0;

}
