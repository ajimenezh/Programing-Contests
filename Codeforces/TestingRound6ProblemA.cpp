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

int a[110];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m;
    cin>>n>>m;
    for (int i=0; i<m; i++) a[i] = n/m;
    n = n%m;
    for (int i=m-1; i>=m-n; i--) a[i]++;
    for (int i=0; i<m; i++) cout<<a[i]<<" ";

    return 0;

}
