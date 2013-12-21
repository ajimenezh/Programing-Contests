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

int n,m,k;
set<pair<int,int> > all;
bool done;
int a[310];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<k; i++) {
        int t;
        cin>>t;
        a[i] = t-1;
    }
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) if (j!=i) {
            all.insert(make_pair(min(i,j),max(i,j)));
        }
    }

    for (int i=1; i<k; i++) {
        all.erase(make_pair(min(a[0],a[i]),max(a[0],a[i])));
    }


    if (m>all.size()) {
        cout<<-1;
        return 0;
    }

    rep(it,all) {
        if (m==0) break;
        m--;
        cout<<(*it).first+1<<" "<<(*it).second+1<<endl;
    }

    return 0;

}
