#line 2 "BigO.cpp"
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

typedef long long LL;
#define rep(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)

long long b;
int n;
long long x[40];

double f(long long m) {
    long long tot = b;
    int all = 0;
    for (int i=0; i<n; i++) {
        if (x[i]<=m) {
            all++;
            tot -= m-x[i];
        }
        if (tot<0) return -1;
    }
    tot -= (37-n)*m;
    if (tot<0) return -1;
    all += (37-n);
    double res = 0.0;
    for (int i=0; i<n; i++) {
        if (x[i]<=m) {
            res += (double)(m-x[i])*36/all;
        }
    }
    res += (double)(37-n)*m*36/all;
    return res - (b-tot);
}

int main() {

    //freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    for (int t=1; t<=tt; t++) {
        cin>>b>>n;
        for (int i=0; i<n; i++) scanf("%I64d", x+i);
        long long lo = 0;
        long long hi = b;
        double res = 0.0;
        while (lo+2<hi) {
            long long lt = (2*lo+hi)/3;
            long long rt = (lo+2*hi)/3;

            double fl = f(lt);
            double fr = f(rt);

            //cout<<lt<<" "<<fl<<endl;
            //cout<<rt<<" "<<fr<<endl;

            //cout<<lo<<" "<<hi<<endl;

            if (fr<0.0 || fr<fl) {
                hi = rt;
            }
            else lo = lt;
        }
        for (long long i = max(0LL, lo-5); i<lo+5; i++) {
            res = max(res, f(i));
        }

        double res2 = 0.0;
        int p = 0;
        for (int i=0; i<=b; i++) {
            if (res2<f(i)) p = i;
            //cout<<i<<" "<<f(i)<<endl;
            res2 = max(res2, f(i));
        }

        //printf("Case #%d: %.12lf\n", t, res);
        printf("Case #%d: %.12lf\n", t, res2);
        //cout<<p<<endl;
    }

	return 0;
}
