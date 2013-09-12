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

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string a,b;
    cin>>a>>b;
    int p = 0, q = 0;
    if (a.length()==1) a = "0" + a + ".00";
    if (a.length()==2) a = a + ".00";
    if (a.length()==4) a = a + "0";
    if (b.length()==1) b = "0" + b + ".00";
    if (b.length()==2) b = b + ".00";
    if (b.length()==4) b = b + "0";
    for (int i=0; i<a.length(); i++) if (a[i]!='.') p = 10*p + a[i]-'0';
    for (int i=0; i<b.length(); i++) if (b[i]!='.') q = 10*q + b[i]-'0';

    p *= 10;
    q *= 10;

    for (int i=1; i<=10010; i++) {
        if ((long long)p*(long long)i/100000<(long long)q*(long long)i/100000-1) {
            cout<<i<<endl;
            break;
        }
        if ((long long)p*(long long)i/100000<(long long)q*(long long)i/100000  &&((long long)p*(long long)i)%100000!=0 && ((long long)q*(long long)i)%100000!=0) {
            cout<<i<<endl;
            break;
        }
    }

    return 0;

}
