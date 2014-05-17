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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>


int main() {

    int x,y,a,b;
    vector<pii> v;
    cin>>x>>y>>a>>b;

    for (int i=a; i<=x; i++) {
        for (int j=b; j<min(i,y+1); j++) v.pb(mp(i,j));
    }

    cout<<v.size()<<endl;
    for (int i=0; i<v.size(); i++) cout<<v[i].first<<" "<<v[i].second<<endl;


	return 0;

}
