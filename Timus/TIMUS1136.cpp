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

struct node{
    int l,r;
    node(){
        l = -1;
        r = -1;
    }
};
node all[66000];
int n;
int root;
int v[3010];

void doit(int i, int j) {
    if (i>=j) return;
    int k = i;
    while (v[k]<v[j]) k++;
    if (k-1>=i) {
        all[v[j]].l = v[k-1];
        doit(i,k-1);
    }
    if (k<=j-1) {
        all[v[j]].r = v[j-1];
        doit(k, j-1);
    }
}

void print(int nd) {
    if (all[nd].r!=-1) print(all[nd].r);
    if (all[nd].l!=-1) print(all[nd].l);
    cout<<nd<<" ";
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        scanf("%d",v+i);
    }
    root = v[n-1];
    doit(0,n-1);

    print(root);

    return 0;

}
