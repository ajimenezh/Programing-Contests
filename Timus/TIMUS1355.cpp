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

int solve(int a) {
    int c = 0;
    for (int i=2; (long long)i*i<=a; i++) if (a%i==0) {
        while (a%i==0) {
            c++;
            a /= i;
        }
    }
    if (a!=1) c++;
    return c+1;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int t;
    cin>>t;
    while (t--) {
        int a,b;
        scanf("%d%d",&a,&b);
        if (b%a!=0) cout<<0<<endl;
        else cout<<solve(b/a)<<endl;
    }

    return 0;

}
