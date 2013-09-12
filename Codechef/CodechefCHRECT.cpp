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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=0; t<tt; t++) {
        int n,m,k;
        cin>>n>>m>>k;
        int sol = k;
        if (n==1 && m==1) sol = 0;
        else if (n==1 && m==2) sol = 0;
        else if (n==2 && m==1) sol = 0;
        else if (n>1 && m>1) sol = (k-1)/2+1;
        else if (n==1 && m>1) sol = k;
        else if (m==1 && n>1) sol = k;
        printf("%d\n",sol);
    }

    return 0;

}
