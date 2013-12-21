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
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    if (n==1) cout<<"+";
    else {
        long long sum = 0;
        for (int i=0; i<n-1; i++) sum += a[i];
        sum -= a[n-1];
        int k = 0;
        while (sum>2*a[0]) {
            sum -= a[k];
            cout<<"-";
            k++;
        }
        for (int i=k; i<n-1; i++) cout<<"+";
        cout<<"-";
    }

    return 0;

}
