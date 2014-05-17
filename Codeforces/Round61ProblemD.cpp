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

bool isprime(int a) {
    for (int i=2; i*i<=a; i++) if (a%i==0) return false;
    return true;
}

int b[55];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n;
    cin>>n;
    int k = 2 + (n-2);

    if (n==2) cout<<-1<<endl;
    else {
        vector<int> p;
        int t = 2;
        while (p.size()<k) {
            if (isprime(t)) p.push_back(t);
            t++;
        }

        for (int i=0; i<n; i++) b[i] = 1;
        b[0] = p[0]*p[1];
        for (int i=1; i<n-1; i++) b[i] = p[0]*p[2];
        b[n-1] = p[1]*p[2];
        for (int i=2; i<n-1; i++) b[i] *= p[i+1];

        for (int i=0; i<n; i++) cout<<b[i]<<"\n";
    }

    return 0;

}
