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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    string s;
    cin>>m; getline(cin,s);
    getline(cin,s);
    n = s.length();
    vector<int> fn, in;
    int p = -1;
    for (int i=0; i<n; i++) {
        if (p==-1) {
            if (s[i]!=' ') {
                p = i;
                in.push_back(i);
            }
        }
        if (s[i]=='.' || s[i]=='?' || s[i]=='!') {
            fn.push_back(i);
            p = -1;
        }
    }

    int k = 0;
    int i = 0;
    while (i<in.size()) {
        int j = i;
        while (j<in.size() && fn[j]-in[i]+1<=m) {
            j++;
        }
        if (j==i) {
            cout<<"Impossible";
            return 0;
        }
        i = j;
        k++;
    }

    cout<<k<<endl;

    return 0;

}
