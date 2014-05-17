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

string s;
int n;
int suml[100010];
int sumr[100010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>s;
    n = s.length();
    for (int i=0; i<n; i++) {
        if (s[i]>='A' && s[i]<='Z') suml[i+1] = suml[i] + 1;
        else suml[i+1] = suml[i];
    }
    for (int i=n-1; i>=0; i--) {
        if (s[i]>='A' && s[i]<='Z') sumr[i] = sumr[i+1] + 1;
        else sumr[i] = sumr[i+1];
    }
    int best = min(suml[n], n-suml[n]);
    for (int i=0; i<n; i++) {
        //cout<<i+1-suml[i+1]+sumr[i+1]<<" "<<i<<endl;
        best = min(i+1-suml[i+1]+sumr[i+1], best);
    }
    cout<<best<<endl;

    return 0;

}
