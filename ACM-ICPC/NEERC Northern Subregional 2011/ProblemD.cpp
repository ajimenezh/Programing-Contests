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
pair<int,int> a[1001];
vector<int> v[1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    int m = 0;
    for (int i=0; i<n; i++) {
        int c;
        cin>>c;
        a[i] = make_pair(c,i);
        m += c;
    }
    sort(a,a+n);

    for (int i=0; i<n; i++) {
        for (int j=0; j<a[i].first; j++) v[a[i].second].push_back(m--);
    }

    double e = 0.0;

    for (int i=0; i<n; i++) {
        for (int j=0; j<v[i].size(); j++) e += 1.0*v[i][j] / (double)v[i].size();
    }

    printf("%.5lf\n",e);
    for (int i=0; i<n; i++) {
        sort(v[i].begin(),v[i].end());
        for (int j=0; j<v[i].size(); j++) {
            if (j==v[i].size()-1) cout<<v[i][j]<<"\n";
            else cout<<v[i][j]<<" ";
        }
    }

    return 0;

}
