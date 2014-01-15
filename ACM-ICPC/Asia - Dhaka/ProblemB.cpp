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

vector<int> e[30];
string s;
int k;
int deg[30];

void dfs(char c) {
    while (s[k]!=c) {
        e[c-'A'].push_back(s[k]-'A');
        dfs(s[k++]);
    }
    k++;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        cin>>s;
        for (int i=0; i<30; i++) e[i].clear();
        for (int i=0; i<30; i++) deg[i] = 0;
        k = 1;
        dfs(s[0]);
        for (int i=0; i<26; i++) {
            for (int j=0; j<e[i].size(); j++) {
                deg[i]++;
                deg[e[i][j]]++;
            }
        }
        printf("Case %d\n",t);
        for (int i=0; i<26; i++) if (deg[i]!=0) {
            cout<<char(i+'A')<<" = "<<deg[i]<<"\n";
        }
    }

    return 0;

}
