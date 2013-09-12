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
int t;
int a[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>t;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    long long sum = 0;
    int i = 0;
    int j = 0;
    int c = 0;
    for (i=0;i<n; i++) {
        while (j<n && sum<=t) {
            sum += (long long)a[j];
            j++;
        }
        if (sum>t) {
            j--;
            sum -= (long long)a[j];
        }
        if (j>i) c = max(j-i,c);

        //cout<<i<<" "<<j<<" "<<" "<<sum<<endl;

        sum -= a[i];
    }

    cout<<c<<endl;

    return 0;

}
