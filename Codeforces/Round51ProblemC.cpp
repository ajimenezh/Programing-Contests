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

bool h[101],v[101];
pair<int,int> vs[101];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m,k;
    cin>>n>>m>>k;

    if (k==0) {cout<<"NO";return 0;}

    int sum = 0;
    for (int i=0; i<k; i++) cin>>vs[i].first>>vs[i].second;
    for (int i=0; i<k; i++) {
        int a,b;
        a = vs[i].first;
        b = vs[i].second;
        int d = min(min(a-1,n-a),min(b-1,m-b));
        if (d<=4) {cout<<"YES"; return 0;}
    }

    cout<<"NO"<<endl;


    return 0;

}
