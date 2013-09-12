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

#define MAXN 100010

int n;
int a[MAXN];
int b[MAXN];
int k,p;
vector<int> v;
set<pair<int,int> > s;
int id[MAXN];

bool cmp(int i, int j) {
    if (a[i]==a[j]) return b[i]>b[j];
    return a[i]>a[j];
}
bool cmp2(int i, int j) {
    if (b[i]==b[j]) return a[i]<a[j];
    return b[i]<b[j];
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>p>>k;
    for (int i=0; i<n; i++) scanf("%d%d",a+i,b+i);
    for (int j=0; j<n; j++) id[j] = j;
    sort(id,id+n,cmp);
    for (int i=0; i<k; i++) v.push_back(id[i]);
    sort(id+k,id+n,cmp2);
    for (int i=k; i<p; i++) v.push_back(id[i]);

    for (int i=0; i<p; i++) printf("%d ",v[i]+1);

    return 0;

}
