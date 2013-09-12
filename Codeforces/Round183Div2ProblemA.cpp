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

bool v[100000001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    int r = 0;
    for (int i=1; i<=n; i++) v[i*i] = 1;
    for (int i=1; i<=n; i++) for (int j=i; j<=n; j++) {
        if (i*i+j*j>n*n) break;
        if (v[i*i+j*j]) {
            r++;
        }
    }
    cout<<r;

    return 0;

}
