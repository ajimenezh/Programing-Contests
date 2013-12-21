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


string f(int i) {
    string s;
    while (i>0) {
        s += char('0'+i%10);
        i /= 10;
    }
    while (s.length()<9) s = s+"0";
    reverse(s.begin(),s.end());
    return s;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int a,b,mod;
    cin>>a>>b>>mod;

    for (int i=0; i<=min(mod-1,a); i++) {
        int c = ((long long)i*1000000000LL)%mod;
        if ((mod-c)%mod<=b) continue;
        else {
            cout<<1<<" "<<f(i)<<endl;
            return 0;
        }
    }
    cout<<2<<endl;

    return 0;

}
