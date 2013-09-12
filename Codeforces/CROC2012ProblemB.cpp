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

#define mod 1000000007

string s1,s2;
int k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s1;
    cin>>s2;
    cin>>k;

    if (k==0) {
        cout<<(s1==s2);
        return 0;
    }

    string s = s1+s1;
    int good = 0;
    int bad = 0;
    for (int i=0; i<s1.length(); i++) {
        bool equal = true;
        for (int j=0; j<s2.length(); j++) if (s2[j]!=s[i+j]) {
            equal = false;
            break;
        }
        if (equal) good++;
        else bad++;
    }

    if (good==0) {
        cout<<0;
        return 0;
    }

    long long tmpg = 0;
    long long tmpb = 0;
    if (s1==s2) {
        tmpg = good-1;
        tmpb = bad;
    }
    else {
        tmpg = good;
        tmpb = bad-1;
    }
    for (int i=1; i<k; i++) {
        long long tmp = tmpg;
        tmpg = ((tmpg*((long long)good-1LL)%mod + mod)%mod + tmpb*(long long)(good)%mod)%mod;
        tmpb = (tmp*(long long)(bad)%mod + (tmpb*((long long)bad-1LL)%mod + mod)%mod)%mod;
    }

    cout<<tmpg;

    return 0;

}
