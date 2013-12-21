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

int m;
int p;
int n;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>m;
    if (m==0) {
        cin>>n;
        long long sum = 0;
        for (int i=0; i<n; i++) {
            int k;
            scanf("%d",&k);
            sum += k;
        }
        cout<<sum;
    }
    else {
        p = 100000000;
        for (int i=0; i<m; i++) {
            int k;
            scanf("%d",&k);
            p = min(k,p);
        }
        cin>>n;
        for (int i=0; i<n; i++) {
            scanf("%d",a+i);
        }
        sort(a,a+n);
        reverse(a,a+n);
        long long sum = 0;
        for (int i=0; i<n; i+=p+2) {
            for (int j=i; j<min(n,i+p); j++) sum += a[j];
        }
        cout<<sum<<endl;
    }

    return 0;

}
