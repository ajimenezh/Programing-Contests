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

int a[300010];
pair<int,int> v[300010];
int n;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) scanf("%d",a+i);
    for (int i=0; i<n; i++) v[i] = make_pair(a[i],i);
    sort(v,v+n);
    int last = -1;
    for (int i=0; i<n; i++) {
        if (v[i].first<=last) {
            a[v[i].second] = ++last;
        }
        else {
            last = v[i].first;
            a[v[i].second] = last;
        }
    }

    for (int i=0; i<n; i++) cout<<a[i]<<" ";

    return 0;

}
