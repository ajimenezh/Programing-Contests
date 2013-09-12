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

pair<int,int> v[1000010];
int n;
char c[1000010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    for (int i=0; i<n; i++) {
        int a,b;
        scanf("%d%d",&a,&b);
        v[i] = make_pair(a,i);
    }
    long long t = 0;
    long long s = 0;
    sort(v,v+n);
    reverse(v,v+n);
    for (int i=0; i<n; i++) t += v[i].first;
    for (int i=0; i<n; i++) c[i] = 'A';
    for (int i=n-1; i>=0; i--) {
        //cout<<s<<" "<<t<<endl;
        if (abs(s-t)<500) break;
        c[v[i].second] = 'G';
        t -= v[i].first;
        s += (1000 - v[i].first);
    }
    //cout<<s<<" "<<t<<endl;
    if (abs(t-s)>500) cout<<-1;
    else {
        for (int i=0; i<n; i++) printf("%c",c[i]);
    }

    return 0;

}
