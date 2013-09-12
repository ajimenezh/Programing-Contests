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

set<pair<int,int> > e;
bool vis[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=0; i<(n-1)/2+1; i++) {
        for (int j=(n-1)/2+1; j<n; j++) {
            e.insert(make_pair(i,j));
        }
    }



    cout<<e.size()<<endl;

    rep(it,e) {
        cout<<(*it).first+1<<" "<<(*it).second+1<<endl;
    }

    return 0;

}
