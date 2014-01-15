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

int n;

bool ady[2*26][2*26];
int vis[2*26];
bool cyc;
bool exist[2*26];

void dfs(int p) {
    if (vis[p]==2) {
        cyc = 1;
        return;
    }
    if (vis[p]==1) return;
    vis[p] = 1;
    for (int i=0; i<2*26; i++) if (ady[p][i]) {
        if (i>=26 && exist[i-26]) dfs(i-26);
        else if (i<26 && exist[i+26]) dfs(i+26);
    }
    vis[p] = 2;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    while (scanf("%d",&n)!=EOF) {
        string s;
        for (int i=0; i<2*26; i++) {
            for (int j=0; j<2*26; j++) {
                ady[i][j] = 0;
            }
        }
        for (int i=0; i<2*26; i++) exist[i] = 0;
        for (int i=0; i<n; i++) {
            cin>>s;
            vector<int> v;
            for (int j=0; j<8; j+=2) {
                if (s[j]=='0') continue;
                else {
                    int a = s[j]-'A';
                    if (s[j+1]=='-') a += 26;
                    v.push_back(a);
                    exist[a] = 1;
                }
            }
            for (int j=0; j<v.size(); j++) {
                for (int k=0; k<v.size(); k++) {
                    if (j!=k) ady[v[j]][v[k]] = 1;
                }
            }
        }

        cyc = 0;
        for (int i=0; i<2*26; i++) if (!vis[i] && exist[i]) {
            for (int j=0; j<2*26; j++) {
                vis[j] = 0;
            }
            dfs(i);
        }
        if (cyc) cout<<"unbounded"<<endl;
        else cout<<"bounded"<<endl;
    }

    return 0;

}
