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

    int n;
    cin>>n;
    pair<int,int> v[100];
    for (int i=0; i<n; i++) cin>>v[i].first<<" "<<v[i].second;
    int c[7];
    for (int i=0; i<7; i++) c[i] = 0;
    for (int i=0; i<n; i++) c[v[i].first]++;
    for (int i=0; i<n; i++) c[v[i].second]--;
    int t = 0;
    for (int i=0; i<7; i++) t += abs(c[i]);
    if (t>1) cout<<"No solution";
    int p = 0;
    bool sign = 0;
    vector<pair<int,char> > v;
    for (int i=0; i<n; i++) {
        if (c[v[i].first]!=0) {
            p = i;
            break;
        }
        else if (c[v[i].second]!=0) {
            p = i;
            sign = 1;
            break;
        }
    }
    v.push_back(make_pair(i+1,(sign?'-':'+')));
    bool vis[101];
    for (int i=0; i<n; i++) vis[i] = 0;
    vis[p] = 1;
    int cur = v[p].second;
    if (sign) cur = v[p].first;
    for (int i=1; i<n-1; i++) {
        int q = 0;
        bool sgn = 0;
    }


    return 0;

}
