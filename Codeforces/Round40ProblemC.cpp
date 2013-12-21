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

string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;

    for (int i=1; i<s.length()-1; i++) {
        if (s[i]=='a' && s[i+1]=='t') {
            s = s.substr(0,i) + '@' + s.substr(i+2, s.length()-i-2);
            break;
        }
    }
    for (int i=1; i<s.length()-3; i++) {
        if (s[i]=='d' && s[i+1]=='o' && s[i+2]=='t') {
            s = s.substr(0,i) + '.' + s.substr(i+3, s.length()-i-3);
        }
    }

    cout<<s;

    return 0;

}
