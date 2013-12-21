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


int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    int n,m,i,j,a,b;
    cin>>n>>m>>i>>j>>a>>b;

    int k = 100000000;

    int x,y;

    x = i-1;
    y = j-1;
    if (x%a==0 && y%b==0) {
        if (x/a==y/b) k = min(k, x/a);
        else {
            x /= a;
            y /= b;
            if (x>y && (x-y)%2==0 && m>b)  k = min(k, x);
            if (x<y && (y-x)%2==0 && n>a)  k = min(k, y);
        }
    }
    x = i-1;
    y = m-j;
    if (x%a==0 && y%b==0) {
        if (x/a==y/b) k = min(k, x/a);
        else {
            x /= a;
            y /= b;
            if (x>y && (x-y)%2==0 && m>b)  k = min(k, x);
            if (x<y && (y-x)%2==0 && n>a)  k = min(k, y);
        }
    }
    x = n-i;
    y = j-1;
    if (x%a==0 && y%b==0) {
        if (x/a==y/b) k = min(k, x/a);
        else {
            x /= a;
            y /= b;
            if (x>y && (x-y)%2==0 && m>b)  k = min(k, x);
            if (x<y && (y-x)%2==0 && n>a)  k = min(k, y);
        }
    }
    x = n-i;
    y = m-j;
    if (x%a==0 && y%b==0) {
        if (x/a==y/b) k = min(k, x/a);
        else {
            x /= a;
            y /= b;
            if (x>y && (x-y)%2==0 && m>b)  k = min(k, x);
            if (x<y && (y-x)%2==0 && n>a)  k = min(k, y);
        }
    }

    if (k==100000000) cout<< "Poor Inna and pony!"<<endl;
    else cout<<k<<endl;

    return 0;

}
