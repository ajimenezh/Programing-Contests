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

bool check(int a, int b, int c) {
    set<int> d;
    while (a>0) {if (d.find(a%10)!=d.end()) return 0; d.insert(a%10); a /= 10;}
    while (b>0) {if (d.find(b%10)!=d.end()) return 0; d.insert(b%10); b /= 10;}
    while (c>0) {if (d.find(c%10)!=d.end()) return 0; d.insert(c%10); c /= 10;}
    return d.size()==9 && d.find(0)==d.end();
}

bool check1(int a) {
    set<int> d;
    int t = 0;
    while (a>0) {if (d.find(a%10)!=d.end()) return 0; d.insert(a%10); a /= 10;t++;}
    return t==d.size() && d.find(0)==d.end();
}


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int sum = 0;

    for (int i=1; i<10000; i++) if (check1(i)) {
        for (int j=1; j*j<i; j++) if (i%j==0 && check1(j)) {
            if (check(i/j,j,i)) {
                cout<<i<<" "<<j<<" "<<i/j<<" "<<sum<<endl;
                sum += i;
                break;
            }
        }
    }

    cout<<sum<<endl;

    return 0;

}
