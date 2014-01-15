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

int n,m;
long long d[310][310];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) for (int j=0; j<n; j++) cin>>d[i][j];
    for (int k=0; k<n; k++) for (int i=0; i<n; i++) for (int j=0; j<n; j++) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    cin>>m;
    long long sum;
    for (int t=0; t<m; t++) {
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        a--; b--;
        for (int i=0; i<n; i++) for (int j=0; j<n; j++) {
            d[i][j] = min(d[i][j], d[i][a]+c+d[b][j]);
            d[i][j] = min(d[i][j], d[i][b]+c+d[a][j]);
        }
        sum = 0;
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) sum += d[i][j];
        cout<<sum<<" ";
    }

    return 0;

}
