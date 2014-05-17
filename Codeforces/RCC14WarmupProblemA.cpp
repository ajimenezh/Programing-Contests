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

int c,d,n,m,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>c>>d>>n>>m>>k;

    int t = 0;
    int cur = k;
    int best = 1000000000;
    for (int i=0; i<=m; i++) {
        int tmp = (n*m - k - n*i);
        if (tmp<0) best = min(best, c*i);
        else best = min(best, c*i + tmp*d);
    }
    cout<<best<<endl;

    return 0;

}
