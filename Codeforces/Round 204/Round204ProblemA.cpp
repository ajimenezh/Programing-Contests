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
int a[4010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<2*n; i++) {
        int b,c;
        scanf("%d.%d",&b,&c);
        a[i] = b*1000+c;
    }

    int sum = 0;
    for (int i=0; i<2*n; i++) a[i] = a[i]%1000;
    for (int i=0; i<2*n; i++) sum += a[i];
    int c = 0;
    while (sum>1000 && c<n) {
        sum -= 1000;
        c++;
    }
    if (c<n) {
        if (1000-sum<sum && c<n) {
            c++;
            sum -= 1000;
        }
    }
    sort(a,a+2*n);
    for (int i=0; i<2*n; i++) {
        if (c<n && a[i]==0) c++;
        else break;
    }

    c = n-c;
    int ans = sum - c*1000;
    ans = abs(ans);

    printf("%d.",ans/1000);
    ans = ans%1000;
    int tmp = ans;
    if (tmp==0) {
        cout<<"000";
        return 0;
    }
    while (tmp<100) {
        cout<<"0";
        tmp*=10;
    }
    cout<<ans;

    return 0;

}
