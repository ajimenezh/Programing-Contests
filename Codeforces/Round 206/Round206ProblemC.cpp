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

int a[300100];
int cnt[1000100];
int k;
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);

    int mi = 1000000;
    for (int i=0; i<n; i++) mi = min(mi,a[i]);
    for (int i=0; i<n; i++) {
        cnt[a[i]+1]--;
        cnt[max(a[i]-k,0)]++;
    }
    sort(a,a+n);
    for (int i=1; i<=a[n-1]; i++) cnt[i] += cnt[i-1];
    for (int i=mi; i; i--) {
        int sum = 0;
        for (int j=i; j<=a[n-1]; j+=i) sum += cnt[j];
        if (sum>=n) {
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<1<<endl;

    return 0;

}
