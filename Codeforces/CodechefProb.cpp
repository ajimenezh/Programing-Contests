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

double rec(double t1, double t2, double t3,int f) {
    if (t3<=1.00000001) {
        return t1/(t1+t2+t3) + t3/(t1+t2+t3)*t1/(t2+t1);
    }
    if (f==0) return t1/(t1+t2+t3) + t3/(t1+t2+t3)*t1/(t1+t2+t3-1.0);
    return t1/(t1+t2+t3) + t3/(t1+t2+t3)*rec(t1,t2,t3-1.0,f-1);
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        double t1,t2,t3,t4;
        cin>>t1>>t2>>t3>>t4;

        double sum = t1+t2+t3;

        t1 -= t4*t1/sum;
        t2 -= t4*t2/sum;
        t3 -= t4*t3/sum;

        printf("%.8f\n",t1/(t2+t1));
    }

    return 0;

}
