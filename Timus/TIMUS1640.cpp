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

int x[101], y[110];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d%d",x+i,y+i);

    double dist = 0.0;
    int t;
    for (int i=0; i<n; i++) {
        if (dist < sqrt(x[i]*x[i] + y[i]*y[i])) {
            dist = sqrt(x[i]*x[i] + y[i]*y[i]);
        }
    }
    cout<<0<<" "<<0<<" ";
    printf("%.12lf\n",dist);

    return 0;

}
