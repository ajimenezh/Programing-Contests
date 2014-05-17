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

int x[51], y[51];
int n;

long long gcd(long long a, long long b) {
    if (a<b) return gcd(b,a);
    if (b==0) return a;
    return gcd(b,a%b);
}

long long fabs(long long a) {if (a<0) return -a; return a;}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=0; t<tt; t++) {
        cin>>n;
        for (int i=0; i<n; i++) cin>>x[i]>>y[i];

        int tot = 0;
        int kill = 0;
        for (int i=0; i<n; i++) for (int j=i+1; j<n; j++) for (int k=j+1; k<n; k++) {
            for (int a = 0; a<n; a++) {
                if (a==i || a==j || a==k) continue;
                long long d = 1;
                long long A = (long long)(x[i]-x[j])*(long long)(x[i]-x[j]) + (long long)(y[i]-y[j])*(long long)(y[i]-y[j]);
                long long B = (long long)(x[i]-x[k])*(long long)(x[i]-x[k]) + (long long)(y[i]-y[k])*(long long)(y[i]-y[k]);
                long long C = (long long)(x[k]-x[j])*(long long)(x[k]-x[j]) + (long long)(y[k]-y[j])*(long long)(y[k]-y[j]);

                long long delta = ((long long)x[i]*(y[j]-y[k]) + (long long)x[j]*(y[k]-y[i]) + (long long)x[k]*(y[i]-y[j]));
                long long tmp = 2*delta*delta;

                d = A*B*C;

                long long cx = (long long)(x[i]*x[i]+y[i]*y[i])*(y[j]-y[k])+(long long)(x[j]*x[j]+y[j]*y[j])*(y[k]-y[i])+(long long)(x[k]*x[k]+y[k]*y[k])*(y[i]-y[j]);
                long long cy = -(long long)(x[i]*x[i]+y[i]*y[i])*(x[j]-x[k])-(long long)(x[j]*x[j]+y[j]*y[j])*(x[k]-x[i])-(long long)(x[k]*x[k]+y[k]*y[k])*(x[i]-x[j]);

                long long dist = (long long)(cx-2*delta*x[a])*(cx-2*delta*x[a]) + (long long)(cy-2*delta*y[a])*(cy-2*delta*y[a]);

                //cout<<"Debug caso "<<tot<<endl;
                //cout<<x[i]<<" "<<y[i]<<endl<<x[j]<<" "<<y[j]<<endl<<x[k]<<" "<<y[k]<<endl<<x[a]<<" "<<y[a]<<endl;
                //cout<<d<<" "<<delta<<" "<<dist<<" "<<cx<<" "<<cy<<endl;

                if (d>=dist && delta!=0) kill++;

                tot++;
            }
        }

        double p = (double) kill / (double) tot;
        printf("%.8f\n",p);
    }

    return 0;

}
