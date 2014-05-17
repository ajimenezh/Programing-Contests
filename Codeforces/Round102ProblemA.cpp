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


int main() {

    long long n;
    cin>>n;

    long long ma,mi;

    mi = ma = (n+1)*3*3 - n;

    for (long long i=1; (i*i*i)<=n; i++)
    {
        for (long long j = 1; j*j*i<=n; j++)
        {
            if (n%i==0 && (n/i)%j==0)
            {
                long long k = n/i/j;

                mi = min(mi,(i+1)*(j+2)*(k+2)-n);
                mi = min(mi,(i+2)*(j+1)*(k+2)-n);
                mi = min(mi,(i+2)*(j+2)*(k+1)-n);

                ma = max(ma,(i+1)*(j+2)*(k+2)-n);
                ma = max(ma,(i+2)*(j+1)*(k+2)-n);
                ma = max(ma,(i+2)*(j+2)*(k+1)-n);
            }
        }
    }

    cout<<mi<<" "<<ma<<endl;

	return 0;

}
