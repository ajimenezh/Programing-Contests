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

vector<int> e[110];
set<int> r[110];
int n;
int q[110];
int in,fn;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a;
        while (cin>>a && a!=0) {
            e[i].push_back(a-1);
            r[a-1].insert(i);
        }
    }

    for (int i=0; i<n; i++) if (r[i].size()==0) q[fn++] = i;

    while (in<fn) {
        int p = q[in++];
        cout<<p+1<<" ";
        for (int i=0; i<e[p].size(); i++) {
            r[e[p][i]].erase(p);
            if (r[e[p][i]].size()==0) q[fn++] = e[p][i];
        }
    }

    return 0;

}
