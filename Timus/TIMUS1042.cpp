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
int m[151][151];
int v[151];
set<int> s[151];
set<int> sol;
bool vis[151];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        while (cin>>a && a!=-1) {
            m[i][a-1] = 1;
        }
        s[i].insert(i+1);
    }

    for (int i=0;i<n; i++) {
        for (int j=i+1; j<n; j++) {
            if (m[j][i]==1 && m[i][i]==1) {
                for (int k=0; k<n; k++) {
                    m[j][k] ^= m[i][k];
                }
                cout<<"what"<<i<<" "<<j<<endl;
                if (s[j].find(i+1)==s[j].end()) s[j].insert(i+1);
                else s[j].erase(i+1);
            }
        }
    }

    for (int i=0; i<n; i++) {for (int j=0; j<n; j++) cout<<m[i][j]<<" "; cout<<endl;}

    for (int i=0; i<n; i++) if (!v[i]) {
        bool good = 1;
        rep(it,s[i]) if (v[*it-1]) good = false;
        if (!good) continue;
        for (int j=0; j<n; j++) v[j] ^= m[i][j];
        rep(it,s[i]) v[*it-1] = 1;
        rep(it,s[i]) sol.insert(*it);
    }

    bool all = 1;
    for (int i=0; i<n; i++) if (!v[i]) all = 0;

    if (!all) {
        cout<<"No solution";
    }
    else {
        rep(it,sol) cout<<*it<<" ";
    }

    return 0;

}
