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

int n;
long long a[200010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%I64d",&a[i]);

    sort(a,a+n);

    long long d=-1;
    int i1,i2;
    for (int i=0; i<n; i++) {

        double tmp = 0;

        int left = i+1;
        int right = n-1;

        while (left<right-2) {
            int thirdLeft = (2*left + right)/3;
            int thirdRight = (2*right + left)/3;

            long long valLeft, valRight;

            valLeft = max(a[thirdLeft] - a[min(i+1,n-1)] , a[n-1] - a[min(thirdLeft+1,n-1)]);

            valRight = max(a[thirdRight] - a[min(i+1,n-1)] , a[n-1] - a[min(thirdRight+1,n-1)]);

            if (valLeft<valRight) {

                right = thirdRight;

            }
            else {
                left = thirdLeft;
            }
        }

        for (int j=left-3; j<=right+3; j++) {
            if (j<i || j>n-1) continue;
            long long t = 0;
            t = max(a[i]-a[0], a[j] - a[min(i+1,n-1)]);
            t = max(t, a[n-1] - a[min(j+1,n-1)]);

            //cout<<i<<" "<<j<<" "<<a[i]-a[0]<<" "<<a[j] - a[min(i+1,n-1)]<<" "<<a[n-1] - a[min(j+1,n-1)]<<endl;

            if (d<0 || t<d) {
                d = t;
                i1 = i;
                i2 = j;
            }
        }
    }

    printf("%.6f\n",1.0*d/2.0);
    printf("%.6f %.6f %.6f\n",(1.0*a[i1]-1.0*a[0])/2.0 + a[0], (1.0*a[i2]-1.0*a[min(i1+1,n-1)])/2.0 + a[min(i1+1,n-1)], (1.0*a[n-1]-1.0*a[min(i2+1,n-1)])/2.0 + a[min(i2+1,n-1)]);

    return 0;

}
