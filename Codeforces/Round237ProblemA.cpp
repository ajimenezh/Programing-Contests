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
string s[301];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>s[i];

    set<char> all;

    for (int i=0; i<n; i++) {
        all.insert(s[i][i]);
        all.insert(s[i][n-i-1]);
    }

    if (all.size()>1) {
        cout<<"NO";
        return 0;
    }

    all.clear();

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (i!=j && j!=n-i-1) all.insert(s[i][j]);
        }
    }

    if (all.size()>1) {
        cout<<"NO";
        return 0;
    }
    else {
        if (s[0][0]!=s[0][1]) cout<<"YES";
        else cout<<"NO";
    }

    return 0;

}
