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

int dp[200][8];
int v[] = {1,2,5,10,20,50,100,200};

int solve(int a, int i) {
    if (a>200) return 0;
    if (a==200) return 1;
    if (i==8) return 0;
    if (dp[a][i]) return  dp[a][i];

    int tmp = 0;
    for (int j=0; a+j*v[i]<=200; j++) {
        tmp += solve(a+j*v[i],i+1);
    }
    dp[a][i] = tmp;
    return tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cout<<solve(0,0);

    return 0;

}
