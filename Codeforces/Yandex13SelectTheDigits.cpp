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


int main() {

    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);

    string s;
    cin>>s;
    int res = 44444;
    for (int i=0; i<(1<<8); i++) if (__builtin_popcount(i)==4) {
        int tmp = 0;
        for (int j=0; j<8; j++) if ((1<<j)&i) tmp = 10*tmp + (s[j]-'0');
        res = min(res,tmp);
    }
    cout<<res<<endl;


    return 0;

}
