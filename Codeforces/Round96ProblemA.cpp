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

int reverse(int a) {
    int p = 0;
    for (int i=0; i<8; i++) {
        if ((1<<i)&a) p += 1<<(8-1-i);
    }
    return p;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    string s;
    getline(cin,s);

    for (int i=0; i<s.length(); i++) {
        if (i==0) {
            int t = s[i];
            t = reverse(t);
            cout<<-t+256<<"\n";
        }
        else {
            int t = s[i];
            t = reverse(t);
            cout<<(reverse(int(s[i-1]))-t+256)%256<<"\n";
        }
    }

    return 0;

}
