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

int n,k;
int c;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int res = 0;
    cin>>n>>k;
    int last = 0;
    int c;
    cin>>c;
    for (int i=0; i<c; i++) {
        int t;
        cin>>t;
        res++;
        if (t-last-1>=k) {
            res += (t-last-1)/k;
        }
        last = t;
    }
    int t = n+1;
    if (t-last-1>=k) {
        res += (t-last-1)/k;
    }

    cout<<res<<endl;

    return 0;

}
