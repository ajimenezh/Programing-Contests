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

bool check(int a, int b) {
    for (int i=0; i<b; i++) {
        bool good = 1;
        for (int j=0; j<a; j++) if (s[j*b + i]=='O') {
            good = 0;
            break;
        }
        if (good) return true;
    }
    return false;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        s = "";
        cin>>s;
        vector<int> v;
        for (int i=1; i<=12; i++) if (12%i==0) {
            if (check(i, 12/i)) v.push_back(i);
        }
        cout<<v.size()<<" ";
        for (int i=0; i<v.size(); i++) printf("%dx%d ", v[i], 12/v[i]);
        cout<<"\n";
    }

    return 0;

}
