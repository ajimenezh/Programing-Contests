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

string s1,s2;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s1>>s2;
    if (s1.length()!=s2.length()) {cout<<"NO"; return 0;}
    bool c1 = 0,c2 = 0;
    for (int i=0; i<s1.length(); i++) {
        c1 += s1[i]=='1';
        c2 += s2[i]=='1';
    }
    if ((c1>0 && c2>0) || (c1==0 && c2==0)) {
        cout<<"YES";
    }
    else {cout<<"NO"; return 0;}

    return 0;

}
