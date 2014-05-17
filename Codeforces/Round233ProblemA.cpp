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

long long n,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    long long res = 0;
    if (k==0) {
        res = n*n;
        cout<<res<<endl;
        for (int i=0; i<n; i++) cout<<"o";
    }
    else if (k==1) {
        res = n*n-1;
        cout<<res<<endl;
        for (int i=0; i<n; i++) cout<<"o";
        cout<<"x";
    }
    else if (k==2 && n!=0) {
        res = n*n-2;
        cout<<res<<endl;
        cout<<"x";
        for (int i=0; i<n; i++) cout<<"o";
        cout<<"x";
    }
    else {
        if (n==0) {
            res = -k*k;
            cout<<res<<endl;
            for (int i=0; i<k; i++) cout<<"x";
        }
        else {
            long long cur = -10000000000000LL;
            int a1,a2,b1,b2;
            int tot = 0;
            for (int i=0; i<n; i++) {
                long long t = n/(i+1);
                long long tmp = i;
                res = i + (n-i)*(n-i);

                long long t2 = k/(i+2);
                long long tmp2 = k%(i+2);
                res -= tmp2*(t2+1)*(t2+1) + (i+2-tmp2)*t2*t2;

                if (res>cur) {
                    cur = res;
                    a1 = t;
                    a2 = tmp;
                    b1 = t2;
                    b2 = tmp2;
                    tot = i+1;
                }
            }

            int t = a1, tmp = a2, t2 = b1, tmp2 = b2;
            cout<<cur<<endl;
            while (tot--) {
                if (tmp2>0) {
                    for (int i=0; i<t2+1; i++) cout<<"x";
                    tmp2--;
                }
                else {
                    for (int i=0; i<t2; i++) cout<<"x";
                }
                if (tmp>0) {
                    for (int i=0; i<1; i++) cout<<"o";
                    tmp--;
                    n--;
                }
                else {
                    for (int i=0; i<n; i++) cout<<"o";
                }
            }
            if (tmp2>0) {
                for (int i=0; i<t2+1; i++) cout<<"x";
                tmp2--;
            }
            else {
                for (int i=0; i<t2; i++) cout<<"x";
            }
        }
    }

    return 0;

}
