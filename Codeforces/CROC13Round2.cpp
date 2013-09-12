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

int n;
string s,t;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>s>>t;

    int c1=0,c2=0;
    int d=0;
    for (int i=0; i<2*n; i++) {
        if (s[i]=='1' && t[i]=='0') c1++;
        else if (s[i]=='0' && t[i]=='1') c2++;
        else if (s[i]=='1' && t[i]=='1') d++;
    }
    c1 += d%2;
    if (c1>c2) {
        c1 -= (c1-c2)/2;
    }
    else if (c2>c1) {
        c2 -= (c2-c1+1)/2;
    }

    if (c1>c2) {
        cout<<"First";
    }
    else if (c2>c1) {
        cout<<"Second";
    }
    else {
        cout<<"Draw";
    }

    return 0;

}
