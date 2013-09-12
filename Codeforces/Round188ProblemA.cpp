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

long long x,y,m;

void swap(long long &a, long long &b) {
    long long tmp = a;
    a = b;
    b = tmp;
}

int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>x>>y>>m;

    if (x<y) swap(x,y);

    long long k = 0;

    if (x<=0) {
        if (x>=m) cout<<0<<endl;
        else cout<<-1<<endl;
    }
    else {
        if (x>=m) {
            cout<<0<<endl;
            return 0;
        }
        if (y<0) {
            k += -(y/x);
            y += x*(-y/x);
            if (y<0) {
                k++;
                y += x;
            }
        }
        while (x<m && y<m) {
            //cout<<x<<" "<<y<<endl;
            if (x>=m-y) {
                k++;
                break;
            }
            y = x+y;
            if (x<y) swap(x,y);
            k++;
        }
        cout<<k<<endl;
    }

    return 0;

}
