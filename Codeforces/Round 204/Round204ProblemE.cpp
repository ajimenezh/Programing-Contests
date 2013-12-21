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

int n;
int a[2010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    for (int i=0; i<n; i++) a[i] = abs(a[i]);

    for (int i=0; i<n; i++) if (a[i]>0) {
        int c1 = 0;
        int c2 = 0;
        for (int j=i+1; j<n; j++) {
            if (a[j]<a[i]) c1++;
            if (a[j]<-a[i]) c2++;
        }
        for (int j=0; j<i; j++) {
            if (a[j]>a[i]) c1++;
            if (a[j]>-a[i]) c2++;
        }
        if (c2<=c1) a[i] = -a[i];
    }

    int cnt = 0;
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) if (a[j]<a[i]) cnt++;
    }

    cout<<cnt<<endl;

    return 0;

}
