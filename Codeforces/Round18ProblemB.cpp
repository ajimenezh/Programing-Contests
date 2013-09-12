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

int n,d,m,l;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>n>>d>>m>>l;

    long long pos = 0;
    for (int i=0; i<n; i++) {
        long long in = (long long)i*(long long)m;
        if (pos<in) {
            break;
        }
        long long fn = in + (long long)l;

        if (pos>fn) continue;

        //cout<<pos<<" "<<in<<" "<<fn<<endl;

        pos = fn - (fn - pos)%(long long)d;

        pos = pos + (long long)d;
    }

    cout<<pos<<endl;

    return 0;

}
