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
string s;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n;
    cin>>s;

    int p = -1;

    for (int i=1; i<n; i++) {
        if (s[i-1]==s[i]) {
            p = i;
            break;
        }
    }

    if (p==-1) {
        cout<<0;
        return 0;
    }

    int best = 0;
    int tmp = 0;

    for (int i=p; i<n; i++) {
        if (i%2==0 && s[i]!='0' || i%2!=0 && s[i]!='1') tmp++;
    }
    for (int i=p-1; i>=0; i--) {
        if (i%2==0 && s[i]!='0' || i%2!=0 && s[i]!='1') tmp++;
    }

    best = tmp;

    tmp = 0;

    for (int i=p; i<n; i++) {
        if (i%2==0 && s[i]!='1' || i%2!=0 && s[i]!='0') tmp++;
    }
    for (int i=p-1; i>=0; i--) {
        if (i%2==0 && s[i]!='1' || i%2!=0 && s[i]!='0') tmp++;
    }

    best = min(best,tmp);

    cout<<best;

    return 0;

}
