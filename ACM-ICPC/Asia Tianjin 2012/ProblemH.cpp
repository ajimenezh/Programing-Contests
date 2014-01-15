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

int x,y;
double p,q;

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int tt;
    cin>>tt;
    while (tt--) {
        cin>>x>>y>>p>>q;

        double tiger = (double)q*(p*x+p*y) + (double)(1-q)*x;
        double wolf = (double)(1-q)*(p*x+p*y) + (double)q*y;

        if (tiger>wolf) {
            cout<<"tiger ";
            printf("%.4f\n",tiger);
        }
        else {
            cout<<"wolf ";
            printf("%.4f\n",wolf);
        }
    }


    return 0;

}
