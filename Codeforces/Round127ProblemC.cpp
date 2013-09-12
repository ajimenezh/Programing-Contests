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

long long l[100010][2], r[100010][2];
long long a[100010];
int n;


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n-1; i++) scanf("%I64d",&a[i]);

    for (int i=0; i<n; i++) {
        if (i==0) {
            l[i][0] = 0;
            l[i][1] = 0;
        }
        else {
            if (a[i-1]==0) {
                l[i][0] = 0;
                l[i][1] = 0;
            }
            else if (a[i-1]==1) {
                l[i][0] = 0;
                l[i][1] = max(l[i-1][1],l[i-1][0]) + 1;
            }
            else if (a[i-1]%2==0) {
                l[i][0] = l[i-1][0] + a[i-1];
                l[i][1] = max(l[i-1][1],l[i-1][0]) + a[i-1] - 1;
            }
            else if (a[i-1]%2!=0) {
                l[i][0] = l[i-1][0] + a[i] - 1;
                l[i][1] = max(l[i-1][1],l[i-1][0]) + a[i-1];
            }
        }
    }

    for (int i=n-1; i>=0; i--) {
        if (i==n-1) {
            r[i][0] = 0;
            r[i][1] = 0;
        }
        else {
            if (a[i]==0) {
                r[i][0] = 0;
                r[i][1] = 0;
            }
            else if (a[i]==1) {
                r[i][0] = 0;
                r[i][1] = max(r[i+1][1],r[i+1][0]) + 1;
            }
            else if (a[i]%2==0) {
                r[i][0] = r[i+1][0] + a[i];
                r[i][1] = max(r[i+1][1],r[i+1][0]) + a[i] - 1;
            }
            else if (a[i]%2!=0) {
                r[i][0] = r[i+1][0] + a[i] - 1;
                r[i][1] = max(r[i+1][1],r[i+1][0]) + a[i];
            }
        }
    }

    //for (int i=0; i<n; i++) cout<<l[i][0]<<" "; cout<<endl;

    long long res = 0;

    for (int i=0; i<n; i++) {
        res = max(res,l[i][0] + r[i][0]);
        res = max(res,l[i][1] + r[i][0]);
        res = max(res,l[i][0] + r[i][1]);
        res = max(res,l[i][1]);
        res = max(res,r[i][1]);
    }

    cout<<res<<endl;


    return 0;

}
