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

int n,m;
set<int> r[1100];
vector<int> e[1100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m;
    for (int i=0; i<m; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        e[a].push_back(b);
        r[b].insert(a);
    }
    bool good = 1;
    for (int i=0; i<n; i++) {
        int a;
        scanf("%d",&a);
        if (r[a].size()!=0) good = 0;
        else {
            for (int j=0; j<e[a].size(); j++) {
                r[e[a][j]].erase(a);
            }
        }
    }

    cout<<(good?"YES":"NO")<<endl;

    return 0;

}
