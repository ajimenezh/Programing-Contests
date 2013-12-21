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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    bool good = 0;
    int p = -1;
    int a,b,c,d;
    int s1,s2;
    for (int i=0; i<4; i++) {
        cin>>a>>b>>c>>d;

        if (good) continue;

        int t1 = min(a,b);
        int t2 = min(c,d);

        if (t1+t2>n) continue;
        else {
            good = 1;
            p = i+1;
            s1 = t1;
            s2 = n-t1;
            if (s2<t2) {
                s2 = t2;
                s1 = n-t2;
            }
        }
    }

    if (!good) cout<<-1<<endl;
    else cout<<p<<" "<<s1<<" "<<s2<<endl;

    return 0;

}
