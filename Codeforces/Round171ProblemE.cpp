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

    string s;
    cin>>s;
    int res = 0;

    int n = s.length();
    for (int i=1; i<n-1; i++) {if (s[i-1]=='1' && s[i]=='0' && s[i+1]=='1') s[i] = '2';}
    for (int i=n-1; i>=0; i--) if (s[i]=='1') {
        int j=i;
        int c = 0;
        int r = 0;
        while (j>=0 && s[j]=='1' || s[j]=='2') {c++; if (s[j]=='2') r++; j--;}
        if (c>1) res += min(c-r,2+r);
        else res++;
        i = j+1;
    }

    cout<<res<<endl;

    return 0;

}
