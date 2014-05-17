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

int n,k,x;
vector<int> c;

int rec(vector<int> &v) {
    int t = 0;
    for (int i=0; i<(int)v.size()-2; i++) {
        if (v[i]==v[i+1]) {
            if (v[i]==v[i+2]) {
                t += 3;
                v.erase(v.begin()+i);
                v.erase(v.begin()+i);
                v.erase(v.begin()+i);
            }
        }
    }

    if (t==0) return 0;
    else return t + rec(v);
}

int solve(int a) {
    vector<int> v = c;
    v.insert(v.begin() + a, x);
    return rec(v);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k>>x;

    c.resize(n);

    for (int i=0; i<n; i++) cin>>c[i];

    int res = 0;
    for (int i=0; i<=n; i++) {
        res = max(res, solve(i));
    }

    cout<<res<<endl;

    return 0;

}
