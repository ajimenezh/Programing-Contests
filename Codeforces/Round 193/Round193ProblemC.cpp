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

int n,p,k;
pair<pair<int,int>,int> v[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>p>>k;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&v[i].first.first,&v[i].first.second);
        v[i].second = i;
    }
    for (int i=0; i<n; i++) {
        swap(v[i].first.first,v[i].first.second);
        v[i].first.second = - v[i].first.second;
    }
    sort(v,v+n);
    for (int i=0; i<(p-k); i++) {
        cout<<v[i].second+1<<" ";
    }
    for (int i=p-k; i<n; i++) {
        swap(v[i].first.first,v[i].first.second);
        v[i].first.first = -v[i].first.first;
    }
    sort(v+(p-k),v+n);
    reverse(v+(p-k),v+n);
    for (int i=(p-k); i<p; i++) {
        cout<<v[i].second+1<<" ";
    }


    return 0;

}
