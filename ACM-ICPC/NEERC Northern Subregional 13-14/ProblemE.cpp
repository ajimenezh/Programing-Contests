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

int n;
int n1, n2;
string s;

int main() {

    freopen("energy.in","r",stdin);
    freopen("energy.out","w",stdout);

    cin>>n>>s;
    long long ans = 0;
    for (int i=0; i<s.length(); i++) {
        if (s[i]=='1') {
            if (n>0) {
                n--;
                n1++;
            }
            else {
                if (n2>0) {
                    n2--;
                    n++;
                    n1++;
                }
            }
        }
        else {
            if (n>1) {
                n-=2;
                n2++;
            }
        }
        ans += n1+n2;
    }

    cout<<ans<<endl;

    return 0;

}
