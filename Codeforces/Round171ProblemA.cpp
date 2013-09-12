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



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int x,y;
    cin>>x>>y;

    if (x==0 && y==0) {
        cout<<0<<endl;
        return 0;
    }
    if (x==1 && y==0) {
        cout<<0<<endl;
        return 0;
    }

    if (x>0 && y<=x && y>-x+1) {
        cout<<1+4*(x-1);
    }
    else if (y>0 && y>x && y>=-x) {
        cout<<2+4*(y-1);
    }
    else if (x<0 && y>=x && y<-x) {
        cout<<3+4*(-x-1);
    }
    else {
        cout<<4+4*(-y-1);
    }

    return 0;

}
