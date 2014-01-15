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
int c;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>c;
    int b = 0, all = 0, bal = 0;

    for (int i=0; i<n; i++) {
        string s;
        int t;
        cin>>t>>s;
        if (s=="bedroom") b += t;
        if (s=="balcony") bal += t;
        all += t;
    }

    cout<<all<<endl;
    cout<<b<<endl;

    long long tot = (long long)(all - bal)*c*2 + bal*c;

    if (tot%2==0) cout<<tot/2<<endl;
    else cout<<tot/2<<".5"<<endl;

    return 0;

}
