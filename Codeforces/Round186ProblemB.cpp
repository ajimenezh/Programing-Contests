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

string s;
int a[100010];
int w[100010];
int n;
int _update(int k, int v) {
    for (int x = k; x <= n; x += x & -x) w[x-1] += v;
}
int _get(int k){
    if (k==0) return 0;
    int x = 0;
    for (int i = k; i>0; i -= i & -i) x += w[i-1];
    return x;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();
    for (int i=0; i<n-1; i++) a[i] = s[i]==s[i+1];
    a[s.length()-1] = 0;
    for (int i=0; i<n; i++) _update(i+1,a[i]);

    int k;
    cin>>k;
    for (int i=0; i<k; i++) {
        int u,v;
        cin>>u>>v;
        cout<<_get(max(u,v)-1)-_get(min(u,v)-1)<<endl;
    }
    return 0;

}
