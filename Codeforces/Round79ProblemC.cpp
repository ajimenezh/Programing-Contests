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

pair<int,int> a,b,c;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    scanf("%d%d",&a.first,&a.second);
    scanf("%d%d",&b.first,&b.second);
    scanf("%d%d",&c.first,&c.second);

    b.first -= a.first;
    b.second -= a.second;

    for (int i=-1; i<=1; i+=2) {
        for (int j=-1; j<=1; j+=2) {
            if (i*c.first*j*c.second - i*c.second*(-j)*c.first!=0) {
            }
        }
    }

    return 0;

}
