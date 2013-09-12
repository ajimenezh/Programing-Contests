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

int v[2000000];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int k;
    cin>>k;
    for (int i=0; i<k; i++) scanf("%d",v+i);
    sort(v,v+k);
    reverse(v,v+k);

    int n = k;

    long long sum = 0;
    int cnt = 0;
    while (k>0) {
        k /= 4;
        cnt++;
    }

    int c = 1;
    for (int i=0; i<n; i++) {
        //cout<<i<<" "<<c<<" "<<cnt<<endl;
        sum += (long long)cnt*(long long)v[i];
        if ((i+1)==c) {cnt--; c *= 4;}
    }

    cout<<sum;

    return 0;

}
