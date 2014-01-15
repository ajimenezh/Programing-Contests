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

set<int> all;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long cur = 1;
    long long sum = 6;
    while (cur<=1000000000) {
        all.insert(cur);
        cur += sum;
        sum += 6;
    }
    int n;
    while (cin>>n && n!=-1) {
        if (all.find(n)==all.end()) {
            cout<<"N\n";
        }
        else cout<<"Y\n";
    }

    return 0;

}
