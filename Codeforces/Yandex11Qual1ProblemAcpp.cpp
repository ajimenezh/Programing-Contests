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
int a,b;
int v[100010];
pair<int,int> w[100010];
int f[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>a>>b;
    for (int i=0; i<n; i++) scanf("%d",v+i);
    if (a<b) {
        for (int i=0; i<n; i++) w[i] = make_pair(v[i],-i);
        sort(w,w+n);
        reverse(w,w+n);
        for (int i=0; i<a; i++) f[-w[i].second] = 1;
        for (int i=a; i<n; i++) f[-w[i].second] = 2;
    }
    else {
        for (int i=0; i<n; i++) w[i] = make_pair(v[i],i);
        sort(w,w+n);
        reverse(w,w+n);
        for (int i=0; i<b; i++) f[w[i].second] = 2;
        for (int i=b; i<n; i++) f[w[i].second] = 1;
    }


    if (a!=b) for (int i=0; i<n; i++) cout<<f[i]<<" ";
    else {
        for (int i=0; i<a; i++) cout<<"1 ";
        for (int i=0; i<b; i++) cout<<"2 ";
    }

    return 0;

}
