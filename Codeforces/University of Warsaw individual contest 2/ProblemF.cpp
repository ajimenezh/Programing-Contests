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
int s[1010][1010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=0; i<n; i++) for (int j=0; j<n; j++) scanf("%d",&s[i][j]);

    if (n>2) {

        int a2 = s[n-3][n-2] + s[n-3][n-1];
        a2 = (a2 - s[n-2][n-1]) / 2;

        s[n-3][n-3] = 2*a2;

        for (int i=0; i<n; i++) {
            cout<<s[i][n-3] - a2<<" ";
        }
    }
    else {
        cout<<1<<" "<<1<<endl;
    }

    return 0;

}
