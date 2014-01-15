#include <iostream>
#include <sstream>
#include <vector>
#include <string.h>
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

int n,p;
int a[1010];
int c[1010000];
int sum[1010];
int m;
int l[1010];
int r[1010];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>p;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) c[a[i]]++;
    sort(a,a+n);
    for (int i=0; i<n; i++) {
        if (i==0 || a[i]!=a[i-1]) {
            sum[m] = c[a[i]];
            a[m] = a[i];
            m++;
        }
    }

    long long cur = 0;
    int tmp = 0;
    int cn = 0;
    int spell = 0;
    for (int i=0; i<m; i++) {
        tmp += sum[i];
        if ((long long)tmp*a[i]>p) {
            tmp -= sum[i];
            cn += tmp;
            if (tmp==0) break;
            spell++;
            tmp = 0;
            i--;
        }
        else if (i==m-1) {
            cn += tmp;
            spell++;
        }
    }

    cout<<cn<<" "<<spell<<endl;

    return 0;

}

