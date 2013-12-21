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

int n,k;
int a[100100];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    int best = 1000000000;
    int p = -1;

    for (int i=0; i<k; i++) {
        int sum = 0;
        for (int j=0; j<n/k; j++) {
            sum += a[(i+j*k)%n];
        }
        if (sum<best) {
            best = sum;
            p = i+1;
        }
    }

    cout<<p<<endl;

    return 0;

}
