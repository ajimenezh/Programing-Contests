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

int n,m,k;
int a[100010];
int b[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>m>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int j=0; j<m; j++) scanf("%d",b+j);
    sort(a,a+n);
    reverse(a,a+n);
    sort(b,b+m);
    reverse(b,b+m);
    if (n>m) {
        cout<<"YES"<<endl;
        return 0;
    }
    for (int i=0; i<min(n,m); i++) {
        if (a[i]>b[i]) {
            cout<<"YES"<<endl;
            return 0;
        }
    }

    cout<<"NO"<<endl;

    return 0;

}
