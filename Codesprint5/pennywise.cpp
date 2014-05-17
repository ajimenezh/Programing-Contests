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

int v[20], w[20];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    int t;
    cin>>t;
    cin>>n>>m;
    for (int i=0; i<n; i++) cin>>v[i];
    for (int j=0; j<m; j++) cin>>w[j];
    sort(v,v+n);
    sort(w,w+m);

    int k = v[0];
    vector<int> p;
    for (int i=0; i<n; i++) {
        int sum = 0;
        int j = 0;
        int tot = 0;
        vector<int> tmp;
        while (j<m && sum+w[j]<v[i]) {
            sum += w[j];
            tmp.push_back(w[j]);
            tot++;
            j++;
        }
        if (tmp.size()>p.size()) {
            p = tmp;
            k = v[i];
        }
    }

    cout<<k<<" "<<p.size()<<endl;
    for (int i=0; i<p.size(); i++) cout<<p[i]<<" "; cout<<endl;

    return 0;

}
