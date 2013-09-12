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
int a[100010];


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;

    for (int i=0; i<n; i++) a[i] = i+1;

    int in = 0;
    if (n%2!=0) in = 1;

    for (int i=in; i<n; i+=2) {
        int tmp = a[i];
        a[i] = a[i+1];
        a[i+1] = tmp;
    }

    for (int i=0; i<n; i++) printf("%d ",a[i]);

    return 0;

}
