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

int n,t;
int x[1100], a[1100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>t;
    for (int i=0; i<n; i++) cin>>x[i]>>a[i];
    vector<int> v;
    for (int i=0; i<n; i++) {
        v.push_back(2*x[i]-a[i]);
        v.push_back(2*x[i]+a[i]);
    }
    sort(v.begin(),v.end());

    int res = 2;
    for (int i=1; i<v.size()-1; i+=2) {
        int h = v[i+1]-v[i];
        if (h==2*t) res++;
        else if (h>2*t) res+=2;
    }
    cout<<res<<endl;

    return 0;

}
