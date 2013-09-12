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
pair<int,int> v[16000];
int x[33000];
int c[16000];

int get(int p) {
    int s = 0;
    for (int i=p; i>0; i -= i & -i) s += x[i];
    return s;
}
int update(int p) {
    for (int i=p; i<=33000; i += i & -i) x[i]++;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) cin>>v[i].first>>v[i].second;
    for (int i=0; i<n; i++) v[i].second++;

    sort(v,v+n);

    for (int i=0; i<n; i++) {
        c[get(v[i].second)]++;
        update(v[i].second);
    }

    for (int i=0; i<n; i++) cout<<c[i]<<endl;

    return 0;

}
