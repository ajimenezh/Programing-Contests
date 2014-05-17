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

//99099999

bool good(int i) {
    while (i>0) {
        if (i%10==0 || i%10==9);
        else return false;
        i /= 10;
    }
    return true;
}

long long f(int t) {
    long long k = 0;
    for (int i=50; i>=0; i--) {
        if (t&(1LL<<i)) k = k*10 + 9;
        else k = k*10;
    }
    return k;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    int k;
    cin>>k;
    while (k--) {
        scanf("%d",&n);
        int t = 1;
        while (f(t)%n!=0) t++;
        cout<<f(t)<<"\n";
    }

    return 0;

}
