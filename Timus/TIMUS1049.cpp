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

int c[10010];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    long long n = 1;
    for (int i=0; i<10; i++) {
        int a;
        cin>>a;
        for (int i=2; i*i<=a; i++) if (a%i==0) {
            while (a%i==0) {c[i]++; a /= i;}
        }
        if (a!=1) c[a]++;
    }

    long long res = 1;

    for (int i=0; i<10010; i++) res *= (long long)(c[i]+1);

    cout<<res%10<<endl;

    return 0;

}
