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

int n;
int sum;
int m;
int x;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    m = 10000;
    cin>>n;
    for (int i=0; i<2*n-1; i++) {
        int a;
         scanf("%d",&a);
         sum += abs(a);
         if (a<0)
            x++;
         m = min(m, abs(a));
    }

    if (n%2==1 || x%2==0) cout<<sum<<endl;
    else cout<<sum-2*m<<endl;

    return 0;

}
