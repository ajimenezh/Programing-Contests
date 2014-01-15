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
int p[100010];
int sum[200010];

void update(int i, int x) {
    for (;i<=n+m; i+=i&-i) sum[i] += x;
}
int get(int i) {
    int x = 0;
    for (;i>=1;i-=i&-i) x += sum[i];
    return x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        cin>>n>>m;
        for (int i=0; i<=n+m; i++) sum[i] = 0;
        for (int i=0; i<n; i++) p[i] = i+m+1;
        for (int i=0; i<n; i++) update(i+m+1,1);
        for (int i=0; i<m; i++) {
            int c;
            scanf("%d",&c);
            c--;
            printf("%d ",get(p[c]-1));
            update(p[c],-1);
            p[c] = m-i;
            update(p[c],1);
        }
        cout<<endl;
    }

    return 0;

}
