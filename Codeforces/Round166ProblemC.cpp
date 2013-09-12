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

int n,k;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>k;

    if (n/k <= 2 || k==1) {
        cout<<-1;
    }
    else {
        for (int i=0; i<k; i++) {
            cout<<(i+1)<<" "<<(i+1)<<" ";
        }
        for (int i=0; i<k; i++) {
            cout<<(i+1)<<" ";
        }
        for (int i=0; i<(n-3*k); i++) {
            cout<<1<<" ";
        }
    }

    return 0;

}
