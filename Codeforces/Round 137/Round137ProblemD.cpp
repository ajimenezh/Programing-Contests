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

int n,x;
int a[100010];
int b[100010];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>x;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) scanf("%d",b+i);

    sort(b,b+n);
    sort(a,a+n);
    int k = 0;
    for (int i=0, j=n-1; i<n&&j>=0; i++) if (a[i]+b[j]>=x) {
        j--; k++;
    }

    cout<<1<<" "<<k<<endl;


    return 0;

}
