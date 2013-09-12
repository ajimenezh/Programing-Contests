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

#define eps 0.000001

int n;
int a[1005];

double solve(double in, double fn) {
    double l = in, r = fn;

    for (int k=0; k<100; k++) {
        double m = (l+r)/2;

        //cout<<l<<" "<<r<<endl;

        double t = m;
        bool done = false;
        for (int i=0; i<n; i++) {
            int pre;
            i==0 ? pre = 0 : pre = a[i-1];
            t -= 10*(a[i]-pre);
            //cout<<t<<endl;
            if (t<0) {
                l = m;
                done = true;
                break;
            }
            if (t>=10) {
                r = m;
                done = true;
                break;
            }
            t += m;
        }

        if (!done) return m;
    }

    return -1;
}

int doit(double alpha) {
    double t = alpha;
    for (int i=0; i<n; i++) {
        int pre;
        i==0 ? pre = 0 : pre = a[i-1];
        t -= 10*(a[i]-pre);
        t += alpha;
        //cout<<t<<endl;
    }
    t -= alpha;
    if (t<10) t += alpha;
    //cout<<t<<endl;
    return (a[n-1] + ((int) t)/10);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>a[i];

    double alpha1 = solve(10-eps,1100000);
    //cout<<alpha1<<" "<<doit(alpha1)<<endl;

    for (int i=0; i<=1000; i++) {
        double alpha2 = solve(alpha1 - 10000.0/(1.0*i), alpha1 );
        if (alpha2<0) continue;
        if (doit(alpha2)!=doit(alpha1)) {
            //cout<<alpha2<<" "<<doit(alpha2)<<endl;
            cout<<"not unique"<<endl;
            return 0;
        }

        alpha2 = solve(alpha1 , alpha1+10000.0/(1.0*i));
        if (alpha2<0) continue;
        if (doit(alpha2)!=doit(alpha1)) {
            //cout<<alpha2<<endl;
            cout<<"not unique"<<endl;
            return 0;
        }
    }

    if (false);
    else {
        cout<<"unique"<<endl;
        cout<<doit(alpha1);
    }


    return 0;

}
