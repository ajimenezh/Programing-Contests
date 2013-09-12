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
int s[100010];
int a[100010][32];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",s+i);
    for (int i=0; i<=30; i++) {
        for (int j=0; j<n; j++) {
            if ((s[j]&(1<<i))==(1<<i)) {
                a[j][i] = 1;
            }
            else a[j][i] = 0;
        }
    }

    int p = -1;
    for (int i=30; i>=0; i--) {
        bool good = false;
        int t = 0;
        for (int j=0; j<n; j++) t += a[j][i];
        for (int j=0; j<n; j++) {
            if (a[j][i]==0 && t>0) {
                good = true;
                p = i;
                break;
            }
        }
        if (good) break;
    }


    long long res = 0;
    int last = 0;
    for (int i=0; i<n; i++) {
        if (a[i][p]==1) {
            int m = 0;
            for (int j=i-1; j>=last; j--) {
                if (s[j]>m) {
                    res = max((long long)s[j]^(long long)s[i],res) ;
                    m = s[j];
                }
            }
            m = 0;
            for (int j=i+1; j<n; j++) {
                if (a[j][p]==1) {
                    last = i+1;
                    break;
                }
                if (s[j]>m) {
                    res = max((long long)s[j]^(long long)s[i],res) ;
                    m = s[j];
                }
            }
        }
    }

    int sol = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int m1 = s[i], m2 = s[i+1];
            for (int k=i+2; k<=j; k++) {
                if (s[k]>m1) {
                    m2 = m1;
                    m1 = s[k];
                }
                else if (s[k]>m2) {
                    m2 = s[k];
                }
            }
            sol = max(sol,m1^m2);
        }
    }

    //cout<<sol<<endl;
    cout<<(int)res<<endl;

    return 0;

}
