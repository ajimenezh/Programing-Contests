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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

int n,m;
int len[501];
pii point[501];
int used[501];

int main() {

    cin>>n>>m;
    fo(i,n)
    {
        int a,b;
        cin>>a>>b;
        point[i] = mp(a,b);
    }
    fo(i,m) cin>>len[i];




    return 0;

}
