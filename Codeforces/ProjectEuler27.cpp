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

set<int> all;

bool prime(int a) {
    for (int i=2; i*i<=a; i++) if (a%i==0) return false;
    return true;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    for (int i=2; i<1000000; i++) if (prime(i)) all.insert(i);
    //for (set<int>::iterator it = all.begin(); it!=all.end(); it++) cout<<(*it)<<endl;

    int now = 0;
    int best = 0;
    int x,y;
    for (int a=-999; a<1000; a++) {
        for (int b=-999; b<1000; b++) {
            int t = 0;
            while (all.find(t*t + a*t + b)!=all.end()) t++;
            if (now<t) {
                now = t;
                best = a*b;
                x = a; y = b;
            }
            else if (now == t && best<a*b) {
                best = a*b;
                x = a;
                y = b;
            }
        }
    }

    cout<<best<<" "<<now<<" "<<x<<" "<<y<<endl;

    return 0;

}
