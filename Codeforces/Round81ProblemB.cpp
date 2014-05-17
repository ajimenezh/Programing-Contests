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

int n,k,a,b;
int s[9],l[9];

double solve(int k,int in)
{
    //cout<<k<<endl;
    if (k!=0) {
        double p = 0.0;
        bool all = true;
        for (int i=0; i<n; i++) if (l[i]!=100) all = false;
        if (all) return solve(0,0);
        for (int i=in; i<n; i++)
        {
            if (l[i]<100)
            {
                l[i]+=10;
                p = max(solve(k-1,i),p);
                l[i]-=10;
            }
        }
        return p;
    }
    else {
        //for (int i=0; i<n; i++) cout<<l[i]<<" "; cout<<endl;
        double p = 0.0;
        for (int i=0; i<(1<<n); i++) {
            int tmp = 0;
            double q = 1.0;
            b = 0;
            for (int j=0; j<n; j++) {
                if ((1<<j)&i) {
                    q *= 1.0*l[j]/100.0;
                    tmp++;
                }
                else {
                    q *= 1.0-1.0*l[j]/100.0;
                    b += s[j];
                }
            }
            if (tmp>n/2) p += q;
            else {
                p += q*(1.0*a/(1.0*a+1.0*b));
            }
            //cout<<a<<endl;
        }
        //cout<<p<<endl;
        return p;
    }
}

int main() {

	//freopen("input.txt","r",stdin);
   	//freopen("output.txt","w",stdout);

    cin>>n>>k>>a;
    for (int i=0; i<n; i++) {
        int x,y;
        cin>>x>>y;
        s[i] = x;
        l[i] = y;
    }

    double res = solve(k,0);

    printf("%.8f",res);

	return 0;

}
