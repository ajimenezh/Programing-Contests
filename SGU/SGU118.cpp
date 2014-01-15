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


int v[1001];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int k;
    cin>>k;
    while (k--) {
        int n;
        cin>>n;
        for (int i=0; i<n; i++) cin>>v[i];
        int t = 0;

        for (int i=0; i<n; i++) {
            int c = 1;
            for (int j=0; j<n-i; j++) {
                c = (c*(v[j]%9))%9;
            }
            t += c%9;
        }
        t = (t + 9  - 1)%9;
        cout<<t+1<<endl;
    }

    return 0;

}
