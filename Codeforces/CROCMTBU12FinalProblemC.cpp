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
int a[100010];
int cnt[100010];
int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    vector<int> v;
    for (int i=0; i<n; i++) {
        if (i==0 || a[i]!=a[i-1]) v.push_back(a[i]);
    }
    for (int i=0; i<v.size(); i++) {
        if (i==0 || i==v.size()-1) cnt[v[i]]++;
        else {
            if (v[i-1]==v[i+1]) cnt[v[i]]+=2;
            else cnt[v[i]]++;
        }
    }

    int best = 0;
    int p = -1;
    for (int i=1; i<=k; i++) {
        if (cnt[i]>best) {
            best = cnt[i];
            p = i;
        }
    }
    cout<<p<<endl;

    return 0;

}
