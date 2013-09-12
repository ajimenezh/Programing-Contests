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
#define forit(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#define mp(a,b) make_pair(a,b)
#define pb(x) push_back(x)
#define pii pair<int,int>

#define MAXN 100010

int n,m;
long long a[100010];


int main() {

    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

    cin>>m;

    int k = 0;
    long long r = a[0];

    for (int i=0; i<m; i++) {
        long long w,h;
        scanf("%I64d%I64d",&w,&h);

        while (k<(w-1)) k++;
        if (k!=n) {
            //cout<<"hola  "<<k<<" "<<r<<endl;
            printf("%I64d\n",max(a[k],r));
        }
        else {
            printf("%I64d\n",r);
        }

        if (k!=n && a[k]>=r) {
            r = a[k] + h;
        }
        else {
            r += h;
        }
        k = max(k,(int)w-1);
        k = min(k,n);

        //cout<<k<<" "<<r<<endl;
    }


	return 0;

}
