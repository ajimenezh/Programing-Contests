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

int a,b,c,d,e,f;
long long k[3];

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>c>>d>>e>>f;

    k[0] = 10000000;

    if (b==0 || d==0 || f==0) {
        cout<<"Hermione"<<endl;
        return 0;
    }
    if (a==0 || c==0 || e==0) {
        cout<<"Ron"<<endl;
        return 0;
    }
    for (int i=0; i<3; i++) {
        long long tmp = (k[0]/a);
        k[0] -= tmp*a;
        k[1] += tmp*b;
        tmp = (k[1]/c);
        k[1] -= tmp*c;
        k[2] += tmp*d;
        tmp = (k[2]/e);
        k[2] -= tmp*e;
        k[0] += tmp*f;
        if (k[0]>10000000) break;
    }
    if (k[0]>10000000) cout<<"Ron";
    else cout<<"Hermione"<<endl;

    return 0;

}
