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

int a,b,n;



int main() {

    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

    cin>>a>>b>>n;

    int t = -1;

    for (int i=0; i<10; i++) {
        if ((a*10+i)%b==0) {
            t = a*10 + i;
            n--;
            break;
        }
    }

    if (t==-1) {cout<<-1; return 0;}

    cout<<t;
    for (int i=0; i<n; i++) cout<<0;


    return 0;

}
