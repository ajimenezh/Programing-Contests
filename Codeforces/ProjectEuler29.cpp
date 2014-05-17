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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    set<vector<pair<int,int> > > all;

    int n = 100;

    for (int a=2; a<=n; a++) {
        vector<pair<int,int> > v;
        int t = a;
        for (int j=2; j*j<=t; j++) if (t%j==0) {
            int k = 0;
            while (t%j==0) {k++; t/=j;}
            v.push_back(make_pair(j,k));
        }
        if (t>1) v.push_back(make_pair(t,1));
        for (int j=2; j<=n; j++) {
            vector<pair<int,int> > w = v;
            for (int k=0; k<w.size(); k++) w[k].second *= j;
            all.insert(w);
        }
    }

    cout<<all.size()<<endl;

    return 0;

}
